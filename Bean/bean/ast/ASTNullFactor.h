#pragma once
#ifndef BEAN_AST_NULLFACTOR_H
#define BEAN_AST_NULLFACTOR_H
#include "ASTFactor.h"
/**
 * null.
 */
class ASTNullFactor : public ASTFactor {
public:
	ASTNullFactor();
	~ASTNullFactor();
	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTNullFactor)
protected:
};
#endif // !BEAN_AST_NULLFACTOR_H


