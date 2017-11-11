#pragma once
#ifndef BEAN_ENV_NATIVE_FILEPTR_FILEPTRCLOSEEXECUTOR_H
#define BEAN_ENV_NATIVE_FILEPTR_FILEPTRCLOSEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FilePtrCloseExecutor : public TypedNativeMethodExecutor {
public:
	FilePtrCloseExecutor();
	~FilePtrCloseExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILEPTR_FILEPTRCLOSEEXECUTOR_H
