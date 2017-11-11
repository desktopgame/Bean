#include "CharacterAsInteger.h"
#include "../../Character.h"

//public method---
CharacterAsInteger::CharacterAsInteger() {
}

CharacterAsInteger::~CharacterAsInteger() {
}

Object_ * const CharacterAsInteger::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Character* self = arg_cast(Character, 0, "Character");
	char c = self->getCChar();
	return getInteger(static_cast<int>(c));
}
//---public method