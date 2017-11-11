#pragma once
#ifndef BEAN_AST_ASTIFSTATEMENT_H
#define BEAN_AST_ASTIFSTATEMENT_H
#include "ASTIfCauseStatement.h"
class ASTNode;
class ASTBody;
class ASTFactor;
class ASTElseIfStatement;
class ASTElseStatement;
/**
 * If��.
 * �q�v�f�Ƃ���elseif, else, ���������Ƃ��o���܂�.
 */
class ASTIfStatement : public ASTIfCauseStatement {
public:
	ASTIfStatement();
	~ASTIfStatement();

	/**
	 * ������ǉ����܂�.
	 * @param elseIfStatement
	 */
	void addElseIf(std::shared_ptr<ASTElseIfStatement> elseIfStatement);

	/**
	 * ������Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTElseIfStatement> getElseIfAt(int index) const;

	/**
	 * �����̐���Ԃ��܂�.
	 * @return
	 */
	int getElseIfCount() const;

	/**
	 * ��������������Ă��Ȃ��ꍇ��ݒ肵�܂�.
	 * @param elseStatement
	 */
	void setElse(std::shared_ptr<ASTElseStatement> elseStatement);

	/**
	 * ��������������Ă��Ȃ��ꍇ��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTElseStatement> getElse() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTIfStatement)
private:
	std::vector<std::shared_ptr<ASTElseIfStatement>> elseIfStatements;
	std::shared_ptr<ASTElseStatement> elseStatement;
};
#endif // !BEAN_AST_ASTIFSTATEMENT_H
