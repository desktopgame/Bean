#pragma once
#ifndef BEAN_AST_ASTRETURNSTATEMENT_H
#define BEAN_AST_ASTRETURNSTATEMENT_H
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * return��.
 */
class ASTReturnStatement : public ASTNode {
public:
	ASTReturnStatement();
	~ASTReturnStatement();

	/**
	 * ����return�����l��Ԃ��Ȃ炻�̎���ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ����return�����l��Ԃ��Ȃ炻�̎���Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTReturnStatement)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTRETURNSTATEMENT_H
