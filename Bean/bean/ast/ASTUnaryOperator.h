#pragma once
#ifndef BEAN_AST_ASTUNARYOPERATOR_H
#define BEAN_AST_ASTUNARYOPERATOR_H
#include "ASTOperator.h"
/**
 * 一つの引数に対して一つの結果を返す単項演算子です.
 */
class ASTUnaryOperator : public ASTOperator {
public:
	ASTUnaryOperator();
	/**
	 * この演算子の引数を設定します.
	 * @param condition
	 */
	void setCondition(std::shared_ptr<ASTFactor> condition);

	/**
	 * この演算子の引数を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getCondition() const;
	void accept(ASTVisitor* visitor) override;
protected:
	virtual ~ASTUnaryOperator();
private:
	std::shared_ptr<ASTFactor> condition;
};
#endif // !BEAN_AST_ASTUNARYOPERATOR_H


