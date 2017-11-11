#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTOPSUBEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTOPSUBEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpSubExecutor : public NativeMethodExecutor {
public:
	ObjectOpSubExecutor();
	~ObjectOpSubExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTOPSUBEXECUTOR_H


