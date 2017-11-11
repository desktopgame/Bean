#pragma once
#ifndef BEAN_ENV_NATIVE_LABEL_LABELNEWEXECUTOR_H
#define BEAN_ENV_NATIVE_LABEL_LABELNEWEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class LabelNewExecutor : public TypedNativeMethodExecutor {
public:
	LabelNewExecutor();
	~LabelNewExecutor();

	// TypedNativeMethodExecutor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_LABEL_LABELNEWEXECUTOR_H
