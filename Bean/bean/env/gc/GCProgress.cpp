#pragma once
#ifndef BEAN_ENV_GC_GCPROGRESS_CPP
#define BEAN_ENV_GC_GCPROGRESS_CPP
#include <iostream>
/**
 * インクリメンタルで使用されます.
 */
enum class GCProgress {
	/**
	 * 未探索.
	 */
	NotSearch,

	/**
	 * 探索中.
	 */
	SearchNow,

	/**
	 * 探索完了.
	 */
	SearchComp,

	/**
	 * 保留.
	 */
	Pending,
};
#endif // !BEAN_ENV_GC_GCPROGRESS_CPP
