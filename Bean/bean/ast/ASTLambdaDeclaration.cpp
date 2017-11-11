#include "ASTLambdaDeclaration.h"
#include "../env/ClassLoader.h"
#include "../env/CodeBlock.h"
#include "../env/Delegate.h"
#include "../env/LambdaDelegate.h"
#include "../env/Object_.h"
#include "../env/user/UserDelegate.h"

//public method---
ASTLambdaDeclaration::ASTLambdaDeclaration() {
	this->parameters = std::vector<std::shared_ptr<ASTParameter>>();
	this->dynamicMethod = false;
}

ASTLambdaDeclaration::~ASTLambdaDeclaration() {
	parameters.clear();
}

void ASTLambdaDeclaration::addParameter(std::shared_ptr<ASTParameter> param) {
	parameters.push_back(param);
}

std::shared_ptr<ASTParameter> ASTLambdaDeclaration::getParameterAt(int index) const {
	return parameters.at(index);
}

int ASTLambdaDeclaration::getParameterCount() const {
	return parameters.size();
}

void ASTLambdaDeclaration::setBody(std::shared_ptr<ASTBody> body) {
	this->body = body;
}

std::shared_ptr<ASTBody> ASTLambdaDeclaration::getBody() const {
	return this->body;
}

void ASTLambdaDeclaration::setDynamicMethod(bool b) {
	this->dynamicMethod = b;
}

bool ASTLambdaDeclaration::isDynamicMethod() const {
	return this->dynamicMethod;
}

Object_ * ASTLambdaDeclaration::eval() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	LambdaDelegate* lmbdd = new LambdaDelegate(this);
	UserDelegate* ud = new UserDelegate(cll, lmbdd);
	Object_* r = ud;
	//ŠO‘¤‚Ì•Ï”‚ð’Ç‰Á
	CodeBlock* cdb = cll->getCodeBlock();
	CodeBlock* cdb_scope = cdb->getPointer();
	std::vector<std::string> nameVec = cdb_scope->getVariableName();
	for (int i = 0; i < nameVec.size(); i++) {
		lmbdd->addOutsideReference(
			nameVec.at(i)
		//	cdb->readReference(nameVec.at(i))
		);
	}
	ud->setDynamicMethod(isDynamicMethod());
	return r;
}

std::string ASTLambdaDeclaration::format() const {
	return "lambda";
}

void ASTLambdaDeclaration::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTLambdaDeclaration));
	visitor->exit(SHARED_FROM_THIS(ASTLambdaDeclaration));
}
IMPL_MAKE_SHARED_0_CPP(ASTLambdaDeclaration)
//---public method
