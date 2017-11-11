#pragma once
#ifndef BEAN_ENV_DELEGATEMETHOD_H
#define BEAN_ENV_DELEGATEMETHOD_H
#include "Method.h"
class UserDelegate;
class DelegateMethod : public Method {
public:
	DelegateMethod(Object_* inv, const std::string& name, UserDelegate* ud);
	~DelegateMethod();

	// Method ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
private:
	UserDelegate* ud;
};
#endif // !BEAN_ENV_DELEGATEMETHOD_H
