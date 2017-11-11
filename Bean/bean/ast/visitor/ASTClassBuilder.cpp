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
	//先にメソッドを評価する
	Field* field = new Field(
		classz,
		element->getModifier()->getValue(),
		element->getName()->getCString()
		);
	classz->addField(field);
	//デフォルト値の設定
	field->setDefaultValue(element->getDefaultValue());
	//セッターの設定
	std::shared_ptr<ASTName> setMName = element->getSetMethodName();
	if (setMName != nullptr) {
		classz->addMethod(new SetMethod(classz, field->getName(), setMName->getCString()));
	}
	//ゲッターの設定
	std::shared_ptr<ASTName> getMName = element->getGetMethodName();
	if (getMName != nullptr) {
		classz->addMethod(new GetMethod(classz, field->getName(), getMName->getCString()));
	}
}

void ASTClassBuilder::enter(std::shared_ptr<ASTMethodDeclaration> element) {
	//文法をチェック
	element->getBody()->visit(this);
	//チェインを確認
	Method* method = nullptr;
	Modifier mod = element->getModifier()->getValue();
	std::string methodName = element->getName()->getCString();
	auto consDefine = std::dynamic_pointer_cast<ASTConstructorDeclaration>(element);
	auto consChain = consDefine == nullptr ? nullptr : consDefine->getChain();
	//ネイティブメソッド
	if (mod.isNative()) {
		//ネイティブメソッドなのに本文が省略されていない
		if (!element->isSimple()) {
			throw ClassFormatException("ネイティブメソッドの本文は省略してください。");
		}
		//名前がnewならコンストラクタ
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
		//それ以外ならメソッド
		} else {
			method = new NativeMethod(
				classz,
				mod,
				methodName,
				package
				);
		}
	//非ネイティブメソッド
	} else {
		//ネイティブメソッドではないのに本文が省略されている
		if (element->isSimple()) {
			throw ClassFormatException("ネイティブでないメソッドの本文は省略できません。");
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


//ループに入ったらカウントを増やします
void ASTClassBuilder::enter(std::shared_ptr<ASTForStatement> element) {
	this->inFor++;
}

void ASTClassBuilder::enter(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile++;
}


//ループに入っていないのに　break/continue を発見したらエラー
void ASTClassBuilder::enter(std::shared_ptr<ASTBreakStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw ClassFormatException("break はループの中にのみ配置出来ます。: " + this->classz->getName());
	}
}

void ASTClassBuilder::enter(std::shared_ptr<ASTContinueStatement> element) {
	if (inFor == 0 && inWhile == 0) {
		throw ClassFormatException("continue はループの中にのみ配置出来ます。: " + this->classz->getName());
	}
}


//ループから出たらカウントを減らします
void ASTClassBuilder::exit(std::shared_ptr<ASTWhileStatement> element) {
	this->inWhile--;
}

void ASTClassBuilder::exit(std::shared_ptr<ASTForStatement> element) {
	this->inFor--;
}

void ASTClassBuilder::enterUnknown(std::shared_ptr<ASTNode> element) {
}
//---public method
