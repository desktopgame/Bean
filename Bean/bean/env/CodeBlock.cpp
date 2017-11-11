#include "CodeBlock.h"
#include <algorithm>
#include <iostream>
#include "Class.h"
#include "Method.h"
#include "Null.h"
#include "Object_.h"
#include "Object_.h"
#include "String.h"
#include "gc/Block.h"
#include "gc/Heap.h"
#include "../util/STL.h"

std::vector<CodeBlock*> CodeBlock::rootBlockVec = std::vector<CodeBlock*>();

//public method---
CodeBlock::CodeBlock() {
	init(nullptr, 0, false);
	CodeBlock::rootBlockVec.push_back(this);
}

CodeBlock::~CodeBlock() {
	destroy();
	//ルート一覧から消去
	rootBlockVec.erase(
		std::remove(rootBlockVec.begin(), rootBlockVec.end(), this),
		rootBlockVec.end()
	);
}

void CodeBlock::paintSearchNow() {
	forEach([](CodeBlock* cb) {
		std::vector<Object_*> runtimeVec = cb->getRuntime();
		for (Object_* obj : runtimeVec) {
			obj->getState()->setProgress(GCProgress::SearchNow);
		}
	});
}

void CodeBlock::mark_items() {
	forEach([](CodeBlock* cb) {
		std::vector<Object_*> runtimeVec = cb->getRuntime();
		for (int j = runtimeVec.size() - 1; j >= 0; j--) {
			Object_* elem = runtimeVec.at(j);
			runtimeVec.erase(runtimeVec.begin() + j);
			elem->markTree();
		}
	});
}

void CodeBlock::sweep_item(Object_ * ref) {
	forEach([ref](CodeBlock* cb) {
		cb->remove(ref);
	});
}

void CodeBlock::forEach(std::function<void(CodeBlock*)> f) {
	for (int i = 0; i < rootBlockVec.size(); i++) {
		CodeBlock* block = rootBlockVec.at(i);
		if (block->isCallStack()) {
			continue;
		}
		f(block);
	}
}

CodeBlock * CodeBlock::clone(bool syncData) {
	return cloneImpl(this, new CodeBlock(), syncData);
}

//method for edit of symbol-table
Object_* CodeBlock::removeReference(const std::string& name) {
	if (hasDelegateTarget()) {
		return getDelegateTarget()->removeReference(name);
	}
	Object_* ret = readReference(name);
	pri__map_erase(name);
	return ret;
}

void CodeBlock::clearReference() {
	pri__map_clear();
}

void CodeBlock::declReference(const std::string& name, Object_* ref) {
	if (hasDelegateTarget()) {
		getDelegateTarget()->declReference(name, ref);
		return;
	}
	declReference(name, ref, !getClosure());
}

void CodeBlock::writeReference(const std::string & name, Object_ * ref) {
	if (hasDelegateTarget()) {
		getDelegateTarget()->writeReference(name, ref);
		return;
	}
	writeReferenceImpl(name, ref);
}

Object_* CodeBlock::readReference(const std::string& name) {
	if (hasDelegateTarget()) {
		return getDelegateTarget()->readReference(name);
	}
	return readReference(name, !getClosure());
}

Object_ * CodeBlock::readCurrentScope(const std::string& name) {
	if (hasDelegateTarget()) {
		return getDelegateTarget()->readReference(name, false);
	}
	return readReference(name, false);
}

void CodeBlock::enter(bool isClosure) {
	isClosure = true;
	if (hasDelegateTarget()) {
		getDelegateTarget()->enter(isClosure);
		return;
	}
	this->addres++;
	CodeBlock* child = new CodeBlock(this, this->getDepth() + 1, isClosure);
	childrenVector.push_back(child);
}

void CodeBlock::exit(bool isGC) {
	if (hasDelegateTarget()) {
		getDelegateTarget()->exit(isGC);
		return;
	}
	CodeBlock* parent = getParent();
	//親スコープがある
	if (parent != nullptr) {
		if (isGC) {
			//親のリストから自身を削除
			parent->childrenVector.erase(parent->childrenVector.begin() + parent->addres);
			parent->addres--;
			delete this;
			return;
		}
		parent->addres--;
	}
}

void CodeBlock::remove(Object_ * ref) {
	removeImpl(getRoot(), ref);
}

std::vector<std::string> CodeBlock::getVariableName() {
	if (hasDelegateTarget()) {
		return getDelegateTarget()->getVariableName();
	}
	std::vector<std::string> clone = std::vector < std::string>();
	for (int i = 0; i < pri__list_size(); i++) {
		clone.push_back(pri__list_at(i));
	}
	return clone;
}

std::vector<Object_*> CodeBlock::getRuntime() {
	if (hasDelegateTarget()) {
		//return getDelegateTarget()->getRuntime();
	}
	std::vector<Object_*> ret = std::vector<Object_*>();
	getRuntimeImpl(getRoot(), &ret);
	return ret;
}

