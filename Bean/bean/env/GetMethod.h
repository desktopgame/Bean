#pragma once
#ifndef BEAN_ENV_GETMETHOD_H
#define BEAN_ENV_GETMETHOD_H
#include <memory>
#include "Method.h"
using ClassSPtr = std::shared_ptr<Class>;
/**
 * ゲッターとして機能するメソッド.
 */
class GetMethod : public Method {
public:
	GetMethod(ClassSPtr classz, const std::string& propertyName, const std::string& methodName);
	~GetMethod();
	Object_* const execute(Object_* const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
private:
	std::string propertyName;
	std::string methodName;
};
#endif // !BEAN_ENV_GETMETHOD_H
