#pragma once
#ifndef BEAN_AST_ASTBINARYOPERATOR_H
#define BEAN_AST_ASTBINARYOPERATOR_H
#include "ASTOperator.h"
class ASTNode;
/**
 * ��̈����ɑ΂��Ĉ�̌��ʂ�Ԃ��񍀉��Z�q�ł�.
 */
class ASTBinaryOperator : public ASTOperator {
public:
	ASTBinaryOperator();
	virtual ~ASTBinaryOperator() = 0;
	/**
	 * �����̈��q��ݒ肵�܂�.
	 * @param left
	 */
	void setLeft(ASTFactorSPtr left);

	/**
	 * �E���̈��q��Ԃ��܂�.
	 * @return
	 */
	ASTFactorSPtr getLeft() const;

	/**
	 * �E���̈��q��ݒ肵�܂�.
	 * @param right
	 */
	void setRight(ASTFactorSPtr right);

	/**
	 * �E���̈��q��Ԃ��܂�.
	 */
	ASTFactorSPtr getRight() const;
	
	void accept(ASTVisitor* visitor) override;
	//DECL_MAKE_SHARED_0_H(ASTBinaryOperator)
private:
	ASTFactorSPtr left;
	ASTFactorSPtr right;
};
#endif // !BEAN_AST_ASTBINARYOPERATOR_H
