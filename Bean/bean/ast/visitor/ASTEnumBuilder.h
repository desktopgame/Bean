#pragma once
#ifndef BEAN_AST_VISITOR_ASTENUMBUILDER_H
#define BEAN_AST_VISITOR_ASTENUMBUILDER_H
#include "ASTFilteredVisitor.h"
class ASTEnumBuilder : public ASTFilteredVisitor {
public:
	ASTEnumBuilder(std::string package, ClassSPtr classz, ClassLoaderSPtr classLoader);
	~ASTEnumBuilder();
	void enter(std::shared_ptr<ASTEnumDeclaration> element) override;
	void exit(std::shared_ptr<ASTEnumDeclaration> element) override;
private:
	std::string package;
	int index;
	ClassSPtr classz;
	ClassLoaderSPtr classLoader;
};
#endif // !BEAN_AST_VISITOR_ASTENUMBUILDER_H
