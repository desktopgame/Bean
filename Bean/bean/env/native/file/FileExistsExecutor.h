#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEEXISTSEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEEXISTSEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileExistsExecutor : public TypedNativeMethodExecutor {
public:
	FileExistsExecutor();
	~FileExistsExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEEXISTSEXECUTOR_H
