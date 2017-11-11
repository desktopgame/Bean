#pragma once
#ifndef BEAN_ENV_GC_INCREMENTALGCSTRATEGY_H
#define BEAN_ENV_GC_INCREMENTALGCSTRATEGY_H
#include "GCStrategy.h"
#include "IncrementalGCPhase.cpp"
#include "IncrementalMarker.h"
/**
 * ƒCƒ“ƒNƒŠƒƒ“ƒ^ƒ‹GC‚ÌÀ‘•.
 */
class IncrementalGCStrategy : public GCStrategy {
public:
	IncrementalGCStrategy();
	~IncrementalGCStrategy();

	// GCStrategy ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	void handleNew(Object_* obj) override;
	void handleWriteBarrier(Object_* obj) override;
	void miniGC(Heap * const heap) override;
	void fullGC(Heap * const heap) override;
private:
	void rootScan(Heap* const heap);
	void mark(Heap* const heap);
	void markFix(Heap* const heap);
	void sweep(Heap* const heap);
	IncrementalGCPhase phase;
	std::vector<IncrementalMarkerSPtr> markers;
	std::vector<IncrementalMarkerSPtr> backBuffer;
	std::vector<Object_*> objects;
	bool fullGCNow;

	float magMarks;
	float magSweeps;
	int minMarks;
	int minSweeps;
	int limitFullSweeps;
};
#endif // !BEAN_ENV_GC_INCREMENTALGCSTRATEGY_H
