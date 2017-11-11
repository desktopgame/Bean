#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWDOTEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWDOTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawDotExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawDotExecutor();
	~GraphicsDrawDotExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWDOTEXECUTOR_H
