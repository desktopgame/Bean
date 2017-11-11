#pragma once
#ifndef BEAN_AST_CODESYNTAXEXCEPTION_H
#define BEAN_AST_CODESYNTAXEXCEPTION_H
#include <stdexcept>
//NOTE:�g�p����Ă��܂���B
/**
 * AST�̍\�z���Ɍ��������G���[�����b�v���܂�.
 */
class CodeSyntaxException : public std::logic_error {
public:
	CodeSyntaxException(std::string msg);
	~CodeSyntaxException();
	/**
	 * ���̗�O���X���[���܂�.
	 * @param msg
	 */
	static void throw_(std::string msg);

	/**
	 * �ăX���[���܂�.
	 * @param e
	 */
	static void re_throw(CodeSyntaxException e);
};

#endif // !BEAN_AST_CODESYNTAXEXCEPTION_H

