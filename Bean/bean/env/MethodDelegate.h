#pragma once
#ifndef BEAN_ENV_METHODDELEGATE_H
#define BEAN_ENV_METHODDELEGATE_H
#include <memory>
#include "Delegate.h"
class ClassLoader;
class Method;

using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;
/**
 * ���\�b�h�Q�Ƃ��g�p�����f���Q�[�g�̎����ł�.
 */
class MethodDelegate : public Delegate {
public:
	MethodDelegate(Object_* invoker, Method* method);
	~MethodDelegate();

	// Delegate ����Čp������܂���
	virtual Object_* call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual Object_ * call(ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual int requestArgumentCount() override;
private:
	Object_* invoker;
	Method* method;
};
#endif // !BEAN_ENV_METHODDELEGATE_H


