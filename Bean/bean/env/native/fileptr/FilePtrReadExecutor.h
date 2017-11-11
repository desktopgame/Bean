#pragma once
#ifndef BEAN_ENV_NATIVE_FILEPTR_FILEPTRREADEXECUTOR_H
#define BEAN_ENV_NATIVE_FILEPTR_FILEPTRREADEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FilePtrReadExecutor : public TypedNativeMethodExecutor {
public:
	FilePtrReadExecutor();
	~FilePtrReadExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILEPTR_FILEPTRREADEXECUTOR_H
