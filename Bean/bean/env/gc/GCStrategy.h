#pragma once
#ifndef BEAN_ENV_GC_GCSTRATEGY_H
#define BEAN_ENV_GC_GCSTRATEGY_H
#include "Heap.h"
/**
 * Heapに蓄積されたメモリーをどのように掃除するかを定義するインターフェイスです.
 *
 * ObjectStateはGCのためのプロパティを公開しますが、
 * GCStrategyの実装によっては使用されません。
 * 例えばIncrementalGC以外ではGCProgressは使用されません。
 */
class GCStrategy {
public:
	GCStrategy();
	virtual ~GCStrategy() = 0;
	/**
	 * 新たな参照が生成されると呼ばれます.
	 * @param item
	 */
	virtual void handleNew(Object_* const item);

	/**
	 * ライトバリアによってオブジェクトが修正されると呼ばれます.
	 * @param item
	 */
	virtual void handleWriteBarrier(Object_* const item);

	/**
	 * ガベージコレクションを実行します.
	 * @param heap
	 */
	virtual void miniGC(Heap* const heap) = 0;

	/**
	 * ガベージコレクションを実行します.
	 * @param heap
	 */
	virtual void fullGC(Heap* const heap) = 0;
};
#endif // !BEAN_ENV_GC_GCSTRATEGY_H
