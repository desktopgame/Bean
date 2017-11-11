#pragma once
#ifndef BEAN_ENV_GC_HEAPMUTEXLOCK_H
#define BEAN_ENV_GC_HEAPMUTEXLOCK_H
/**
 * デストラクタが実行されるまでの間
 * 他のスレッドがGCを実行中なら待機します.
 */
class HeapMutexLock {
public:
	HeapMutexLock();
	~HeapMutexLock();
};
#endif // !BEAN_ENV_GC_HEAPMUTEXLOCK_H
