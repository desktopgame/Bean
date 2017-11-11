#pragma once
#ifndef BEAN_NATIVE_OBJECT_OBJECTEQUALSEXECUTOR_H
#define BEAN_NATIVE_OBJECT_OBJECTEQUALSEXECUTOR_H
#include "../NativeMethodExecutor.h"
class ObjectOpEqualsExecutor : public NativeMethodExecutor {
public:
	ObjectOpEqualsExecutor();
	~ObjectOpEqualsExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_NATIVE_OBJECT_OBJECTEQUALSEXECUTOR_H


