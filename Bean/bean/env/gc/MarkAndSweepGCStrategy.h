#pragma once
#ifndef BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
#define BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
#include "GCStrategy.h"
/**
 * マークアンドスイープ方式のGC.
 */
class MarkAndSweepGCStrategy : public GCStrategy {
public:
	MarkAndSweepGCStrategy();
	virtual ~MarkAndSweepGCStrategy();

	// GCStrategy を介して継承されました
	virtual void miniGC(Heap * const heap) override;
	virtual void fullGC(Heap * const heap) override;
protected:
	virtual void mark_items(Heap* const heap);
	virtual void sweep_items(Heap* const heap);
};
#endif // !BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
