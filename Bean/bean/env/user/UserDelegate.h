#pragma once
#ifndef BEAN_ENV_USER_USERDELEGATE_H
#define BEAN_ENV_USER_USERDELEGATE_H
#include <memory>
#include "../Object_.h"
class ClassLoader;
class Delegate;
#include "../../threads/Thread.h"

using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;
/**
 * �f���Q�[�g�̃��b�p�[.
 */
class UserDelegate : public Object_ {
public:
	/**
	 * @param classLoader
	 * @param d
	 */
	UserDelegate(ClassLoaderSPtr, Delegate* d);
	~UserDelegate();
	/**
	 * ���̃����_����`���ꂽ�Ƃ��̃N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	ClassLoaderSPtr getCapture() const;
	/**
	 * ������Ԃ��܂�.
	 * @return
	 */
	Delegate* const getDelegate() const;

	/**
	 * Delegate�ւ̈Ϗ��ł�.
	 * @param t
	 * @param args
	 */
	Object_* call(ThreadSPtr t, std::vector<Object_*> args);

	/**
	 * Delegate�ւ̈Ϗ��ł�.
	 * @param args
	 */
	Object_* call(std::vector<Object_*> args);

	/**
	 * ���I���\�b�h�̂��߂ɍ쐬���ꂽ�����_�Ȃ�true.
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * ���I���\�b�h�̂��߂ɍ쐬���ꂽ�����_�Ȃ�true.
	 * @return b
	 */
	bool isDynamicMethod() const;

	// Object_ ����Čp������܂���
	virtual Object_ * clone() override;
	std::vector<Object_*> getVirtualField() override;
	UserDelegate* asUserDelegate() override;
protected:
	void lazyLoading() override;
private:
	ClassLoaderSPtr classLoader;
	Delegate* d;
	bool dynamicMethod;
};
#endif // !BEAN_ENV_USER_USERDELEGATE_H


