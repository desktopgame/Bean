#pragma once
#ifndef BEAN_AST_ASTCONSTRUCTORDECLARATION_H
#define BEAN_AST_ASTCONSTRUCTORDECLARATION_H
#include "ASTConstructorChain.h"
#include "ASTMethodDeclaration.h"
/**
 * [...]
 * def new() { ... }
 */
class ASTConstructorDeclaration : public ASTMethodDeclaration {
public:
	ASTConstructorDeclaration();
	~ASTConstructorDeclaration();
	/**
	 * �A����ݒ肵�܂�.
	 * @param chain
	 */
	void setChain(std::shared_ptr<ASTConstructorChain> chain);

	/**
	 * �A����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTConstructorChain> getChain();
	DECL_MAKE_SHARED_0_H(ASTConstructorDeclaration)
private:
	std::shared_ptr<ASTConstructorChain> chain;
};
#endif // !BEAN_AST_ASTCONSTRUCTORDECLARATION_H
