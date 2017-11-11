#pragma once
#ifndef BEAN_AST_ASTFORSTATEMENT_H
#define BEAN_AST_ASTFORSTATEMENT_H
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * for��.
 */
class ASTForStatement : public ASTNode {
public:
	ASTForStatement();
	~ASTForStatement();

	/**
	 * ����������ݒ肵�܂�.
	 * @param initialize
	 */
	void setInitialize(std::shared_ptr<ASTNode> initialize);

	/**
	 * ����������Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTNode> getInitialize() const;

	/**
	 * ��������ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ��������Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	/**
	 * �X�V����ݒ肵�܂�.
	 * @param update
	 */
	void setUpdate(std::shared_ptr<ASTNode> update);

	/**
	 * �X�V����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTNode> getUpdate() const;

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
	DECL_MAKE_SHARED_0_H(ASTForStatement)
private:
	std::shared_ptr<ASTNode> initialize;
	std::shared_ptr<ASTFactor> factor;
	std::shared_ptr<ASTNode> update;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTFORSTATEMENT_H


