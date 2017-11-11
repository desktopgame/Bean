#pragma once
#ifndef BEAN_ENV_WEAKREFERENCE_H
#define BEAN_ENV_WEAKREFERENCE_H
class Object_;
/**
 * �I�u�W�F�N�g�̏������Ď�����N���X.
 */
class WeakReference {
public:
	WeakReference();
	virtual ~WeakReference() = 0;
	/**
	 * �I�u�W�F�N�g���폜�����Ƃ��ɌĂяo����܂�.
	 * @parma obj
	 */
	virtual void onDelete(Object_* obj);
};
#endif // !BEAN_ENV_WEAKREFERENCE_H
