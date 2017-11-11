#pragma once
#ifndef BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETVALUEEXECUTOR_H
#define BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETVALUEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class EnumItemGetValueExecutor : public TypedNativeMethodExecutor {
public:
	EnumItemGetValueExecutor();
	~EnumItemGetValueExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMGETVALUEEXECUTOR_H
