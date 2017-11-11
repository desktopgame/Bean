#pragma once
#ifndef BEAN_AST_ASTUNARYOPERATOR_H
#define BEAN_AST_ASTUNARYOPERATOR_H
#include "ASTOperator.h"
/**
 * ��̈����ɑ΂��Ĉ�̌��ʂ�Ԃ��P�����Z�q�ł�.
 */
class ASTUnaryOperator : public ASTOperator {
public:
	ASTUnaryOperator();
	/**
	 * ���̉��Z�q�̈�����ݒ肵�܂�.
	 * @param condition
	 */
	void setCondition(std::shared_ptr<ASTFactor> condition);

	/**
	 * ���̉��Z�q�̈�����Ԃ��܂�.
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


