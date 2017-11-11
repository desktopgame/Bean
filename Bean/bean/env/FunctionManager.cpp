#include "FunctionManager.h"
#include "Function.h"

//public method---
FunctionManager::FunctionManager() {
	this->funcVec = std::vector<Function*>();
}

FunctionManager::~FunctionManager() {
	for (int i = funcVec.size() - 1; i >= 0; i--) {
		Function* func = funcVec.at(i);
		funcVec.erase(funcVec.begin() + i);
		delete func;
	}
}

void FunctionManager::addFunction(Function * func) {
	this->funcVec.push_back(func);
}

Function * const FunctionManager::findFunction(std::string name, int argCount) const {
	for (int i = 0; i < funcVec.size(); i++) {
		Function* func = funcVec.at(i);
		if (func->getName() == name &&
			func->getArgumentCount() == argCount) {
			return func;
		}
	}
	return nullptr;
}

Function * const FunctionManager::getFunctionAt(int index) const {
	return this->funcVec.at(index);
}

bool FunctionManager::contains(Function * func) const {
	for (Function* elem : this->funcVec) {
		if (elem->getName() == func->getName() &&
			elem->getArgumentCount() == func->getArgumentCount()) {
			return true;
		}
	}
	return false;
}

int FunctionManager::getFunctionCount() {
	return this->funcVec.size();
}
//---public method