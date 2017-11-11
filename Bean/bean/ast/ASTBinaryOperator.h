#pragma once
#ifndef BEAN_AST_ASTBINARYOPERATOR_H
#define BEAN_AST_ASTBINARYOPERATOR_H
#include "ASTOperator.h"
class ASTNode;
/**
 * 二つの引数に対して一つの結果を返す二項演算子です.
 */
class ASTBinaryOperator : public ASTOperator {
public:
	ASTBinaryOperator();
	virtual ~ASTBinaryOperator() = 0;
	/**
	 * 左側の因子を設定します.
	 * @param left
	 */
	void setLeft(ASTFactorSPtr left);

	/**
	 * 右側の因子を返します.
	 * @return
	 */
	ASTFactorSPtr getLeft() const;

	/**
	 * 右側の因子を設定します.
	 * @param right
	 */
	void setRight(ASTFactorSPtr right);

	/**
	 * 右側の因子を返します.
	 */
	ASTFactorSPtr getRight() const;
	
	void accept(ASTVisitor* visitor) override;
	//DECL_MAKE_SHARED_0_H(ASTBinaryOperator)
private:
	ASTFactorSPtr left;
	ASTFactorSPtr right;
};
#endif // !BEAN_AST_ASTBINARYOPERATOR_H
