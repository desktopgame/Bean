#pragma once
#ifndef BEAN_AST_ASTINCREMENT_H
#define BEAN_AST_ASTINCREMENT_H
#include "ASTScheduledFactor.h"
/**
 * ++‰‰ŽZŽq.
 */
class ASTIncrement : public ASTScheduledFactor {
public:
	ASTIncrement();
	~ASTIncrement();

	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTIncrement)
protected:
	Object_ * lazy(Object_ * target, Object_ * one) override;
	void edit(Object_* src);
private:
};
#endif // !BEAN_AST_ASTINCREMENT_H
