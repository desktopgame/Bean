#pragma once
#ifndef BEAN_ENV_NATIVE_LABEL_LABELSETTEXTEXECUTOR_H
#define BEAN_ENV_NATIVE_LABEL_LABELSETTEXTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LabelSetTextExecutor : public TypedNativeMethodExecutor {
public:
	LabelSetTextExecutor();
	~LabelSetTextExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LABEL_LABELSETTEXTEXECUTOR_H
