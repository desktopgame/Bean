#pragma once
#ifndef BEAN_AST_ASTTHROW_H
#define BEAN_AST_ASTTHROW_H
#include "ASTNode.h"
/**
 * throw文.
 */
class ASTThrow : public ASTNode {
public:
	ASTThrow();
	~ASTThrow();
	/**
	 * この文がスローする例外への参照を設定します.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * この文がスローする例外への参照を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;
	void accept(ASTVisitor* visitor) override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTThrow)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTTHROW_H


