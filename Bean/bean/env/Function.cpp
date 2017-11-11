#include "Function.h"
#include "ClassLoader.h"
#include "../ast/ASTMethodDeclaration.h"
#include "../env/CodeBlock.h"
#include "../env/Object_.h"
#include "../threads/Thread.h"
#include "../ast/visitor/ASTMethodVisitor.h"

//public method---
Function::Function(std::shared_ptr<ASTMethodDeclaration> methodDecl) {
	this->methodDecl = methodDecl;
}

Function::~Function() {
}

Object_* const Function::call(std::vector<Object_*> args) {
	ClassLoader::pushCurrentClassLoader(ClassLoader::getCurrentClassLoader());
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	CodeBlock* cdb = cll->getCodeBlock();
	//引数の作成	
	cdb->enter(false);
	for (int i = 0; i < getArgumentCount(); i++) {
		cdb->declReference(
			methodDecl->getParameterAt(i)->getName()->getCString(),
			args.at(i)
		);
	}
	//関数の実行
	Block::pushCurrent();
	ASTMethodVisitor mv = ASTMethodVisitor();
	methodDecl->getBody()->visit(&mv);
	Block::popCurrent();
	cdb->exit(true);
	//例外をスロー
	if (mv.isThrown()) {
		Thread::getCurrent()->setException(mv.getException());
	}
	ClassLoader::popCurrentClassLoader();
	return mv.getReturnValue();
}

std::string Function::getName() {
	return methodDecl->getName()->getCString();
}

int Function::getArgumentCount() {
	return methodDecl->getParameterCount();
}
//---public method
