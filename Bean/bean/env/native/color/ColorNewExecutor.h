#pragma once
#ifndef BEAN_ENV_NATIVE_COLOR_COLORNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_COLOR_COLORNEWEXECUTOR_H
#include <memory>
#include "../TypedNativeMethodExecutor.h"
using ClassSPtr = std::shared_ptr<Class>;
class ColorNewExecutor : public TypedNativeMethodExecutor {
public:
	ColorNewExecutor();
	~ColorNewExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COLOR_COLORNEWEXECUTOR_H
