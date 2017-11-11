#pragma once
#ifndef BEAN_ENV_DELEGATE_H
#define BEAN_ENV_DELEGATE_H
#include <vector>
class Object_;
class ClassLoader;
#include "ClassLoaderSkeleton.h"
#include "../threads/Thread.h"
/**
 * �����֐��̎����ł�.
 */
class Delegate {
public:
	Delegate();
	virtual ~Delegate() = 0;
	/**
	 * �֐����w��̃X���b�h�Ŏ��s���܂�.
	 * @param t
	 * @param cll
	 * @param args
	 */
	virtual Object_* call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) = 0;

	/**
	 * �֐������̃f���Q�[�g����`���ꂽ�X�R�[�v�Ŏ��s���܂�.
	 * @param cll
	 * @param args
	 * @return
	 */
	virtual Object_* call(ClassLoaderSPtr cll, std::vector<Object_*> args) = 0;

	/**
	 * ���̃����_���v����������̐���Ԃ��܂�.
	 * @return
	 */
	virtual int requestArgumentCount() = 0;

	/**
	 * ���z�t�B�[���h��Ԃ��܂�.
	 * @return
	 */
	virtual std::vector<Object_*> getVirtualField(ClassLoaderSPtr cll);

	/**
	 * ���I���\�b�h�̂��߂̃f���Q�[�g�Ȃ�true.
	 * �����_�ɂ���č쐬���ꂽ�ꍇ�̂�true�ł��B
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * ���I���\�b�h�̂��߂̃f���Q�[�g�Ȃ�true.
	 * �����_�ɂ���č쐬���ꂽ�ꍇ�̂�true�ł��B
	 * @param b
	 */
	bool isDynamicMethod();
private:
	bool dynamicMethod;
};
#endif // !BEAN_ENV_DELEGATE_H


