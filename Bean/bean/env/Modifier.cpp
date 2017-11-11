#include "Modifier.h"

const  int Modifier::PUBLIC = 1;
const  int Modifier::PRIVATE = 2;
const  int Modifier::PROTECTED = 4;
const  int Modifier::STATIC = 8;
const  int Modifier::FINAL = 16;
const  int Modifier::NATIVE = 32;
const  int Modifier::BLANK = 257;

//public method---
Modifier::Modifier(int mask) {
	this->mask = mask;
}

Modifier::Modifier() {
	this->mask = PUBLIC;
}

Modifier::Modifier(Modifier mod, int mask) {
	this->mask = mod.mask | mask;
}

Modifier::~Modifier() {
}

int Modifier::getId(std::string text) {
	if (text == "public") return PUBLIC;
	else if (text == "private") return PRIVATE;
	else if (text == "protected") return PROTECTED;
	else if (text == "static") return STATIC;
	else if (text == "const") return FINAL;
	else if (text == "native") return NATIVE;
	else return -1;
}

Modifier Modifier::publicStatic() {
	return Modifier(PUBLIC|STATIC);
}

std::string Modifier::getString()  const {
	std::string str = "[";
	if (hasFlag(PUBLIC)) str += "public|";
	if (hasFlag(PRIVATE)) str += "private|";
	if (hasFlag(PROTECTED)) str += "protected|";
	if (hasFlag(STATIC)) str += "static|";
	if (hasFlag(FINAL)) str += "final|";
	str.erase(str.end() - 1);
	str += "]";
	return str;
}

bool Modifier::isPublic()  const {
	return hasFlag(PUBLIC);
}

bool Modifier::isPrivate() const {
	return hasFlag(PRIVATE);
}

bool Modifier::isProtected() const {
	return hasFlag(PROTECTED);
}

bool Modifier::isStatic()  const {
	return hasFlag(STATIC);
}

bool Modifier::isFinal()  const {
	return hasFlag(FINAL);
}

bool Modifier::isNative()  const {
	return hasFlag(NATIVE);
}

bool Modifier::isError()const {
	return
		(hasFlag(PUBLIC) && (hasFlag(PRIVATE) || hasFlag(PROTECTED)));
}

bool Modifier::isBlank() const {
	return mask == BLANK;
}

bool Modifier::hasFlag(int bit)const {
	return (mask & bit) != 0;
}
//---public method