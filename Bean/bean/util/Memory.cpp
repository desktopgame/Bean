#include "Memory.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include "../env/Null.h"
#include "../env/Object_.h"

//public method---
Memory::Memory() {
}

Memory::~Memory() {
}

int Memory::getAddres(void * p) {
	int i = (int)(unsigned long)p;
	return i;
}

void Memory::printAddres(void * p) {
	int i = getAddres(p);
	std::cout << std::to_string(i) << std::endl;
}

bool Memory::isObjNull(Object_ * obj) {
	if (Null::getInstance() == obj) return true;
	return obj == nullptr;
}
//---public method
