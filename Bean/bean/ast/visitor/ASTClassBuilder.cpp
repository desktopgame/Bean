#include "ASTClassBuilder.h"
#include <string>
#include "ASTIncludeVisitor.h"
#include "../ASTConstructorChain.h"
#include "../ASTConstructorDeclaration.h"
#include "../../env/Class.h"
#include "../../env/Constructor_.h"
#include "../../env/Field.h"
#include "../../env/GetMethod.h"
#include "../../env/Method.h"
#include "../../env/NativeMethod.h"
#include "../../env/Package.h"
#include "../../env/Parameter.h"
#include "../../env/ScriptMethod.h"
#include "../../env/SetMethod.h"

//public method---
ASTClassBuilder::ASTClassBuilder(std::string package, ClassSPtr classz, ClassLoaderSPtr classLoader) {
	this->package = package;
	this->classz = classz;
	this->classLoader = classLoader;
	this->inFor = 0;
	this->inWhile = 0;
}

ASTClassBuilder::~ASTClassBuilder() {
}

void ASTClassBuilder::enter(std::shared_ptr<ASTFieldDeclaration> element) {
	//��Ƀ��\�b�h��]������
	Field* field = new Field(
		classz,
		element->getModifier()->getValue(),
		element->getName()->getCString()
		);
	classz->addField(field);
	//�f�t�H���g�l�̐ݒ�
	field->setDefaultValue(element->getDefaultValue());
	//�Z�b�^�[�̐ݒ�
	std::shared_ptr<ASTName> setMName = element->getSetMethodName();
	if (setMName != nullptr) {
		classz->addMethod(new SetMethod(classz, field->getName(), setMName->getCString()));
	}
	//�Q�b�^�[�̐ݒ�
	std::shared_ptr<ASTName> getMName = element->getGetMethodName();
	if (getMName != nullptr) {
		classz->addMethod(new GetMethod(classz, field->getName(), getMName->getCString()));
	}
}

void ASTClassBuilder::enter(std::shared_ptr<ASTMethodDeclaration> element) {
	//���@���`�F�b�N
	element->getBody()->visit(this);
	//�`�F�C�����m�F
	Method* method = nullptr;
	Modifier mod = element->getModifier()->getValue();
	std::string methodName = element->getName()->getCString();
	auto consDefine = std::dynamic_pointer_cast<ASTConstructorDeclaration>(element);
	auto consChain = consDefine == nullptr ? nullptr : consDefine->getChain();
	//�l�C�e�B�u���\�b�h
	if (mod.isNative()) {
		//�l�C�e�B�u���\�b�h�Ȃ̂ɖ{�����ȗ�����Ă��Ȃ�
		if (!element->isSimple()) {
			throw ClassFormatException("�l�C�e�B�u���\�b�h�̖{���͏ȗ����Ă��������B");
		}
		//���O��new�Ȃ�R���X�g���N�^
		if (methodName == "new") {
			auto cons = new Constructor_(
				classz,
				mod,
				"new",
				new NativeMethod(
					classz,
					mod,
					methodName,
					package
					)
				);
			cons->setChain(consChain);
			method = cons;
		//����ȊO�Ȃ烁�\�b�h
		} else {
			method = new NativeMethod(
				classz,
				mod,
				methodName,
				package
				);
		}
	//��l�C�e�B�u���\�b�h
	} else {
		//�l�C�e�B�u���\�b�h�ł͂Ȃ��̂ɖ{�����ȗ�����Ă���
		if (element->isSimple()) {
			throw ClassFormatException("�l�C�e�B�u�łȂ����\�b�h�̖{���͏ȗ��ł��܂���B");
		}
		if (methodName == "new") {
			auto cons = new Constructor_(
				classz,
				mod,
				"new",
				new ScriptMethod(
					classz,
					element
					)
				);
			cons->setChain(consChain);
			method = cons;
		} else {
			method = new ScriptMethod(classz, element);
		}
	}
	for (int i = 0; i < element->getParameterCount(); i++) {
		std::string parName = element->getParameterAt(i)->getName()->getCString();
		method->addParameter(new Parameter(parName));
	}
	if (methodName == "new") {
		classz->addConstructor(dynamic_cast<Constructor_*>(method));
	} else {
		classz->addMethod(method);
	}
}


//���[�v�ɓ�������J�E���g�𑝂₵�܂�
void ASTClassBuilder::enter(std::shared_ptr<ASTForStatement> element) {
	this->inFor++;
}

void ASTClassBuilder::enter(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile++;
}


//���[�v�ɓ����Ă��Ȃ��̂Ɂ@break/continue �𔭌�������G���[
void ASTClassBuilder::enter(std::shared_ptr<ASTBreakStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw ClassFormatException("break �̓��[�v�̒��ɂ̂ݔz�u�o���܂��B: " + this->classz->getName());
	}
}

void ASTClassBuilder::enter(std::shared_ptr<ASTContinueStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw ClassFormatException("continue �̓��[�v�̒��ɂ̂ݔz�u�o���܂��B: " + this->classz->getName());
	}
}


//���[�v����o����J�E���g�����炵�܂�
void ASTClassBuilder::exit(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile--;
}

void ASTClassBuilder::exit(std::shared_ptr<ASTForStatement> element) {
	this->inFor--;
}

void ASTClassBuilder::enterUnknown(std::shared_ptr<ASTNode> element) {
}
//---public method
