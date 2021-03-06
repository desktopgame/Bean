#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEGETPARENTEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEGETPARENTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileGetParentExecutor : public TypedNativeMethodExecutor {
public:
	FileGetParentExecutor();
	~FileGetParentExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEGETPARENTEXECUTOR_H

