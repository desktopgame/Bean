#include "MarkAndSweepGCStrategy.h"
#include <iostream>
#include "../Class.h"
#include "../CodeBlock.h"
#include "../Field.h"
#include "../Object_.h"
#include "../gc/Block.h"

//public method---
MarkAndSweepGCStrategy::MarkAndSweepGCStrategy() {
}

MarkAndSweepGCStrategy::~MarkAndSweepGCStrategy() {
}

void MarkAndSweepGCStrategy::miniGC(Heap * const heap) {
	mark_items(heap);
	sweep_items(heap);
}

void MarkAndSweepGCStrategy::fullGC(Heap * const heap) {
	miniGC(heap);
}
//---public method

//protected method---
void MarkAndSweepGCStrategy::mark_items(Heap * const heap) {
	//全てのマークを解除
	heap->view([](std::vector<Object_*>& items) {
		for (Object_* item : items) {
			item->getState()->setMarked(false);
		}
	});
	//ルートからアクセス可能な要素をマーク
	CodeBlock::mark_items();
	Field::markStatics();
	Block::blocks_page_markAll();
}

void MarkAndSweepGCStrategy::sweep_items(Heap * const heap) {
	heap->view([](std::vector<Object_*>& items) {
		for (int i = items.size() - 1; i >= 0; i--) {
			Object_* item = items.at(i);
			if (item->getState()->isMarked() ||
				item->isSingleton() ||
				item->getState()->getRank() > 0 ||
				item->getState()->getStrongReferenceCount() > 0
			) {
				item->getState()->setAge(item->getState()->getAge() + 1);
				continue;
			}
			Heap::deleteItem(item);
			items.erase(items.begin() + i);
			item->die();
		}
	});
}
//---protected method
