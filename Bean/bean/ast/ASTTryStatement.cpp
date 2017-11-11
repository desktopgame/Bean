#include "ASTTryStatement.h"
#include "ASTBody.h"

//public method---
ASTTryStatement::ASTTryStatement() {
}

ASTTryStatement::~ASTTryStatement() {
}

void ASTTryStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTTryStatement::getBody() const {
	return body;
}

void ASTTryStatement::setCatchStatement(std::shared_ptr<ASTCatchStatement> catchStatement) {
	this->catchStatement = catchStatement;
}

std::shared_ptr<ASTCatchStatement> ASTTryStatement::getCatchStatement() const {
	return catchStatement;
}

void ASTTryStatement::setFinally(std::shared_ptr<ASTBody> finallyBlock) {
	this->finallyBlock = finallyBlock;
}

std::shared_ptr<ASTBody> ASTTryStatement::getFinally() const {
	return finallyBlock;
}

void ASTTryStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTTryStatement));
	visitor->exit(SHARED_FROM_THIS(ASTTryStatement));
}

std::string ASTTryStatement::format() const {
	return "try";
}
IMPL_MAKE_SHARED_0_CPP(ASTTryStatement)
//---public method
