#pragma once
#ifndef BEAN_AST_CODESYNTAXEXCEPTION_H
#define BEAN_AST_CODESYNTAXEXCEPTION_H
#include <stdexcept>
//NOTE:使用されていません。
/**
 * ASTの構築中に見つかったエラーをラップします.
 */
class CodeSyntaxException : public std::logic_error {
public:
	CodeSyntaxException(std::string msg);
	~CodeSyntaxException();
	/**
	 * この例外をスローします.
	 * @param msg
	 */
	static void throw_(std::string msg);

	/**
	 * 再スローします.
	 * @param e
	 */
	static void re_throw(CodeSyntaxException e);
};

#endif // !BEAN_AST_CODESYNTAXEXCEPTION_H

