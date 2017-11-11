#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEMKDIREXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEMKDIREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileMkdirExecutor : public TypedNativeMethodExecutor {
public:
	FileMkdirExecutor();
	~FileMkdirExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEMKDIREXECUTOR_H
