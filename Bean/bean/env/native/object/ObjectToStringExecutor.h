#pragma once
#ifndef BEAN_ENV_NATIVE_OBJECT_OBJECTTOSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_OBJECT_OBJECTTOSTRINGEXECUTOR_H
#include <string>
#include "../NativeMethodExecutor.h"
#include "../../Class.h"
#include "../../Object_.h"
#include "../../String.h"
class ObjectToStringExecutor : public NativeMethodExecutor {
public:
	ObjectToStringExecutor();
	~ObjectToStringExecutor();

	// NativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_OBJECT_OBJECTTOSTRINGEXECUTOR_H


