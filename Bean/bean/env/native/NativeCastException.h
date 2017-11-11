#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVECASTEXCEPTION_H
#define BEAN_ENV_NATIVE_NATIVECASTEXCEPTION_H
#include <stdexcept>
class NativeCastException : public std::logic_error {
public:
	NativeCastException(std::string msg);
	~NativeCastException();
private:
	std::string requireType;
	std::string realType;
};
#endif // !BEAN_ENV_NATIVE_NATIVECASTEXCEPTION_H
