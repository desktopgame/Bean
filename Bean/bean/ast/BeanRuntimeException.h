#pragma once
#ifndef BEAN_AST_BEANRUNTIMEEXCEPTION_H
#define BEAN_AST_BEANRUNTIMEEXCEPTION_H
#include <stdexcept>
#include <string>
class BeanRuntimeException : public std::logic_error {
public:
	BeanRuntimeException(const std::string& err);
	BeanRuntimeException();
	~BeanRuntimeException();
};
#endif // !BEAN_AST_BEANRUNTIMEEXCEPTION_H
