#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWBITMAPEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWBITMAPEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawBitmapExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawBitmapExecutor();
	~GraphicsDrawBitmapExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSDRAWBITMAPEXECUTOR_H
