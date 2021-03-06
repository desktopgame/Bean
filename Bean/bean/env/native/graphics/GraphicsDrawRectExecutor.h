#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWRECTEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWRECTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawRectExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawRectExecutor();
	~GraphicsDrawRectExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWRECTEXECUTOR_H
