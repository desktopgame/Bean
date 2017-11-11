#include "ASTNewStatement.h"
#include "ASTMethodInvocation.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Constructor_.h"
#include "../env/IncludeManager.h"
#include "../env/Method.h"
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
ASTNewStatement::ASTNewStatement() {
}

ASTNewStatement::~ASTNewStatement() {
	arguments.clear();
}

void ASTNewStatement::setClassName(std::shared_ptr<ASTName> className) {
	this->className = className;
}

std::shared_ptr<ASTName> ASTNewStatement::getClassName() const {
	return this->className;
}

void ASTNewStatement::addArgument(std::shared_ptr<ASTFactor> factor) {
	this->arguments.push_back(factor);
}

std::shared_ptr<ASTFactor> ASTNewStatement::getArgumentAt(int index) const {
	return arguments.at(index);
}

int ASTNewStatement::getArgumentCount() const {
	return arguments.size();
}

std::string ASTNewStatement::format() const {
	return "new";
}

void ASTNewStatement::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTFactor));
	visitor->exit(SHARED_FROM_THIS(ASTFactor));
}

Object_ * ASTNewStatement::eval() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	ClassSPtr cl = cll->getIncludeManager()->getClass(getClassName()->getCString());
	//ˆø”‚ğì¬
		//‚±‚±‚ÅV‚½‚ÈQÆ‚ğì¬‚µ‚È‚¢‚ÆAC#‚Å‚¢‚¤‚Æ‚±‚ë‚Ìref‚É‚È‚Á‚Ä‚µ‚Ü‚¤
	std::vector<Object_*> args = std::vector<Object_*>();
	for (int i = 0; i < getArgumentCount(); i++) {
		args.push_back(getArgumentAt(i)->eval());
	}
	ClassLoader::pushCurrentClassLoader(cl->getClassLoader().lock());
	Constructor_* cons = cl->findConstructor(cll, getArgumentCount(),false);
	Object_* retVal = Null::getInstance();
	if (cons != nullptr) {
		retVal = cons->execute(nullptr, args, true);
	} else {
		ASTMethodInvocation::throwNoMethodError(cll, cl->getName(), "new", getArgumentCount());
	}
	ClassLoader::popCurrentClassLoader();
	return retVal;
}
IMPL_MAKE_SHARED_0_CPP(ASTNewStatement)
//---public method
