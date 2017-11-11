#pragma once
#ifndef BEAN_AST_ASTRETURNSTATEMENT_H
#define BEAN_AST_ASTRETURNSTATEMENT_H
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * return•¶.
 */
class ASTReturnStatement : public ASTNode {
public:
	ASTReturnStatement();
	~ASTReturnStatement();

	/**
	 * ‚±‚Ìreturn•¶‚ª’l‚ğ•Ô‚·‚È‚ç‚»‚Ì®‚ğİ’è‚µ‚Ü‚·.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ‚±‚Ìreturn•¶‚ª’l‚ğ•Ô‚·‚È‚ç‚»‚Ì®‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTReturnStatement)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTRETURNSTATEMENT_H
