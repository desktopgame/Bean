#include "ASTConstructorChain.h"
#include "../env/Class.h"
#include "../env/Constructor_.h"

//public method---
ASTConstructorChain::ASTConstructorChain() {
	this->arguments = std::vector<std::shared_ptr<ASTFactor>>();
}

ASTConstructorChain::~ASTConstructorChain() {
}

void ASTConstructorChain::setChainType(ConstructorChainType type) {
	this->cct = type;
}
ConstructorChainType ASTConstructorChain::getChainType() const {
	return this->cct;
}

void ASTConstructorChain::addArgument(std::shared_ptr<ASTFactor> arg) {
	this->arguments.push_back(arg);
}

std::shared_ptr<ASTFactor> ASTConstructorChain::getArgumentAt(int index) const {
	return arguments.at(index);
}

void ASTConstructorChain::removeArgumentAt(int index) {
	arguments.erase(arguments.begin() + index);
}

int ASTConstructorChain::getArgumentCount() const {
	return arguments.size();
}
Constructor_ * ASTConstructorChain::find(Constructor_ * self) {
	auto classz = self->getClass().lock();
	//自クラスのコンストラクタで連鎖
	if (getChainType() == ConstructorChainType::cct_This) {
		return classz->findConstructor(getArgumentCount(), false);
	//親クラスのコンストラクタで連鎖
	} else {
		auto super = classz->getSuper().lock();
		return super->findConstructor(this->getArgumentCount(), false);
	}
}
IMPL_MAKE_SHARED_0_CPP(ASTConstructorChain)
//---public method
