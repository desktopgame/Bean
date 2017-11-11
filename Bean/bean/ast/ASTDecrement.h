#pragma once
#ifndef BEAN_AST_ASTDECREMENT_H
#define BEAN_AST_ASTDECREMENT_H
#include "ASTScheduledFactor.h";
/**
 * --‰‰ŽZŽq.
 */
class ASTDecrement : public ASTScheduledFactor {
public:
	ASTDecrement();
	~ASTDecrement();

	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTDecrement)
protected:
	Object_ * lazy(Object_ * target, Object_ * one) override;
	void edit(Object_* src);
};
#endif // !BEAN_AST_ASTDECREMENT_H


