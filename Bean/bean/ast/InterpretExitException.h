#pragma once
#ifndef BEAN_AST_INTERPRETEXITEXCEPTION_H
#define BEAN_AST_INTERPRETEXITEXCEPTION_H
#include <stdexcept>
/**
 * �ÓI�Ɍ��o���ꂽ�G���[�ɂ���ăC���^�v���^���I�����邽�߂ɃX���[����܂�.
 */
class InterpretExitException : public std::logic_error {
public:
	InterpretExitException(std::string msg);
	~InterpretExitException();
};
#endif // !BEAN_AST_INTERPRETEXITEXCEPTION_H
