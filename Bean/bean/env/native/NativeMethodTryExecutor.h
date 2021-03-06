#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
#define BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
#include "NativeMethodExecutor.h"
/**
 * C++ で発生した std::exception を 捕捉して Beanの例外で再送します。
 */
class NativeMethodTryExecutor : public NativeMethodExecutor {
public:
	NativeMethodTryExecutor(NativeMethodExecutor* nmproxy);
	~NativeMethodTryExecutor();

	// NativeMethodExecutor を介して継承されました
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
private:
	NativeMethodExecutor* nmproxy;
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
