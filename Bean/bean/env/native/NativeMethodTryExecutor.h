#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
#define BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
#include "NativeMethodExecutor.h"
/**
 * C++ Ç≈î≠ê∂ÇµÇΩ std::exception Ç ïﬂë®ÇµÇƒ BeanÇÃó·äOÇ≈çƒëóÇµÇ‹Ç∑ÅB
 */
class NativeMethodTryExecutor : public NativeMethodExecutor {
public:
	NativeMethodTryExecutor(NativeMethodExecutor* nmproxy);
	~NativeMethodTryExecutor();

	// NativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
private:
	NativeMethodExecutor* nmproxy;
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODTRYEXECUTOR_H
