#include "CharacterToStringExecutor.h"
#include "../../Character.h"

//public method---
CharacterToStringExecutor::CharacterToStringExecutor() {
}

CharacterToStringExecutor::~CharacterToStringExecutor() {
}

Object_ * const CharacterToStringExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Character* ch = invoker->asCharacter();
	char c = ch->getCChar();
	std::string s = std::string();
	s.push_back(c);
	String* retV = String::allocString(s);
	return retV;
}
//---public method