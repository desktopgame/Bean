#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWLINEEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWLINEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawLineExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawLineExecutor();
	~GraphicsDrawLineExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWLINEEXECUTOR_H
