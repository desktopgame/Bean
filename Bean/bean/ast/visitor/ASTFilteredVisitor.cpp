#include "ASTFilteredVisitor.h"

//public method---
ASTFilteredVisitor::ASTFilteredVisitor() {
}

ASTFilteredVisitor::~ASTFilteredVisitor() {
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTNode > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTContinueStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTBreakStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTReturnStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTThrow > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTAliasStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTIncludeStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTDynFieldDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTDynMethodDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTClassDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTEnumDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTFieldDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTMethodDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTIfStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTWhileStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTForStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTLambdaDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTVariableDeclaration > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTUnaryOperator > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTBinaryOperator > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTMethodInvocation > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTFactor > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTTryStatement > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::enter(std::shared_ptr<ASTScheduledFactor > element) {
	callEnterUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTNode > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTContinueStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTBreakStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTReturnStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTThrow > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTAliasStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTIncludeStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTDynFieldDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTDynMethodDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTClassDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTEnumDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTFieldDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTMethodDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTIfStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTWhileStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTForStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTLambdaDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTVariableDeclaration > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTUnaryOperator > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTBinaryOperator > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTMethodInvocation > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTFactor > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTTryStatement > element) {
	callExitUnknown(element);
}

void ASTFilteredVisitor::exit(std::shared_ptr<ASTScheduledFactor > element) {
	callExitUnknown(element);
}
//---public method

//protected method---
void ASTFilteredVisitor::enterUnknown(std::shared_ptr<ASTNode> element) {
}

void ASTFilteredVisitor::exitUnknown(std::shared_ptr<ASTNode> element) {
}
//---protected method

//private method---
void ASTFilteredVisitor::callEnterUnknown(std::shared_ptr<ASTNode> element) {
	enterUnknown(element);
}

void ASTFilteredVisitor::callExitUnknown(std::shared_ptr<ASTNode> element) {
	exitUnknown(element);
}
//---private method