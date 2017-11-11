#include "ASTPreInterpretVisitor.h"
#include "../InterpretExitException.h"
#include "../../ast/ASTClassDeclaration.h"
#include "../../ast/ASTEnumDeclaration.h"
#include "../../ast/ASTErrorNode.h"
#include "../../env/ClassLoader.h"
#include "../../env/Function.h"
#include "../../env/FunctionManager.h"
#include "../../env/IncludeManager.h"
#include "../../env/Package.h"

//public method---
ASTPreInterpretVisitor::ASTPreInterpretVisitor(ClassLoaderSPtr rootClsLoader) {
	this->rootClsLoader = rootClsLoader;
	this->inClass = false;
	this->inFor = 0;
	this->inWhile = 0;
}

ASTPreInterpretVisitor::~ASTPreInterpretVisitor() {
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTNode> element) {
	auto err = std::dynamic_pointer_cast<ASTErrorNode>(element);
	if (err) {
		throw InterpretExitException(err->getMessage());
	}
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTClassDeclaration > element) {
	//クラス宣言に入ったらMethodDeclは
	//トップレベルの関数と定義しない
	this->inClass = true;
	std::string s = Package::ENTRY_POINT_PACKAGE + "." + element->getName()->getCString();
	rootClsLoader->getIncludeManager()->include(s);
	auto newClsLoader = std::make_shared<ClassLoader>(rootClsLoader, element, s, true);
	newClsLoader->registerClassLoader();
	ClassLoader::loadClass(Package::ENTRY_POINT_PACKAGE, element, newClsLoader);
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTEnumDeclaration > element) {
	std::string s = Package::ENTRY_POINT_PACKAGE + "." + element->getName()->getCString();
	rootClsLoader->getIncludeManager()->include(Package::ENTRY_POINT_PACKAGE + "." + element->getName()->getCString());
	auto newClsLoader = std::make_shared<ClassLoader>(rootClsLoader, element, s, true);
	newClsLoader->registerClassLoader();
	ClassLoader::loadEnum(Package::ENTRY_POINT_PACKAGE, element, newClsLoader);
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTMethodDeclaration> element) {
	if (inClass) {
		return;
	}
	FunctionManager* fm = rootClsLoader->getFunctionManager();
	Function* f = new Function(element);
	if (!element->getModifier()->getValue().isBlank()) {
		delete f;
		throw InterpretExitException("トップレベルの関数に修飾子は付与出来ません。");
	}
	if (!fm->contains(f)) {
		rootClsLoader->getFunctionManager()->addFunction(f);
	} else {
		std::string loMsg = f->getName() + "(" + std::to_string(f->getArgumentCount()) + ") は既に定義されています";
		delete f;
		throw InterpretExitException(loMsg);
	}
}

//ループに入ったらカウントを増やします
void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTForStatement> element) {
	this->inFor++;
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile++;
}


//ループに入っていないのに　break/continue を発見したらエラー
void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTBreakStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw InterpretExitException("break はループの中にのみ配置出来ます。");
	}
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTContinueStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw InterpretExitException("continue はループの中にのみ配置出来ます。");
	}
}

void ASTPreInterpretVisitor::enter(std::shared_ptr<ASTThrow> element) {
	if (inFor == 0 && inWhile == 0) {
		throw InterpretExitException("throw はループの中にのみ配置出来ます。");
	}
}



//ループから出たらカウントを減らします
void ASTPreInterpretVisitor::exit(std::shared_ptr<ASTForStatement> element) {
	this->inFor--;
}

void ASTPreInterpretVisitor::exit(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile--;
}

void ASTPreInterpretVisitor::exit(std::shared_ptr<ASTClassDeclaration> element) {
	this->inClass = false;
}
//---public method
