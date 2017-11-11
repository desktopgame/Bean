#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTOPMULEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTOPMULEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpMulExecutor : public NativeMethodExecutor {
public:
	ObjectOpMulExecutor();
	~ObjectOpMulExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTOPMULEXECUTOR_H


