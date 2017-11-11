#include "ASTCatchStatement.h"
#include "ASTBody.h"
#include "ASTName.h"

//public method---
ASTCatchStatement::ASTCatchStatement() {
}

ASTCatchStatement::~ASTCatchStatement() {
}

void ASTCatchStatement::setCaptureExceptionName(std::shared_ptr<ASTName> captureExceptionName) {
	this->captureExceptionName = captureExceptionName;
}

std::shared_ptr<ASTName> ASTCatchStatement::getCaptureExceptionName() const {
	return captureExceptionName;
}

void ASTCatchStatement::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTCatchStatement::getBody() const {
	return body;
}

std::string ASTCatchStatement::format() const {
	return "catch";
}
IMPL_MAKE_SHARED_0_CPP(ASTCatchStatement)
//---public method
