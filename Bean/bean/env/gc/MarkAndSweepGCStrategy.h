#pragma once
#ifndef BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
#define BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
#include "GCStrategy.h"
/**
 * �}�[�N�A���h�X�C�[�v������GC.
 */
class MarkAndSweepGCStrategy : public GCStrategy {
public:
	MarkAndSweepGCStrategy();
	virtual ~MarkAndSweepGCStrategy();

	// GCStrategy ����Čp������܂���
	virtual void miniGC(Heap * const heap) override;
	virtual void fullGC(Heap * const heap) override;
protected:
	virtual void mark_items(Heap* const heap);
	virtual void sweep_items(Heap* const heap);
};
#endif // !BEAN_ENV_GC_MARKANDSWEEPGCSTRATEGY_H
