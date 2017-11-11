#pragma once
#ifndef BEAN_ENV_NATIVE_OBJECT_OBJECTHASHCODEEXECUTOR_H
#define BEAN_ENV_NATIVE_OBJECT_OBJECTHASHCODEEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectHashCodeExecutor : public NativeMethodExecutor {
public:
	ObjectHashCodeExecutor();
	~ObjectHashCodeExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_OBJECT_OBJECTHASHCODEEXECUTOR_H


