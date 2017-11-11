#pragma once
#ifndef BEAN_AST_ASTTRYSTATEMENT_H
#define BEAN_AST_ASTTRYSTATEMENT_H
#include "ASTCatchStatement.h"
#include "ASTNode.h"
/**
 * try { ... } catch () { ... } finally {  } 構文.
 */
class ASTTryStatement : public ASTNode {
public:
	ASTTryStatement();
	~ASTTryStatement();
	/**
	 * 処理の本文を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * 処理の本文を返します.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * 例外を捕捉したときの実行処理の本文を設定します.
	 * @param catchStatement
	 */
	void setCatchStatement(std::shared_ptr<ASTCatchStatement> catchStatement);

	/**
	 * 例外を捕捉したときの実行処理の本文を返します.
	 * @return
	 */
	std::shared_ptr<ASTCatchStatement> getCatchStatement() const;

	/**
	 * 必ず処理される本文を設定します.
	 * @param body
	 */
	void setFinally(std::shared_ptr<ASTBody> finallyBlock);

	/**
	 * 必ず処理される本文を返します.
	 * @return
	 */
	std::shared_ptr<ASTBody> getFinally() const;

	void accept(ASTVisitor* visitor) override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTTryStatement)
protected:
private:
	std::shared_ptr<ASTCatchStatement> catchStatement;
	std::shared_ptr<ASTBody> finallyBlock;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTTRYSTATEMENT_H


