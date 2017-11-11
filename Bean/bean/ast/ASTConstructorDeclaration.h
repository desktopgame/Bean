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
	 * òAçΩÇê›íËÇµÇ‹Ç∑.
	 * @param chain
	 */
	void setChain(std::shared_ptr<ASTConstructorChain> chain);

	/**
	 * òAçΩÇï‘ÇµÇ‹Ç∑.
	 * @return
	 */
	std::shared_ptr<ASTConstructorChain> getChain();
	DECL_MAKE_SHARED_0_H(ASTConstructorDeclaration)
private:
	std::shared_ptr<ASTConstructorChain> chain;
};
#endif // !BEAN_AST_ASTCONSTRUCTORDECLARATION_H
