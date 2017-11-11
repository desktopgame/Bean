#include "CharacterOpAddExecutor.h"

//public method---
CharacterOpAddExecutor::CharacterOpAddExecutor() {
}

CharacterOpAddExecutor::~CharacterOpAddExecutor() {
}

Object_ * const CharacterOpAddExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return invoker->add(args.at(0));
}
//---public method