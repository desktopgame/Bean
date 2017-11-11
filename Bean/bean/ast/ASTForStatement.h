#pragma once
#ifndef BEAN_AST_ASTFORSTATEMENT_H
#define BEAN_AST_ASTFORSTATEMENT_H
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * for文.
 */
class ASTForStatement : public ASTNode {
public:
	ASTForStatement();
	~ASTForStatement();

	/**
	 * 初期化式を設定します.
	 * @param initialize
	 */
	void setInitialize(std::shared_ptr<ASTNode> initialize);

	/**
	 * 初期化式を返します.
	 * @return
	 */
	std::shared_ptr<ASTNode> getInitialize() const;

	/**
	 * 条件式を設定します.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * 条件式を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	/**
	 * 更新式を設定します.
	 * @param update
	 */
	void setUpdate(std::shared_ptr<ASTNode> update);

	/**
	 * 更新式を返します.
	 * @return
	 */
	std::shared_ptr<ASTNode> getUpdate() const;

	/**
	 * 文を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * 文を返します.
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


