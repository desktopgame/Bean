#include "IncrementalMarker.h"
#include <algorithm>
#include "../Field.h"
#include "../Object_.h"
#include "../../Debug.h"

//public method---
IncrementalMarker::IncrementalMarker(IncrementalMarkerSPtr parent, Object_ * root) {
	this->root = root;
	this->parent = (parent == nullptr) ? std::weak_ptr<IncrementalMarker>() : std::weak_ptr<IncrementalMarker>(parent);
	this->current = root->getClass();
	this->children = std::vector<IncrementalMarkerSPtr>();
	this->bIsMarkEnd = false;
	root->getState()->setProgress(GCProgress::SearchNow);
}

IncrementalMarker::IncrementalMarker(Object_* root) 
 : IncrementalMarker(nullptr, root) {

}

IncrementalMarker::~IncrementalMarker() {
	children.clear();
}

int IncrementalMarker::markTree() {
	
	int sum = 0;
	if (bIsMarkEnd) return 0;
	if (root->getState()->getProgress() == GCProgress::SearchComp) {
		this->bIsMarkEnd = true;
		return 0;
	}
	sum += markFields();
	if (sum >= limit()) {
		return sum;
	}
	sum += markChildren();
	if (sum >= limit()) {
		return sum;
	}
	return sum;
}

bool IncrementalMarker::isMarkEnd() {
	return this->bIsMarkEnd;
}
//---public method

//private method---
int IncrementalMarker::markFields() {
	if (current == nullptr) {
		return 0;
	}
	int count = 0;
	//Debug::break_if(root->getClass()->getName() == "Component");
	std::vector<Field*> fields = current->getFields();
	for (Field* field : fields) {
		if (field->getModifier().isStatic()) {
			continue;
		}
		Object_* fieldVal = field->getValue(root);
		//循環参照しているか検査
		if (isRecursive(fieldVal)) {
			continue;
		}
		//循環参照していないので追加
		this->children.push_back(std::make_shared<IncrementalMarker>(shared_from_this(), fieldVal));
		count++;
	}
	this->current = current->getSuper().lock();
	//全てのフィールドをマークした
	if (current == nullptr) {
		std::vector<Object_*> objects = root->getVirtualField();
		for (Object_* obj : objects) {
			if (isRecursive(obj)) {
				continue;
			}
			this->children.push_back(std::make_shared<IncrementalMarker>(shared_from_this(), obj));
			count++;
		}
	}
	return count;
}

int IncrementalMarker::markChildren() {
	if (current != nullptr) {
		return 0;
	}
	int count = 0;
	for (IncrementalMarkerSPtr child : children) {
		count += child->markTree();
		if (count >= limit()) {
			break;
		}
	}
	//既に終了したマーカを削除
	auto first = std::remove_if(children.begin(), children.end(), [](IncrementalMarkerSPtr elem) {
		return elem->isMarkEnd();
	});
	children.erase(first, children.end());
	//全てのマーカがなくなったら
	if (children.empty()) {
		this->bIsMarkEnd = true;
		root->getState()->setProgress(GCProgress::SearchComp);
	}
	return count;
}

int IncrementalMarker::limit() {
	return 10;
}

bool IncrementalMarker::isRecursive(Object_ * o) {
	bool recursive = false;
	IncrementalMarkerSPtr tmp = parent.lock();
	while (tmp) {
		if (o == tmp->root) {
			recursive = true;
			break;
		}
		tmp = tmp->parent.lock();
	}
	return recursive;
}
//---private method
