#include "ASTMethodInvocation.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"
#include "../env/Function.h"
#include "../env/Method.h"
#include "../env/Numeric.h"
#include "../env/String.h"
#include "../threads/Thread.h"

//public method---
ASTMethodInvocation::ASTMethodInvocation() {
	this->invocation = nullptr;
	this->arguments = std::vector<std::shared_ptr<ASTFactor>>();
}

void ASTMethodInvocation::setName(std::shared_ptr<ASTName> name) {
	this->name = name;
}

std::shared_ptr<ASTName> ASTMethodInvocation::getName() const {
	return this->name;
}

void ASTMethodInvocation::addArgument(std::shared_ptr<ASTFactor> factor) {
	this->arguments.push_back(factor);
}

std::shared_ptr<ASTFactor> ASTMethodInvocation::getArgumentAt(int index) const {
	return arguments.at(index);
}

int ASTMethodInvocation::getArgumentCount() const {
	return arguments.size();
}

void ASTMethodInvocation::setInvocation(std::shared_ptr<ASTMethodInvocation> invocation) {
	this->invocation = invocation;
}

std::shared_ptr<ASTMethodInvocation> ASTMethodInvocation::getInvocation() const {
	return this->invocation;
}

std::string ASTMethodInvocation::format() const {
	return "invoke";
}

void ASTMethodInvocation::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTMethodInvocation));
	visitor->exit(SHARED_FROM_THIS(ASTMethodInvocation));
}

void ASTMethodInvocation::throwNoClassError(ClassLoaderSPtr cll, std::string className) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(String::allocString(className));
	Thread::getCurrent()->setException(Class::dynamicNewInstance("api.exc.NoClassError", args));
}

void ASTMethodInvocation::throwNoMethodError(ClassLoaderSPtr cll, std::string className, std::string methodName, int argCount) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(String::allocString(className));
	args.push_back(String::allocString(methodName));
	args.push_back(Numeric::newInteger(argCount));
	Thread::getCurrent()->setException(Class::dynamicNewInstance("api.exc.NoMethodError", args));
}

std::shared_ptr<ASTMethodInvocationByMessage> ASTMethodInvocation::asByMessage() {
	return nullptr;
}

std::shared_ptr<ASTMethodInvocationBySelf> ASTMethodInvocation::asBySelf() {
	return nullptr;
}
//---public method

std::vector<Object_*> ASTMethodInvocation::getEvalArguments(Function * f) {
	return  getEvalArgumentImpl([f](int i) {
		Exception::throw_e_simple("api.exc.ArgumentException", "引数を計算出来ませんでした(" + std::to_string(i) + ")：" + f->getName());
	});
}

//protected method---
std::vector<Object_*> ASTMethodInvocation::getEvalArguments(Method* m) {
	return  getEvalArgumentImpl([m](int i) {
		Exception::throw_e_simple("api.exc.ArgumentException", "引数を計算出来ませんでした(" + std::to_string(i) +")：" + m->getLocation());
	});
}

ASTMethodInvocation::~ASTMethodInvocation() {
	arguments.clear();
}
//---protected method


//private method---
std::vector<Object_*> ASTMethodInvocation::getEvalArgumentImpl(std::function<void(int)> f) {
	auto ret = std::vector<Object_*>();
	//全ての引数を計算します
	for (int i = 0; i < getArgumentCount(); i++) {
		auto argNode = getArgumentAt(i);
		auto elem = argNode->eval();
		if (thrown()) {
			break;
		}
		//計算出来なかった
		if (elem == nullptr) {
			f(i);
			break;
		}
		ret.push_back(elem);
	}
	return ret;
}
//---private method
