#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEREADTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEREADTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileReadTextExecutor : public TypedNativeMethodExecutor {
public:
	FileReadTextExecutor();
	~FileReadTextExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEREADTEXTEXECUTOR_H
