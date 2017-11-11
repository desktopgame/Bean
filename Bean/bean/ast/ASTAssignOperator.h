#pragma once
#ifndef BEAN_AST_ASTASSIGNOPERATOR_H
#define BEAN_AST_ASTASSIGNOPERATOR_H
#include "ASTBinaryOperator.h"
class ASTName;
class ASTFactor;
class ASTPointer;

class ASTAssignOperator;
using ASTAssignOperatorSPtr = std::shared_ptr<ASTAssignOperator>;
using ASTAssignOperatorWPtr = std::weak_ptr<ASTAssignOperator>;
/**
 * = ���Z�q.
 */
class ASTAssignOperator : public ASTBinaryOperator {
public:
	ASTAssignOperator();
	virtual ~ASTAssignOperator();
	/**
	 * �����̕ϐ��̖��O��ݒ肵�܂�.
	 * @param pointer
	 */
	void setPointer(std::shared_ptr<ASTPointer> pointer);
	/**
	 * �����̕ϐ��̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTPointer> getPointer() const;

	/**
	 * ��������l��ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ��������l��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	virtual std::string format() const override;
	// ASTOperator ����Čp������܂���
	virtual Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTAssignOperator)
private:
	std::shared_ptr<ASTPointer> pointer;
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTASSIGNOPERATOR_H


