#include "ASTInterpretVisitor.h"
#include <functional>
#include <iostream>
#include "ASTMethodVisitor.h"
#include "../ASTBinaryOperator.h"
#include "../ASTBreakStatement.h"
#include "../ASTClassDeclaration.h"
#include "../ASTContinueStatement.h"
#include "../ASTElseIfStatement.h"
#include "../ASTElseStatement.h"
#include "../ASTFactor.h"
#include "../ASTFieldDeclaration.h"
#include "../ASTForStatement.h"
#include "../ASTIfStatement.h"
#include "../ASTIncludeStatement.h"
#include "../ASTMethodDeclaration.h"
#include "../ASTMethodInvocation.h"
#include "../ASTMethodInvocationByMessage.h"
#include "../ASTMethodInvocationBySelf.h"
#include "../ASTModifier.h"
#include "../ASTName.h"
#include "../ASTNewStatement.h"
#include "../ASTReturnStatement.h"
#include "../ASTThrow.h"
#include "../ASTTryStatement.h"
#include "../ASTVariableDeclaration.h"
#include "../ASTWhileStatement.h"
#include "../BeanRuntimeException.h"
#include "../InterpretExitException.h"
#include "../../env/Class.h"
#include "../../env/ClassFormatException.h"
#include "../../env/CodeBlock.h"
#include "../../env/Function.h"
#include "../../env/IncludeManager.h"
#include "../../env/MessageQueue.h"
#include "../../env/Method.h"
#include "../../env/Package.h"
#include "../../env/String.h"
#include "../../threads/Thread.h"
#include "../../env/gc/Block.h"
#include "../../env/gc/GCLock.h"

//public method---
ASTInterpretVisitor::ASTInterpretVisitor(ClassLoaderSPtr rootClassLoader) {
	this->rootClassLoader = rootClassLoader;
	this->exifOfintrrupt = false;
	//エントリポイントで定義されたクラスを参照するためにインクルード
	rootClassLoader->getIncludeManager()->include(Package::ENTRY_POINT_PACKAGE);
	Thread::getCurrent()->setExceptionListener([this](Thread* t, Object_* e) { onException(t, e); });
}

ASTInterpretVisitor::~ASTInterpretVisitor() {
//	rootClassLoader->getCodeBlock()->dump();
	rootClassLoader->getCodeBlock()->exit(!false);
	ThreadSPtr th = Thread::getCurrentOrSystem();
	if (th) {
		th->setExceptionListener([](Thread* t, Object_* e) {});
	}
}

void ASTInterpretVisitor::error() {
	this->exifOfintrrupt = true;
}

void ASTInterpretVisitor::clear() {
	this->exifOfintrrupt = false;
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTAliasStatement > element) {
	if (exit()) return;
	auto oldname = element->getOldName()->getCString();
	auto newname = element->getNewName()->getCString();
	rootClassLoader->getIncludeManager()->checkAlias(oldname, newname);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTIncludeStatement > element) {
	if (exit()) return;
	try {
		rootClassLoader->loadClass(element->getPath()->getCString());
	} catch (ClassFormatException e) {
		throw InterpretExitException(e.what());
	}
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTIfStatement > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTDynFieldDeclaration > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTDynMethodDeclaration > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTWhileStatement > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTForStatement > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTVariableDeclaration > element) {
	if (exit()) return;
	GCLock gcLock = GCLock();
	std::string name = element->getName()->getCString();
	Object_* refSrc = element->getFactor()->eval();
	Object_* ref = refSrc;
	this->rootClassLoader
		->getCodeBlock()
		->declReference(element->getName()->getCString(), ref);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTBinaryOperator > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTMethodInvocation > element) {
	if (exit()) return;
	std::shared_ptr<ASTMethodInvocationBySelf> bySelf = std::dynamic_pointer_cast<ASTMethodInvocationBySelf>(element);
	std::shared_ptr<ASTMethodInvocationByMessage> byMsg = std::dynamic_pointer_cast<ASTMethodInvocationByMessage>(element);
	if (bySelf != nullptr) {
		bySelf->eval();
	} else {
		byMsg->eval();
	}
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTTryStatement > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

void ASTInterpretVisitor::enter(std::shared_ptr<ASTScheduledFactor > element) {
	if (exit()) return;
	ASTMethodVisitor* mv = newVisitor();
	init(mv);
	element->visit(mv);
}

ASTMethodVisitor* ASTInterpretVisitor::newVisitor() {
	ASTMethodVisitor* v = new ASTMethodVisitor(this);
	addHandle(v);
	return v;
}

void ASTInterpretVisitor::onException(Thread* t, Object_* e) {
	this->catched = false;
	//実行中の全てのビジターへ通知
	fire(t, e);
	//全てのビジターに通知したが
	//catchされなかったのでインタプリタを終了
	if (!catched) {
		error();
		printException(t, e);
	//	Thread::getCurrent()->clearException();
	//	throw BeanRuntimeException();
	}
}

void ASTInterpretVisitor::onCatch() {
	this->catched = true;
}
//---public method


//private method---
ClassLoaderSPtr ASTInterpretVisitor::getCLL() {
	return this->rootClassLoader;
}

void ASTInterpretVisitor::init(ASTMethodVisitor * mv) {
}

bool ASTInterpretVisitor::exit() {
	return exifOfintrrupt;
}
//---private method
