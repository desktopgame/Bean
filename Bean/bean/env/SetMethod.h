#pragma once
#ifndef BEAN_ENV_SETMETHOD_H
#define BEAN_ENV_SETMETHOD_H
#include <memory>
#include "Method.h"
using ClassSPtr = std::shared_ptr<Class>;
/**
 * セッターとして機能するメソッド.
 */
class SetMethod : public Method {
public:
	SetMethod(ClassSPtr classz, const std::string& propertyName, const std::string& methodName);
	~SetMethod();
	Object_* const execute(Object_* const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
private:
	std::string propertyName;
	std::string methodName;
};

#endif // !BEAN_ENV_SETMETHOD_H

