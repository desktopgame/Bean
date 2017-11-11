#pragma once
#ifndef BEAN_ENV_NATIVEMETHOD_H
#define BEAN_ENV_NATIVEMETHOD_H
#include <memory>
#include "Method.h"
class Class;
class NativeMethodExecutor;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * C++�Ŏ��s�����R�[�h�ł�.
 */
class NativeMethod : public Method {
public:
	/**
	 * @param classz
	 * @param modifier 
	 * @param name
	 * @param package
	 */
	NativeMethod(ClassSPtr classz, Modifier modifier, std::string name, std::string package);
	~NativeMethod();
	/**
	 * ���W�X�g���ɓo�^����Ȃ����@�ł��̃��\�b�h�̈Ϗ����ݒ肵�܂�.
	 * @param executor
	 * @return
	 */
	NativeMethod* singular(NativeMethodExecutor* executor);

	// Method ����Čp������܂���
	Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
private:
	NativeMethodExecutor* getDelegate();
	bool isSingular;
	std::string package;
	NativeMethodExecutor* delgate;
};
#endif // !BEAN_ENV_NATIVEMETHOD_H


