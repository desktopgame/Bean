#pragma once
#ifndef BEAN_AST_ASTTHISFACTOR_H
#define BEAN_AST_ASTTHISFACTOR_H
#include "ASTFactor.h"
/**
 * this.
 */
class ASTThisFactor : public ASTFactor {
public:
	ASTThisFactor();
	~ASTThisFactor();
	std::string format() const override;
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTThisFactor)
protected:
};
#endif // !BEAN_AST_ASTTHISFACTOR_H


