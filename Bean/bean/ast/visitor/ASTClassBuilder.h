#pragma once
#ifndef BEAN_AST_ASTCLASSBUILDER_H
#define BEAN_AST_ASTCLASSBUILDER_H
#include <string>
#include "ASTFilteredVisitor.h"
class ASTIncludeVisitor;
/**
 * ÉNÉâÉXÇç\ízÇ∑ÇÈé¿ëïÇ≈Ç∑.
 */
class ASTClassBuilder : public ASTFilteredVisitor {
public:
	ASTClassBuilder(std::string package, ClassSPtr classz, ClassLoaderSPtr classLoader);
	~ASTClassBuilder();

	void enter(std::shared_ptr<ASTFieldDeclaration> element) override;
	void enter(std::shared_ptr<ASTMethodDeclaration> element) override;
	void enter(std::shared_ptr<ASTForStatement> element) override;
	void enter(std::shared_ptr<ASTWhileStatement> element) override;

	void enter(std::shared_ptr<ASTBreakStatement> element) override;
	void enter(std::shared_ptr<ASTContinueStatement> element) override;

	void exit(std::shared_ptr<ASTWhileStatement> element) override;
	void exit(std::shared_ptr<ASTForStatement> element) override;
protected:
	void enterUnknown(std::shared_ptr<ASTNode> element) override;
private:
	int inFor;
	int inWhile;
	std::string package;
	ClassSPtr classz;
	ClassLoaderSPtr classLoader;
	ASTIncludeVisitor* parent;
};
#endif // !BEAN_AST_ASTCLASSBUILDER_H
