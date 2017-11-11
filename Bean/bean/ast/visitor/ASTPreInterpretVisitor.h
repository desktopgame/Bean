#pragma once
#ifndef BEAN_AST_VISITOR_ASTPREINTERPRETNVISITOR_H
#define BEAN_AST_VISITOR_ASTPREINTERPRETNVISITOR_H
#include "ASTNullVisitor.h"
#include "../../env/ClassLoader.h"
/**
 * ���C���N���X���s���Ɏg�p�����r�W�^�[�ł�.
 * �֐��̑O���錾���\�ɂ��邽�߂Ɏg�p����܂��B
 */
class ASTPreInterpretVisitor : public ASTNullVisitor {
public:
	ASTPreInterpretVisitor(ClassLoaderSPtr rootClsLoader);
	~ASTPreInterpretVisitor();
	void enter(std::shared_ptr<ASTNode> element) override;
	void enter(std::shared_ptr<ASTClassDeclaration> element) override;
	void enter(std::shared_ptr<ASTEnumDeclaration > element) override;
	void enter(std::shared_ptr<ASTMethodDeclaration> element) override;
	void enter(std::shared_ptr<ASTForStatement> element) override;
	void enter(std::shared_ptr<ASTWhileStatement> element) override;

	void enter(std::shared_ptr<ASTBreakStatement> element) override;
	void enter(std::shared_ptr<ASTContinueStatement> element) override;
	void enter(std::shared_ptr<ASTThrow> element) override;


	void exit(std::shared_ptr<ASTForStatement> element) override;
	void exit(std::shared_ptr<ASTWhileStatement> element) override;
	void exit(std::shared_ptr<ASTClassDeclaration> element) override;
private:
	bool inClass;
	int inFor;
	int inWhile;
	ClassLoaderSPtr rootClsLoader;
};
#endif // !BEAN_AST_VISITOR_ASTPREINTERPRETNVISITOR_H
