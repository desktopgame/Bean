#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWSTRINGEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWSTRINGEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawStringExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawStringExecutor();
	~GraphicsDrawStringExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWSTRINGEXECUTOR_H