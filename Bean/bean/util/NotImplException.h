#pragma once
#ifndef BEAN_UTIL_NOTIMPLEXCEPTION_H
#define BEAN_UTIL_NOTIMPLEXCEPTION_H
#include <stdexcept>
/**
 * �������̃��\�b�h����X���[������O.
 */
class NotImplException : std::logic_error {
public:
	NotImplException();
	~NotImplException();
};
#endif // !BEAN_UTIL_NOTIMPLEXCEPTION_H
