#pragma once
#ifndef BEAN_AST_ASTRETURNSTATEMENT_H
#define BEAN_AST_ASTRETURNSTATEMENT_H
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * return文.
 */
class ASTReturnStatement : public ASTNode {
public:
	ASTReturnStatement();
	~ASTReturnStatement();

	/**
	 * このreturn文が値を返すならその式を設定します.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * このreturn文が値を返すならその式を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTReturnStatement)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTRETURNSTATEMENT_H
