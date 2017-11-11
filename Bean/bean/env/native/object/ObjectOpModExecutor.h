#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTOPMODEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTOPMODEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpModExecutor : public NativeMethodExecutor {
public:
	ObjectOpModExecutor();
	~ObjectOpModExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTOPMODEXECUTOR_H


