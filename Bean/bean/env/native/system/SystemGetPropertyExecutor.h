#pragma once
#ifndef BEAN_ENV_NATIVE_SYSTEMGETPROPERTYEXECUTOR_H
#define BEAN_ENV_NATIVE_SYSTEMGETPROPERTYEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class SystemGetPropertyExecutor : public TypedNativeMethodExecutor {
public:
	SystemGetPropertyExecutor();
	~SystemGetPropertyExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_SYSTEMGETPROPERTYEXECUTOR_H
