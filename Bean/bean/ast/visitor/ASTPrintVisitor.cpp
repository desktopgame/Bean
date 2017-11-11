#include "ASTPrintVisitor.h"
#include "ASTMethodVisitor.h"
#include "ASTPrintVisitorSkeleton.h"
#include "../../Debug.h"
#include "../../env/Class.h"
#include "../../env/ClassFormatException.h"
#include "../../env/CodeBlock.h"
#include "../../env/Function.h"
#include "../../env/IncludeManager.h"
#include "../../env/Method.h"
#include "../../env/String.h"
#include "../../env/gc/Block.h"

//public method---
ASTPrintVisitor::ASTPrintVisitor() {
	this->depth = 0;
}

ASTPrintVisitor::~ASTPrintVisitor() {
}

void ASTPrintVisitor::print(std::shared_ptr<ASTNode> parent) {
	if (parent == nullptr) {
		return;
	}
	std::string indent = makeIndent();
	//int so = parent->getStartOffset();
	//int eo = parent->getEndOffset();
	std::cout << indent << parent->format() << std::endl;
}

std::string ASTPrintVisitor::makeIndent() {
	std::string indent = std::string();
	for (int i = 0; i < depth; i++) {
		indent += "    ";
	}
	return indent;
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTContinueStatement> element) {
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTBreakStatement> element) {
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTEnumDeclaration> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTContinueStatement> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTBreakStatement> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTEnumDeclaration> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTFactor> element) {
}



void ASTPrintVisitor::enter(std::shared_ptr<ASTNode> element) {
	//	Debug::break_if(true);
	//print(element);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTReturnStatement> element) {
	print(element);
	depth++;
	if (element->getFactor() != nullptr) {
		element->getFactor()->visit(this);
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTThrow> element) {
	print(element);
	depth++;
	if (element->getFactor() != nullptr) {
		element->getFactor()->visit(this);
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTDynFieldDeclaration> element) {
	print(element);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTDynMethodDeclaration> element) {
	print(element);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTAliasStatement> element) {
	print(element);
	depth++;
	std::cout << makeIndent() << element->getOldName()->getCString() << std::endl;
	std::cout << makeIndent() << element->getNewName()->getCString() << std::endl;
	depth--;
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTIncludeStatement> element) {
	print(element);
	depth++;
	std::cout << makeIndent() << element->getPath()->getCString() << std::endl;
	depth--;
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTClassDeclaration> element) {
	print(element);
	depth++;
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTFieldDeclaration> element) {
	print(element);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTMethodDeclaration> element) {
	print(element);
	depth++;
	element->getBody()->visit(this);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTIfStatement> element) {
	print(element);
	element->getFactor()->visit(this);
	depth++;
	element->getBody()->visit(this);
	for (int i = 0; i < element->getElseIfCount(); i++) {
		print(element->getElseIfAt(i));
		depth++;
		element->getElseIfAt(i)->getBody()->visit(this);
		depth--;
	}
	if (element->getElse() != nullptr) {
		print(element->getElse());
		depth++;
		element->getElse()->getBody()->visit(this);
		depth--;
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTWhileStatement> element) {
	print(element);
	depth++;
	element->getBody()->visit(this);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTForStatement> element) {
	print(element);
	depth++;
	element->getInitialize()->visit(this);
	element->getFactor()->visit(this);
	element->getUpdate()->visit(this);
	depth++;
	element->getBody()->visit(this);
	depth--;
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTLambdaDeclaration> element) {
	print(element);
	depth++;
	element->getBody()->visit(this);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTVariableDeclaration> element) {
	print(element);
	depth++;
	element->getFactor()->visit(this);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTUnaryOperator> element) {
	print(element);
	depth++;
	if (element->getCondition()) {
		element->getCondition()->visit(this);
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTBinaryOperator> element) {
	print(element);
	depth++;
	if (element->getLeft()) {
		element->getLeft()->visit(this);
	}
	if (element->getRight()) {
		element->getRight()->visit(this);
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTMethodInvocation> element) {
	//	print(element);
	//	depth++;
	print(element);
	depth++;
	for (int i = 0; i < element->getArgumentCount(); i++) {
		//		print(element->getArgumentAt(i));
		element->getArgumentAt(i)->visit(this);
	}
	std::shared_ptr<ASTMethodInvocationByMessage> byMsg = element->asByMessage();
	std::shared_ptr<ASTMethodInvocationBySelf> bySelf = element->asBySelf();
	if (byMsg != nullptr) {
		byMsg->getInvoker()->visit(this);
	}
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTFactor> element) {
	print(element);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTScheduledFactor> element) {
	print(element);
	depth++;
	element->getArgument()->visit(this);
}

void ASTPrintVisitor::enter(std::shared_ptr<ASTTryStatement> element) {
	print(element);
	depth++;
	element->getBody()->visit(this);
	if (element->getCatchStatement() != nullptr) {
		print(element->getCatchStatement());
		element->getCatchStatement()->getBody()->visit(this);
	}
	std::shared_ptr<ASTBody> f = element->getFinally();
	if (f == nullptr) return;
	std::cout << makeIndent() << "finally : " << f->getStartOffset() << " " << f->getEndOffset() << std::endl;
	if (f != nullptr) {
		f->visit(this);
	}
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTNode> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTAliasStatement> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTIncludeStatement> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTReturnStatement> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTThrow> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTDynFieldDeclaration> element) {
//	print(element);
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTDynMethodDeclaration> element) {
//	print(element);
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTClassDeclaration> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTFieldDeclaration> element) {
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTMethodDeclaration> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTIfStatement> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTWhileStatement> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTForStatement> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTLambdaDeclaration> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTVariableDeclaration> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTUnaryOperator> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTBinaryOperator> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTScheduledFactor> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTMethodInvocation> element) {
	depth--;
}

void ASTPrintVisitor::exit(std::shared_ptr<ASTTryStatement> element) {
	depth--;
}
//---public method
