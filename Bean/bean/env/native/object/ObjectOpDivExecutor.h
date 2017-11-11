#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTOPDIVEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTOPDIVEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpDivExecutor : public NativeMethodExecutor {
public:
	ObjectOpDivExecutor();
	~ObjectOpDivExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTOPDIVEXECUTOR_H


