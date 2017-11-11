#include "Debug.h"
BitFlags Debug::bits = BitFlags();

//public method---
void Debug::break_of() {
}

void Debug::break_if(bool b) {
	if (b) break_of();
}

void Debug::break_has(int flag) {
	break_if(hasFlag(flag));
}

void Debug::setFlag(int flag) {
	bits.setFlag(flag);
}

void Debug::addFlag(int flag) {
	bits.addFlag(flag);
}

void Debug::removeFlag(int flag) {
	bits.removeFlag(flag);
}

void Debug::clearFlag() {
	bits.clearFlag();
}

int Debug::getFlag() {
	return bits.getFlag();
}

bool Debug::hasFlag(int flag) {
	return bits.hasFlag(flag);
}

bool Debug::compFlag(int flag) {
	return bits.compFlag(flag);
}
//---public method


//private method---
Debug::Debug() {
}

Debug::~Debug() {
}
//---private method
