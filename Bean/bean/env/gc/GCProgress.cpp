#pragma once
#ifndef BEAN_ENV_GC_GCPROGRESS_CPP
#define BEAN_ENV_GC_GCPROGRESS_CPP
#include <iostream>
/**
 * �C���N�������^���Ŏg�p����܂�.
 */
enum class GCProgress {
	/**
	 * ���T��.
	 */
	NotSearch,

	/**
	 * �T����.
	 */
	SearchNow,

	/**
	 * �T������.
	 */
	SearchComp,

	/**
	 * �ۗ�.
	 */
	Pending,
};
#endif // !BEAN_ENV_GC_GCPROGRESS_CPP
