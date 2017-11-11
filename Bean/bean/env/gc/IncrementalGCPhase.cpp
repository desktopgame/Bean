#pragma once
#ifndef BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
#define BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
/**
 * インクリメンタルGCにおいて、現在どの段階であるかを表します.
 */
enum class IncrementalGCPhase {
	RootScan,
	Mark,
	MarkFix,
	Sweep,
};
#endif // !BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
