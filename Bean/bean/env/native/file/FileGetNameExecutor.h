#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEGETNAMEEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEGETNAMEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileGetNameExecutor : public TypedNativeMethodExecutor {
public:
	FileGetNameExecutor();
	~FileGetNameExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEGETNAMEEXECUTOR_H
