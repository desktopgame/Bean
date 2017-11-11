#pragma once
#ifndef BEAN_AST_ASTSUPERFACTOR_H
#define BEAN_AST_ASTSUPERFACTOR_H
#include "ASTFactor.h"
/**
 * super.
 */
class ASTSuperFactor : public ASTFactor {
public:
	ASTSuperFactor();
	~ASTSuperFactor();

	Object_ * eval() override;
	ClassSPtr getBaseLine(ClassSPtr classz) override;
	DECL_MAKE_SHARED_0_H(ASTSuperFactor)
protected:
};

#endif // !BEAN_AST_ASTSUPERFACTOR_H

