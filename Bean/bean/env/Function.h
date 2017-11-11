#pragma once
#ifndef BEAN_ENV_FUNCTION_H
#define BEAN_ENV_FUNCTION_H
#include <vector>
class Object_;
//class ASTMethodDeclaration;
#include "../ast/ASTMethodDeclaration.h"
/**
 * トップレベルに定義される関数です.
 */
class Function {
public:
	Function(std::shared_ptr<ASTMethodDeclaration> methodDecl);
	~Function();

	/**
	 * この関数を実行します.
	 * @param args
	 */
	Object_* const call(std::vector<Object_*> args);

	/**
	 * 名前を返します.
	 * @return
	 */
	std::string getName();

	/**
	 * 引数の数を返します.
	 * @return
	 */
	int getArgumentCount();
private:
	std::shared_ptr<ASTMethodDeclaration> methodDecl;
};
#endif // !BEAN_ENV_FUNCTION_H


