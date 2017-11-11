#pragma once
#ifndef BEAN_AST_ASTWHILESTATEMENT_H
#define BEAN_AST_ASTWHILESTATEMENT_H
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * while��.
 */
class ASTWhileStatement : public ASTNode {
public:
	ASTWhileStatement();
	~ASTWhileStatement();

	/**
	 * ������ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ������Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	/**
	 * ����ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * ����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTWhileStatement)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTWHILESTATEMENT_H
