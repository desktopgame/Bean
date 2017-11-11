#pragma once
#ifndef BEAN_AST_INTERPRETEXITEXCEPTION_H
#define BEAN_AST_INTERPRETEXITEXCEPTION_H
#include <stdexcept>
/**
 * 静的に検出されたエラーによってインタプリタを終了するためにスローされます.
 */
class InterpretExitException : public std::logic_error {
public:
	InterpretExitException(std::string msg);
	~InterpretExitException();
};
#endif // !BEAN_AST_INTERPRETEXITEXCEPTION_H
