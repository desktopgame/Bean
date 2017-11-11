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
 * = 演算子.
 */
class ASTAssignOperator : public ASTBinaryOperator {
public:
	ASTAssignOperator();
	virtual ~ASTAssignOperator();
	/**
	 * 代入先の変数の名前を設定します.
	 * @param pointer
	 */
	void setPointer(std::shared_ptr<ASTPointer> pointer);
	/**
	 * 代入先の変数の名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTPointer> getPointer() const;

	/**
	 * 代入される値を設定します.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * 代入される値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	virtual std::string format() const override;
	// ASTOperator を介して継承されました
	virtual Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTAssignOperator)
private:
	std::shared_ptr<ASTPointer> pointer;
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTASSIGNOPERATOR_H


