#pragma once
#ifndef BEAN_ENV_NATIVE_ARRAY_ARRAYNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_ARRAY_ARRAYNEWEXECUTOR_H
#include <memory>
#include "../NativeMethodExecutor.h"
using ClassSPtr = std::shared_ptr<Class>;
class ArrayNewExecutor : public NativeMethodExecutor {
public:
	ArrayNewExecutor();
	~ArrayNewExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ARRAY_ARRAYNEWEXECUTOR_H
