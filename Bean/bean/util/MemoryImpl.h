#pragma once
#ifndef BEAN_UTIL_MEMORYIMPL_H
#define BEAN_UTIL_MEMORYIMPL_H
#include "Memory.h"

template<typename T>
T * Memory::getNull() {
	return nullptr;
}

template<typename T>
std::shared_ptr<T> Memory::getSharedNull() {
	return nullptr;
}

template<typename T>
bool Memory::isNull(T * ptr) {
	return ptr == NULL || ptr == nullptr;
}

template<typename T>
bool Memory::isSharedNull(std::shared_ptr<T> ptr) {
	return ptr == nullptr;
}
#endif // !BEAN_UTIL_MEMORYIMPL_H
