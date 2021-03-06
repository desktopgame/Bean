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
 * If文.
 * 子要素としてelseif, else, 文を持つことが出来ます.
 */
class ASTIfStatement : public ASTIfCauseStatement {
public:
	ASTIfStatement();
	~ASTIfStatement();

	/**
	 * 条件を追加します.
	 * @param elseIfStatement
	 */
	void addElseIf(std::shared_ptr<ASTElseIfStatement> elseIfStatement);

	/**
	 * 条件を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTElseIfStatement> getElseIfAt(int index) const;

	/**
	 * 条件の数を返します.
	 * @return
	 */
	int getElseIfCount() const;

	/**
	 * 条件が満たされていない場合を設定します.
	 * @param elseStatement
	 */
	void setElse(std::shared_ptr<ASTElseStatement> elseStatement);

	/**
	 * 条件が満たされていない場合を返します.
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
