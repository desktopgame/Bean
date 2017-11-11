#pragma once
#ifndef BEAN_ENV_NATIVE_COLOR_COLORNEWAEXECUTOR_H
#define BEAN_ENV_NATIVE_COLOR_COLORNEWAEXECUTOR_H
#include <memory>
#include "../TypedNativeMethodExecutor.h"
using ClassSPtr = std::shared_ptr<Class>;
class ColorNewAExecutor : public TypedNativeMethodExecutor {
public:
	ColorNewAExecutor();
	~ColorNewAExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_COLOR_COLORNEWAEXECUTOR_H
