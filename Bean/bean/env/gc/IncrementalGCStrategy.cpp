#include "IncrementalGCStrategy.h"
#include <algorithm>
#include "MarkAndSweepGCStrategy.h"
#include "../CodeBlock.h"
#include "../Field.h"
#include "../Object_.h"
#include "../gc/Block.h"
#include "../../threads/Thread.h"
#include "../../env/user/UserSystem.h"

//public method---
IncrementalGCStrategy::IncrementalGCStrategy() {
	this->phase = IncrementalGCPhase::RootScan;
	this->markers = std::vector<IncrementalMarkerSPtr>();
	this->backBuffer = std::vector<IncrementalMarkerSPtr>();
	this->objects = std::vector<Object_*>();
	//プロパティの設定
	UserSystem* uSys = UserSystem::getInstance();
	this->magMarks = uSys->value<float>(UserSystem::GC_INC_MAG_MARKS, 0.3f);
	this->magSweeps = uSys->value<float>(UserSystem::GC_INC_MAG_SWEEPS, 0.3f);
	this->minMarks = uSys->value<int>(UserSystem::GC_INC_MIN_MARKS, 50);
	this->minSweeps = uSys->value<int>(UserSystem::GC_INC_MIN_SWEEPS, 50);
	this->limitFullSweeps = uSys->value<int>(UserSystem::GC_INC_LIMIT_FULL_SWEEPS, 300);
}

IncrementalGCStrategy::~IncrementalGCStrategy() {
	markers.clear();
}

void IncrementalGCStrategy::handleNew(Object_ * obj) {
	if (this->phase == IncrementalGCPhase::Mark ||
		this->phase == IncrementalGCPhase::MarkFix) {
		obj->getState()->setProgress(GCProgress::Pending);
		objects.push_back(obj);

		//auto newChild = std::make_shared<IncrementalMarker>(obj);
		//this->backBuffer.push_back(newChild);
	}
	if (this->phase == IncrementalGCPhase::Sweep) {
		obj->getState()->setProgress(GCProgress::Pending);
	}
	//obj->dump();
}

void IncrementalGCStrategy::handleWriteBarrier(Object_ * obj) {
	if (this->phase == IncrementalGCPhase::Mark ||
		this->phase == IncrementalGCPhase::MarkFix) {
		auto newChild = std::make_shared<IncrementalMarker>(obj);
		this->backBuffer.push_back(newChild);
	}
	if (this->phase == IncrementalGCPhase::Sweep) {
		obj->getState()->setProgress(GCProgress::Pending);
	}
}

void IncrementalGCStrategy::miniGC(Heap * const heap) {
	switch (this->phase) {
		case IncrementalGCPhase::RootScan:
			rootScan(heap);
			break;
		case IncrementalGCPhase::Mark:
			mark(heap);
			break;
		case IncrementalGCPhase::MarkFix:
			markFix(heap);
			break;
		case IncrementalGCPhase::Sweep:
			sweep(heap);
			break;
		default:
			break;
	}
}

void IncrementalGCStrategy::fullGC(Heap * const heap) {
	this->fullGCNow = true;
	//Heap::getInstance()->dump();
	if (phase == IncrementalGCPhase::RootScan) {
		rootScan(heap);
	}
	while (phase != IncrementalGCPhase::RootScan) {
		miniGC(heap);
	}
	this->markers.clear();
	this->fullGCNow = false;
//	MarkAndSweepGCStrategy masgcs = MarkAndSweepGCStrategy();
//	masgcs.fullGC(heap);
}

void IncrementalGCStrategy::rootScan(Heap* const heap) {
	//全てのオブジェクトを未探索状態に設定
	heap->view([](std::vector<Object_*>& items) {
		for (Object_* item : items) {
			item->getState()->setProgress(GCProgress::NotSearch);
		}
	});
	//ルートからアクセス可能なオブジェクトを
	//探索途中へ設定
	CodeBlock::paintSearchNow();
	Block::blocks_page_paintAll(GCProgress::SearchNow);
	Field::paintSearchNow();
	//探索途中のオブジェクトを起点とするリストを作成
	this->markers.clear();
	this->backBuffer.clear();
	this->objects.clear();
	auto temp = std::vector<IncrementalMarkerSPtr>();
	heap->view([&temp](std::vector<Object_*>& items) {
		for (Object_* item : items) {
			if (item->getState()->getProgress() == GCProgress::SearchNow) {
				temp.push_back(std::make_shared<IncrementalMarker>(item));
			}
		}
	});
	this->markers.swap(temp);
	this->phase = IncrementalGCPhase::Mark;
}

void IncrementalGCStrategy::mark(Heap * const heap) {
	int sum = 0;
	//現在のオブジェクト数に対する割合でマーク数を決める
	int markMax = (int)(heap->getCurrentSize() * magMarks);
	//ただしあまりに小さい場合には全てスキャン
	if (markMax < minMarks) {
		markMax = minMarks;
	}
	for (IncrementalMarkerSPtr marker : this->markers) {
		if (marker->isMarkEnd()) {
			continue;
		}
		sum += marker->markTree();
		if (sum >= markMax) break;
	}
	using Itr = std::vector<IncrementalMarkerSPtr>::iterator;
	Itr first = std::remove_if(markers.begin(), markers.end(), [](IncrementalMarkerSPtr marker) {
		return marker->isMarkEnd();
	});
	markers.erase(first, markers.end());
	if (markers.empty()) {
		this->phase = IncrementalGCPhase::MarkFix;
	}
}

void IncrementalGCStrategy::markFix(Heap * const heap) {
	for (auto buff : this->backBuffer) {
		while (!buff->isMarkEnd()) {
			buff->markTree();
		}
	}
	backBuffer.clear();
	CodeBlock::paintSearchNow();
	Block::blocks_page_paintAll(GCProgress::SearchNow);
	Field::paintSearchNow();
	this->phase = IncrementalGCPhase::Sweep;
}

void IncrementalGCStrategy::sweep(Heap * const heap) {
	int removeCount = 0;
	//現在のオブジェクト数に対する割合でスイープ数を決める
	int removeMax = (int)(heap->getCurrentSize() / magSweeps);
	//ただしあまりに小さい場合には全てスキャン
	if (removeMax < minSweeps) {
		removeMax = minSweeps;
	//大きすぎる場合にも全て削除
	} else if (heap->getCurrentSize() > limitFullSweeps) {
		removeMax = heap->getCurrentSize();
	}
	heap->view([&removeCount, removeMax](std::vector<Object_*>& items) {
		for (int i = items.size() - 1; i >= 0; i--) {
			Object_* item = items.at(i);
			auto state = item->getState();
			auto prog = state->getProgress();
			if (
				prog != GCProgress::NotSearch ||
				item->getState()->getRank() > 0 ||
				state->getStrongReferenceCount() > 0 ||
				item->isSingleton()
			) {
				item->getState()->setAge(item->getState()->getAge() + 1);
				continue;
			}
			removeCount++;
			Heap::deleteItem(item);
			items.erase(items.begin() + i);
			item->die();
			if (removeCount >= removeMax) {
				break;
			}
		}
	});
	if (removeCount == 0) {
		this->phase = IncrementalGCPhase::RootScan;
	}
}
//---public method
