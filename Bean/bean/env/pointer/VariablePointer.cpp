#include "VariablePointer.h"
#include "../ClassLoader.h"
#include "../CodeBlock.h"
#include "../Field.h"
#include "../IncludeManager.h"
#include "../Null.h"
#include "../Numeric.h"
#include "../Object_.h"
#include "../../Debug.h"
#include "../../ast/ASTName.h"

//public method---
VariablePointer::VariablePointer(std::shared_ptr<ASTVariable> variable) {
	this->variable = std::weak_ptr<ASTVariable>(variable);
	this->cache = nullptr;
}

VariablePointer::~VariablePointer() {
}

void VariablePointer::setValue(Object_ * obj) {
	ClassLoaderSPtr classLoader = ClassLoader::getCurrentClassLoader();
	CodeBlock* codeBlock = classLoader->getCodeBlock();
	std::string name = variable.lock()->getName()->getCString();
	if (codeBlock->readReference(name)) {
		codeBlock->writeReference(name, obj);
	} else {
		Object_* inst = classLoader->getLock();
		Field* field = getField();
		if (field) {
			field->setValue(inst, obj);
		//フィールドが見つからなかったら仮想フィールドを検査
		} else if(inst->findDynField(name)) {
			inst->defineDynField(name, obj);
		}
	}
}

Object_ * VariablePointer::getValue() {
	ClassLoaderSPtr classLoader = ClassLoader::getCurrentClassLoader();
	CodeBlock* codeBlock = classLoader->getCodeBlock();
	std::string name = variable.lock()->getName()->getCString();
	Object_* obj = codeBlock->readReference(name);
	if (obj == nullptr) {
		Object_* inst = classLoader->getLock();
		Field* field = getField();
		if (field) {
			auto ret = field->getValue(inst);
			return ret;
		//フィールドが見つからなかったら仮想フィールドを検査
		} else if (inst != nullptr && inst->findDynField(name)) {
			return inst->findDynField(name);
		} else {
			return nullptr;
		}
	} else {
		//std::cout << "get " << name << std::endl;
		//Debug::break_if(name == "i");
		return obj;
	}
}

bool VariablePointer::isAssignable() {
	return true;
}

std::string VariablePointer::getLocation() {
	auto field = getField();
	if (field == nullptr) {
		return variable.lock()->getName()->getCString();
	}
	auto buff = std::string();
	buff += (field->getClass().lock()->getName());
	buff += "#";
	buff += field->getName();
	return buff;
}
//---public method

//private method---
Field * VariablePointer::getField() {
	if (this->cache != nullptr) {
		return cache;
	}
	ClassLoaderSPtr curCls = ClassLoader::getCurrentClassLoader();
	Object_* inv = curCls->getLock();
	//if (!inv) return nullptr;
	ClassSPtr cls = inv == nullptr ? curCls->getClass() : inv->getClass();
	if (cls == nullptr) {
		IncludeManager* incMgr = curCls->getIncludeManager();
		cls = incMgr->getClass(variable.lock()->getName()->getCString());
	}
	if (cls == nullptr) {
		return nullptr;
	}
	std::string fieldName = variable.lock()->getName()->getCString();
//	Debug::break_if(fieldName == "message");
	Field* field = cls->findField(fieldName);
	if (field == nullptr) {
		return nullptr;
	}
	//staticじゃないのにそれを実行するオブジェクトがいない
	if (!field->getModifier().isStatic() &&
		inv == nullptr) {
		return nullptr;
	}
	this->cache = field;
	return field;
}
//---private method
