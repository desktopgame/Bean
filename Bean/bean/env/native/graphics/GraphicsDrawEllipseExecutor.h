#pragma once
#ifndef BEAN_ENV_NATIVE_GRAPHCIS_GRAPHICSDRAWELLIPSEEXECUTOR_H
#define BEAN_ENV_NATIVE_GRAPHCIS_GRAPHICSDRAWELLIPSEEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class GraphicsDrawEllipseExecutor : public TypedNativeMethodExecutor {
public:
	GraphicsDrawEllipseExecutor();
	~GraphicsDrawEllipseExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_GRAPHCIS_GRAPHICSDRAWELLIPSEEXECUTOR_H
