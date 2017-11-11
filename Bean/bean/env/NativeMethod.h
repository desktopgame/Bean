#pragma once
#ifndef BEAN_ENV_NATIVEMETHOD_H
#define BEAN_ENV_NATIVEMETHOD_H
#include <memory>
#include "Method.h"
class Class;
class NativeMethodExecutor;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * C++で実行されるコードです.
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
	 * レジストリに登録されない方法でこのメソッドの委譲先を設定します.
	 * @param executor
	 * @return
	 */
	NativeMethod* singular(NativeMethodExecutor* executor);

	// Method を介して継承されました
	Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
private:
	NativeMethodExecutor* getDelegate();
	bool isSingular;
	std::string package;
	NativeMethodExecutor* delgate;
};
#endif // !BEAN_ENV_NATIVEMETHOD_H


