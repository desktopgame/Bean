#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSCLEAREXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSCLEAREXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsClearExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsClearExecutor();
	~GraphicsClearExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHICS_GRAPHICSCLEAREXECUTOR_H
