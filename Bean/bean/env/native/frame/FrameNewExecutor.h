#pragma once
#ifndef BEAN_ENV_NATIVE_FRAME_FRAMENEWEXECUTOR_H
#define BEAN_ENV_NATIVE_FRAME_FRAMENEWEXECUTOR_H
#include <memory>
#include "../TypedNativeMethodExecutor.h"
using ClassSPtr = std::shared_ptr<Class>;
class FrameNewExecutor : public TypedNativeMethodExecutor {
public:
	FrameNewExecutor();
	~FrameNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
	static int argc;
	static char** argv;
};
#endif // !BEAN_ENV_NATIVE_FRAME_FRAMENEWEXECUTOR_H
