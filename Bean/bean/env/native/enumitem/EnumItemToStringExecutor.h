#pragma once
#ifndef BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMTOSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMTOSTRINGEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class EnumItemToStringExecutor : public TypedNativeMethodExecutor {
public:
	EnumItemToStringExecutor(std::string name);
	~EnumItemToStringExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
private:
	std::string name;
};
#endif // !BEAN_ENV_NATIVE_ENUMITEM_ENUMITEMTOSTRINGEXECUTOR_H
