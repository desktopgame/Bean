#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILECREATENEWFILEEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILECREATENEWFILEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileCreateNewFileExecutor : public TypedNativeMethodExecutor {
public:
	FileCreateNewFileExecutor();
	~FileCreateNewFileExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILECREATENEWFILEEXECUTOR_H
