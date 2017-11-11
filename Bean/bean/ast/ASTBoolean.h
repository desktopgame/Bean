#pragma once
#ifndef BEAN_AST_ASTBOOLEAN_H
#define BEAN_AST_ASTBOOLEAN_H
#include "ASTFactor.h"
/**
 * true/false.
 */
class ASTBoolean : public ASTFactor {
public:
	ASTBoolean(bool b);
	~ASTBoolean();

	// ASTFactor ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_1_H(ASTBoolean, bool)
private:
	bool b;
};
#endif // !BEAN_AST_ASTBOOLEAN_H


