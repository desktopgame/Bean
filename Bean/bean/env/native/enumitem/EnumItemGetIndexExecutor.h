#pragma once
#ifndef BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETINDEXEXECUTOR_H
#define BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETINDEXEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class EnumItemGetIndexExecutor : public TypedNativeMethodExecutor {
public:
	EnumItemGetIndexExecutor();
	~EnumItemGetIndexExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETINDEXEXECUTOR_H
