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
 * If•¶.
 * q—v‘f‚Æ‚µ‚Äelseif, else, •¶‚ğ‚Â‚±‚Æ‚ªo—ˆ‚Ü‚·.
 */
class ASTIfStatement : public ASTIfCauseStatement {
public:
	ASTIfStatement();
	~ASTIfStatement();

	/**
	 * ğŒ‚ğ’Ç‰Á‚µ‚Ü‚·.
	 * @param elseIfStatement
	 */
	void addElseIf(std::shared_ptr<ASTElseIfStatement> elseIfStatement);

	/**
	 * ğŒ‚ğ•Ô‚µ‚Ü‚·.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTElseIfStatement> getElseIfAt(int index) const;

	/**
	 * ğŒ‚Ì”‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	int getElseIfCount() const;

	/**
	 * ğŒ‚ª–‚½‚³‚ê‚Ä‚¢‚È‚¢ê‡‚ğİ’è‚µ‚Ü‚·.
	 * @param elseStatement
	 */
	void setElse(std::shared_ptr<ASTElseStatement> elseStatement);

	/**
	 * ğŒ‚ª–‚½‚³‚ê‚Ä‚¢‚È‚¢ê‡‚ğ•Ô‚µ‚Ü‚·.
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
