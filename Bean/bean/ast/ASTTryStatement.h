#pragma once
#ifndef BEAN_AST_ASTTRYSTATEMENT_H
#define BEAN_AST_ASTTRYSTATEMENT_H
#include "ASTCatchStatement.h"
#include "ASTNode.h"
/**
 * try { ... } catch () { ... } finally {  } �\��.
 */
class ASTTryStatement : public ASTNode {
public:
	ASTTryStatement();
	~ASTTryStatement();
	/**
	 * �����̖{����ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * �����̖{����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * ��O��ߑ������Ƃ��̎��s�����̖{����ݒ肵�܂�.
	 * @param catchStatement
	 */
	void setCatchStatement(std::shared_ptr<ASTCatchStatement> catchStatement);

	/**
	 * ��O��ߑ������Ƃ��̎��s�����̖{����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTCatchStatement> getCatchStatement() const;

	/**
	 * �K�����������{����ݒ肵�܂�.
	 * @param body
	 */
	void setFinally(std::shared_ptr<ASTBody> finallyBlock);

	/**
	 * �K�����������{����Ԃ��܂�.
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