bool CodeBlock::isCallStack() const {
	return source != nullptr;
}

void CodeBlock::dump() {
	dumpImpl(this, 0);
}

//public property
int CodeBlock::getDepth() const {
	return this->depth;
}

int CodeBlock::getCount() const {
	return this->childrenVector.size();
}

bool CodeBlock::getClosure() const {
	return this->isClosure;
}

CodeBlock* CodeBlock::getRoot() {
	return getDepth() == 0 ? this : getParent()->getRoot();
}

CodeBlock* CodeBlock::getParent() const {
	return this->parent;
}

CodeBlock* CodeBlock::getPointer() {
	return hasDelegateTarget() ? getDelegateTarget()->getPointer() : this;
}

CodeBlock* CodeBlock::getElementAt(int index) const {
	return this->childrenVector.at(index);
}
//---public method


//private method---
CodeBlock::CodeBlock(CodeBlock* parent, int depth, bool isClosure) {
	init(parent, depth, isClosure);
}

void CodeBlock::init(CodeBlock* parent, int depth, bool isClosure) {
	this->parent = parent;
	this->addres = -1;
	this->depth = depth;
	this->isClosure = isClosure;
	this->map = std::unordered_map< std::string, Object_*>();
	this->variableVector = std::vector<std::string>();
	this->childrenVector = std::vector<CodeBlock*>();
}

void CodeBlock::destroy() {
	//根から優先的にdelete
	STL::removeAll<CodeBlock*>(childrenVector, [](CodeBlock* child) { delete child; });
	if (source != nullptr) {
		return;
	}
	STL::removeAll<std::string>(variableVector, [this](std::string elem) { map.erase(elem); });
	this->map.clear();
	this->childrenVector.clear();
	this->variableVector.clear();
}

Object_* CodeBlock::readCurrentReference(const std::string& name, bool isClosure) {
	int o_addres = this->addres;
	Object_* ret = readReference(name, isClosure);
	this->addres = o_addres;
	return ret;
}

void CodeBlock::declReference(const std::string& name, Object_* ref, bool isClosure) {
	if (pri__map_contains(name)) {
		Object_* oldRef = pri__map_read(name);
		pri__map_erase(name);
	}
	pri__map_decl(name, ref);
}

void CodeBlock::writeReferenceImpl(const std::string & name, Object_ * ref) {
	//既に同名の変数が書き込まれているコードブロックを検索
	CodeBlock* target = this;
	CodeBlock* save = this;
	do {
		if (target->map.count(name) != 0) {
			break;
		}
		save = target;
		target = target->parent;
	} while (target != nullptr);
	if (target == nullptr) {
		target = this;
	}
	target->pri__map_decl_impl(name, ref);
}

Object_* CodeBlock::readReference(const std::string& name, bool isClosure) {
	//このスコープに定義されていなければ親スコープを参照
	bool contains = pri__map_contains(name);
	Object_* elem = contains ? pri__map_read(name) : nullptr;
	//	BinarySearchTree<string, Object_> elem = variableTree.Search(name);
	if (elem == nullptr) {
		CodeBlock* root = this->parent;
		while (root) {
			elem = root->readCurrentReference(name, false);
			if (elem != nullptr) {
				break;
			}
			root = root->parent;
		}
	}
	return elem;
}

bool CodeBlock::hasDelegateTarget() {
	return this->addres > -1;
}

CodeBlock* CodeBlock::getDelegateTarget() {
//	std::lock_guard<std::recursive_mutex> lock(thread_sync);
	CodeBlock* top = this;
	while (top->hasDelegateTarget()) {
		top = top->childrenVector.at(top->addres);
	}
	return top;
//	return this->childrenVector.at(addres);
}

void CodeBlock::getRuntimeImpl(CodeBlock * root, std::vector<Object_*>* ret) {
	for (int i = 0; i < root->pri__list_size(); i++) {
		std::string varName = root->pri__list_at(i);
		//FIXME:たまになる
		if (varName.empty()) continue;
		Object_* ref = root->pri__map_read(varName);
		ret->push_back(ref);
	}
	for (int i = 0; i < root->childrenVector.size(); i++) {
		getRuntimeImpl(root->childrenVector.at(i), ret);
	}
}

void CodeBlock::removeImpl(CodeBlock * root, Object_ * ref) {
	root->pri__map_each([root, ref](std::string key, Object_* val) {
		if (val != ref) {
			return false;
		}
		root->pri__map_erase(key);
		bool found = false;
		for (int i = 0; i < root->pri__list_size(); i++) {
			std::string varName = root->pri__list_at(i);
			if (varName == key) {
				found = true;
				root->pri__list_erase(i);
				break;
			}
		}
	});
	for (int i = 0; i < root->childrenVector.size(); i++) {
		removeImpl(root->childrenVector.at(i), ref);
	}
}

