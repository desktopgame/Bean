#pragma once
#ifndef BEAN_ENV_NATIVE_FILECOPYEXECUTOR_H
#define BEAN_ENV_NATIVE_FILECOPYEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class FileCopyExecutor : public TypedNativeMethodExecutor {
public:
	FileCopyExecutor();
	~FileCopyExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_FILECOPYEXECUTOR_H

