#pragma once
#ifndef BEAN_AST_VISITOR_ASTINCLUDEVISITOR_H
#define BEAN_AST_VISITOR_ASTINCLUDEVISITOR_H
#include <iostream>
#include "ASTFilteredVisitor.h"
#include "../../env/ClassLoader.h"
/**
 * クラスを読み込むために使用されるビジターです.
 * ClassLoaderから呼び出されます。
 */
class ASTIncludeVisitor : public ASTFilteredVisitor {
public:
	ASTIncludeVisitor(std::string package, ClassLoaderSPtr parent);
	~ASTIncludeVisitor();

	void enter(std::shared_ptr<ASTNode > element) override;
	void enter(std::shared_ptr<ASTAliasStatement > element) override;
	void enter(std::shared_ptr<ASTIncludeStatement > element) override;
	void enter(std::shared_ptr<ASTClassDeclaration > element) override;
	void enter(std::shared_ptr<ASTEnumDeclaration> element) override;
	void enter(std::shared_ptr<ASTFieldDeclaration > element) override;
	void enter(std::shared_ptr<ASTMethodDeclaration > element) override;

	void exit(std::shared_ptr<ASTClassDeclaration > element) override;
	
	/**
	 * パッケージ名を返します.
	 * @return
	 */
	std::string getPackage();
private:
	int loadCount;
	ClassLoaderSPtr parent;
	std::string package;
};
#endif // !BEAN_AST_VISITOR_ASTINCLUDEVISITOR_H


