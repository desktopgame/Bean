#pragma once
#ifndef BEAN_ENV_GC_HEAPMUTEXLOCK_H
#define BEAN_ENV_GC_HEAPMUTEXLOCK_H
/**
 * �f�X�g���N�^�����s�����܂ł̊�
 * ���̃X���b�h��GC�����s���Ȃ�ҋ@���܂�.
 */
class HeapMutexLock {
public:
	HeapMutexLock();
	~HeapMutexLock();
};
#endif // !BEAN_ENV_GC_HEAPMUTEXLOCK_H
