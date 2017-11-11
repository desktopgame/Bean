#include "ASTScheduledFactor.h"
#include <iostream>
#include <stdexcept>
#include "../Debug.h"
#include "../env/Numeric.h"
#include "../env/Object_.h"
#include "../util/Memory.h"
#include "../env/gc/GCLock.h"
#include "../env/gc/Heap.h"

//public method---
ASTScheduledFactor::ASTScheduledFactor() {
	this->_isPrefix = false;
	this->_isSuffix = false;
}

void ASTScheduledFactor::setArgument(std::shared_ptr<ASTFactor> argument) {
	this->argument = argument;
//	Memory::printAddres(argument);
}

std::shared_ptr<ASTFactor> ASTScheduledFactor::getArgument() const {
	return this->argument;
}

void ASTScheduledFactor::setPrefix(bool isPrefix) {
	this->_isPrefix = isPrefix;
}

bool ASTScheduledFactor::isPrefix() const {
	return this->_isPrefix;
}

void ASTScheduledFactor::setSuffix(bool isSuffix) {
	this->_isSuffix = isSuffix;
}

bool ASTScheduledFactor::isSuffix() const {
	return this->_isSuffix;
}

Object_ * ASTScheduledFactor::eval() {
//	GCSystem::getInstance()->lock();
	buffer_begin();
	Object_* retVal = evalImpl();
	buffer_end();
//	GCSystem::getInstance()->unlock();
	return retVal;
}

std::string ASTScheduledFactor::format() const {
	return "scheduled";
}

void ASTScheduledFactor::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTScheduledFactor));
	visitor->exit(SHARED_FROM_THIS(ASTScheduledFactor));
}
//---public method


//protected method---
ASTScheduledFactor::~ASTScheduledFactor() {
	//delete_(getArgument());
}

Object_ * ASTScheduledFactor::evalImpl() {
	Object_* ref = getArgument()->eval();
	//先置きインクリメント
	if (isPrefix()) {
		//本体を変更
		edit(ref);
		//複製を返す
		return newClone(ref);
		//後置き
	} else if (isSuffix()) {
		//変更前の値を複製
		Object_* clone = newClone(ref);
		//本体を変更
		edit(ref);
		//複製を返す
		return clone;
	} else {
		//Heap::getInstance()->unlock();
		throw std::logic_error("前置き/後置き のどちらかを設定してください");
	}
}

Object_ * ASTScheduledFactor::newClone(Object_ * src) {
	Object_* original = src;
	Object_* clone = original->clone();
	return clone;
}

Object_ * ASTScheduledFactor::lazy(Object_ * target, Object_ * one) {
	return nullptr;
}

void ASTScheduledFactor::edit(Object_ * src) {
}
//---protected method
