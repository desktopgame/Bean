#pragma once
#ifndef BEAN_AST_ASTMODIFIER_H
#define BEAN_AST_ASTMODIFIER_H
#include "ASTNode.h"
#include "../env/Modifier.h"
/**
 * �����o�[�C���q.
 */
class ASTModifier : public ASTNode {
public:
	ASTModifier(Modifier mod);
	~ASTModifier();
	std::string format() const override;
	/**
	 * �l��Ԃ��܂�.
	 * @return
	 */
	Modifier getValue() const;
	DECL_MAKE_SHARED_1_H(ASTModifier, Modifier)
protected:
private:
	Modifier mod;
};
#endif // !BEAN_AST_ASTMODIFIER_H
