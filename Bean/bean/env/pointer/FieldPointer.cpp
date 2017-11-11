#include "FieldPointer.h"
#include "../../Debug.h"
#include "../../ast/ASTFieldAccess.h"
#include "../../ast/ASTName.h"
#include "../../env/Class.h"
#include "../../env/ClassLoader.h"
#include "../../env/Exception.h"
#include "../../env/Field.h"
#include "../../env/IncludeManager.h"
#include "../../env/Null.h"
#include "../../env/Numeric.h"
#include "../../env/Object_.h"
#include "../../env/gc/GCLock.h"

//public method---
FieldPointer::FieldPointer(std::shared_ptr<ASTFieldAccess> fieldAccess) {
	this->fieldAccess = std::weak_ptr<ASTFieldAccess>(fieldAccess);
	this->cache = nullptr;
}

FieldPointer::~FieldPointer() {
}

void FieldPointer::setValue(Object_ * obj) {
	setValue(getInvoker(), obj);
}

void FieldPointer::setValue(Object_ * inv, Object_ * obj) {
	std::string name = fieldAccess.lock()->getName()->getCString();
	//���I�t�B�[���h������
	if (inv != nullptr) {
		if (inv->findDynField(name) != nullptr) {
			inv->defineDynField(name, obj);
			return;
		}
	}
	Field* f = getField();
	f->setValue(inv, obj);
}

Object_ * FieldPointer::getValue() {
	return getValue(getInvoker());
}

Object_ * FieldPointer::getValue(Object_ * inv) {
	std::string name = fieldAccess.lock()->getName()->getCString();
	//���I�t�B�[���h������
	if (inv != nullptr) {
		Object_* dynFieldVal = inv->findDynField(name);
		if (dynFieldVal != nullptr) {
			return dynFieldVal;
		}
	}
	auto field = getField();
	if (!field) {
		return nullptr;
	}
	return field->getValue(inv);
}

bool FieldPointer::isAssignable() {
	auto field = getField();
	if (!field) {
		std::string name = fieldAccess.lock()->getName()->getCString();
		Object_* dynFieldVal = getInvoker()->findDynField(name);
		return dynFieldVal != nullptr;
	}
	return !field->getModifier().isFinal();
}

std::string FieldPointer::getLocation() {
	auto buff = std::string();
	auto field = getField();
	if (field) {
		buff += field->getClass().lock()->getName();
		buff += "#";
		buff += field->getName();
	} else {
		GCLock gcLock = GCLock();
		auto fa = fieldAccess.lock();
		auto clsName = fa->getParent()->eval()->getClass()->getName();
		auto varName = fa->getName()->getCString();
		buff += clsName + "#" + varName;
	}
	return buff;
}
//---public method

Object_ * FieldPointer::getInvoker() {
	Object_* inv = fieldAccess.lock()->getParent()->eval();
	return inv;
}

//private method---
Field* FieldPointer::getField() {
	//���ڈȍ~�̓L���b�V����Ԃ�
	if (cache != nullptr) {
		return cache;
	}
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	ClassSPtr cls = cll->getClass();
	auto fParentNode = fieldAccess.lock()->getParent();
	auto fNameNode = fieldAccess.lock()->getName();
	std::shared_ptr<ASTFactor> p = fParentNode;
	Object_* ref = nullptr;
	//�t�B�[���h�A�N�Z�X�̑Ώۂ��擾
	if (fParentNode != nullptr) {
		ref = fParentNode->eval();
	}
	//�擾�o�����Ȃ�N���X���擾
	if (ref != nullptr) {
		cls = ref->getClass();
	}
	//�����������Ȃ�static�N���X�Ƃ��Ĉ���
	if (cls == NULL) {
		std::string name = fParentNode->getStaticClassName();
		cls = cll->getIncludeManager()->getClass(name);
	}
	if (cls == NULL) {
		cls = cll->getClass();
	}
	//�N���X��������Ȃ�
	if (!cls) {
		return nullptr;
	}
	std::string fName = fNameNode->getCString();
	Field* field = cls->findField(fName);
	//����ȃt�B�[���h���݂��Ȃ�
	if (field == nullptr) {
		return nullptr;
	}
	this->cache = field;
	return field;
}
//---private method
