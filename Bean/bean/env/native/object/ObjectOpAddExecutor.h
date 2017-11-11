#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTOPADDEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTOPADDEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpAddExecutor : public NativeMethodExecutor {
public:
	ObjectOpAddExecutor();
	~ObjectOpAddExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTOPADDEXECUTOR_H


