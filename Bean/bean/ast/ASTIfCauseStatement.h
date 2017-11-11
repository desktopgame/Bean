#pragma once
#ifndef BEAN_AST_ASTIFCAUSESTATEMENT_H
#define BEAN_AST_ASTIFCAUSESTATEMENT_H
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * if elseif の基底クラス.
 */
class ASTIfCauseStatement : public ASTNode {
public:
	ASTIfCauseStatement();
	virtual ~ASTIfCauseStatement();
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
	 * この文の条件が満たされているときに実行される文を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * この文の条件が満たされているときに実行される文を設定します.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;
private:
	std::shared_ptr<ASTBody> body;
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTIFCAUSESTATEMENT_H


