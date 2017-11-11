#pragma once
#ifndef BEAN_ENV_GC_GCLOCK_H
#define BEAN_ENV_GC_GCLOCK_H
/**
 * デストラクタが実行されるまでの間
 * ガベージコレクションが実行されないようにします.
 */
class GCLock {
public:
	GCLock();
	~GCLock();
};
#endif //! BEAN_ENV_GC_GCLOCK_H
