#pragma once
#ifndef BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
#define BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
/**
 * �C���N�������^��GC�ɂ����āA���݂ǂ̒i�K�ł��邩��\���܂�.
 */
enum class IncrementalGCPhase {
	RootScan,
	Mark,
	MarkFix,
	Sweep,
};
#endif // !BEAN_ENV_GC_INCREMENTALGCPHASE_CPP
