#pragma once
#ifndef BEAN_ENV_NATIVE_FILE_FILEPATHSEPARATORCHAREXECUTOR_H
#define BEAN_ENV_NATIVE_FILE_FILEPATHSEPARATORCHAREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileGetPathSeparatorCharExecutor : public TypedNativeMethodExecutor {
public:
	FileGetPathSeparatorCharExecutor();
	~FileGetPathSeparatorCharExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILE_FILEPATHSEPARATORCHAREXECUTOR_H
