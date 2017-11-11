#pragma once
#ifndef BEAN_AST_ASTELSESTATEMENT_H
#define BEAN_AST_ASTELSESTATEMENT_H
#include "ASTBody.h"
#include "ASTNode.h"
/**
 * else文.
 * 子要素として文を持つことが出来ます。
 */
class ASTElseStatement : public ASTNode {
public:
	ASTElseStatement();
	~ASTElseStatement();
	/**
	* この条件が満たされているときに実行される文を設定します.
	* @param body
	*/
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	* この条件が満たされているときに実行される文を返します.
	* @return
	*/
	std::shared_ptr<ASTBody> getBody() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTElseStatement)
private:
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTELSESTATEMENT_H