CodeBlock * CodeBlock::cloneImpl(CodeBlock * srcRoot, CodeBlock* dstRoot, bool syncData) {
	for (int i = 0; i < srcRoot->getCount(); i++) {
		CodeBlock* child = new CodeBlock(dstRoot, dstRoot->getDepth() + 1, false);
		cloneImpl(
			srcRoot->getElementAt(i),
			child,
			syncData
		);
		dstRoot->childrenVector.push_back(child);
	}
	dstRoot->addres = srcRoot->addres;
	if (syncData) {
		dstRoot->source = srcRoot;
	} else {
		dstRoot->map = srcRoot->map;
		dstRoot->variableVector = srcRoot->variableVector;
	}
	return dstRoot;
}

void CodeBlock::dumpImpl(CodeBlock* root, int depth) {
	std::string padL = std::string();
	for (int i = 0; i < depth; i++) {
		padL.push_back(' ');
	}
	std::cout << "---" << root->getDepth() << "---" << std::endl;
	for (int i = 0; i < root->pri__list_size(); i++) {
		std::string name = root->pri__list_at(i);
		//toStringメソッドを呼び出す
		Object_* elem = root->pri__map_read(name);
		if (elem == NULL) {
			continue;
		}
		Method* toStrMethod = elem->getClass()->findMethod("toString", 0, false);
		std::vector<Object_*> emptyVector = std::vector<Object_*>();
		Object_* retVal = toStrMethod->execute(elem, emptyVector);
		String* toStrVal = retVal->asString();
		std::string addName = *toStrVal->getCString();
		if (elem != nullptr) {
			//	addName += " RefCount=" + std::to_string(ref->getCount());
		}
		std::cout << padL << name << " " << addName << std::endl;
	}
	std::cout << "---" << root->getDepth() << "---" << std::endl;
	for (int i = 0; i<root->childrenVector.size(); i++) {
		dumpImpl(root->childrenVector.at(i), depth + 1);
	}
}
//---private method


//private sys method---
void CodeBlock::pri__map_decl(const std::string& name, Object_ * ref) {
	pri__map_decl_impl(name, ref);
	if (isClosure) {
		CodeBlock* root = this->parent;
		while (root) {
			if (root->pri__map_read(name)) {
				root->pri__map_decl_impl(name, ref);
			} else {
				break;
			}
			root = root->parent;
		}
	}
}

void CodeBlock::pri__map_decl_impl(const std::string & name, Object_ * ref) {
	if (source != nullptr) {
		source->pri__map_decl_impl(name, ref);
		return;
	}
	//コードブロックを介して参照可能になったので
	//ライトバリアを張る
	Heap::getInstance()->writeBarrier(ref);
	//既に記録されている値があるなら破棄する
	if (map.count(name) != 0) {
		Object_* oldVal = map[name];
	}
	//マップへ記録
	if (map.count(name) == 0) {
		variableVector.push_back(name);
	}
	map.insert_or_assign(name, ref);
}

Object_ * CodeBlock::pri__map_read(const std::string& name) {
	if (source != nullptr) {
		return source->pri__map_read(name);
	}
	if (map.count(name) == 0) {
		return nullptr;
	}
	return map.at(name);
}

void CodeBlock::pri__map_clear() {
	if (source != nullptr) {
		source->pri__map_clear();
		return;
	}
	map.clear();
	variableVector.clear();
}

void CodeBlock::pri__map_erase(const std::string& name) {
	if (source != nullptr) {
		source->pri__map_erase(name);
		return;
	}
	Object_* ref = map[name];
	map.erase(name);
	variableVector.erase(
		std::remove(variableVector.begin(), variableVector.end(), name),
		variableVector.end()
	);
}

void CodeBlock::pri__map_each(std::function<bool(const std::string&, Object_*)> f) {
	if (source != nullptr) {
		source->pri__map_each(f);
		return;
	}
	using MapIterator = std::unordered_map < std::string, Object_*>::iterator;
	for (MapIterator it = map.begin(); it != map.end(); it++) {
		std::string name = it->first;
		Object_* val = it->second;
		if(f(name, val)) break;
	}
}

bool CodeBlock::pri__map_contains(const std::string& name) {
	if (source != nullptr) {
		return source->pri__map_contains(name);
	}
	return map.count(name) == 1;
}

std::string CodeBlock::pri__list_at(int index) {
	if (source != nullptr) {
		return source->pri__list_at(index);
	}
	return variableVector.at(index);
}

void CodeBlock::pri__list_erase(int index) {
	if (source != nullptr) {
		source->pri__list_erase(index);
		return;
	}
	variableVector.erase(variableVector.begin() + index);
}

int CodeBlock::pri__list_size() {
	if (source != nullptr) {
		return source->pri__list_size();
	}
	return variableVector.size();
}
//---private sys method
