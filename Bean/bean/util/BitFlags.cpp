#include "BitFlags.h"
#include <math.h>
//public method---
BitFlags::BitFlags() {
}

BitFlags::~BitFlags() {
}

void BitFlags::setFlag(int flag) {
	this->flag = flag;
}

void BitFlags::addFlag(int flag) {
	this->flag |= flag;
}

void BitFlags::removeFlag(int flag) {
	if(hasFlag(flag))
		this->flag ^= flag;
}

void BitFlags::clearFlag() {
	this->flag = 0;
}

int BitFlags::getFlag() {
	return this->flag;
}

bool BitFlags::hasFlag(int flag) {
	return (this->flag & flag) != 0;
}

bool BitFlags::compFlag(int flag) {
	return (this->flag == flag);
}

int BitFlags::makeBit(int level) {
	return pow(2, level);
}
//---public method
