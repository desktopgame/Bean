#pragma once
#ifndef BEAN_AST_ASTWHILESTATEMENT_H
#define BEAN_AST_ASTWHILESTATEMENT_H
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * while•¶.
 */
class ASTWhileStatement : public ASTNode {
public:
	ASTWhileStatement();
	~ASTWhileStatement();

	/**
	 * ğŒ‚ğİ’è‚µ‚Ü‚·.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ğŒ‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	/**
	 * •¶‚ğİ’è‚µ‚Ü‚·.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * •¶‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTWhileStatement)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTWHILESTATEMENT_H
