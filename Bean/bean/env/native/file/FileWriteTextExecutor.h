#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEWRITEEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEWRITEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileWriteTextExecutor : public TypedNativeMethodExecutor {
public:
	FileWriteTextExecutor();
	~FileWriteTextExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEWRITEEXECUTOR_H
