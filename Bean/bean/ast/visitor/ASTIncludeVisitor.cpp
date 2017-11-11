#include "ASTIncludeVisitor.h"
#include <memory>
#include "ASTClassBuilder.h"
#include "ASTEnumBuilder.h"
#include "../ASTErrorNode.h"
#include "../InterpretExitException.h"
#include "../../Debug.h"
#include "../../env/Class.h"
#include "../../env/ClassFormatException.h"
#include "../../env/Constructor_.h"
#include "../../env/Enum.h"
#include "../../env/Field.h"
#include "../../env/Method.h"
#include "../../env/NativeMethod.h"
#include "../../env/Package.h"
#include "../../env/Parameter.h"
#include "../../env/ScriptMethod.h"
#include "../../util/Memory.h"
#include "../../env/native/enum/EnumValueOfExecutor.h"
#include "../../env/native/enum/EnumValuesExecutor.h"

//public method---
ASTIncludeVisitor::ASTIncludeVisitor(std::string package, ClassLoaderSPtr parent) {
	this->package = package;
	this->parent = parent;
	this->loadCount = 0;
}

ASTIncludeVisitor::~ASTIncludeVisitor() {
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTNode > element) {
	auto err = std::dynamic_pointer_cast<ASTErrorNode>(element);
	if (err) {
		throw ClassFormatException(err->getMessage());
	}
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTAliasStatement > element) {
	auto oldname = element->getOldName()->getCString();
	auto newname = element->getNewName()->getCString();
	parent->getIncludeManager()->checkAlias(oldname, newname);
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTIncludeStatement > element) {
	std::string clsName = element->getPath()->getCString();
	std::string pkgName = Package::resolvePackage(clsName);
	try {
		parent->loadClass(clsName);
	} catch (ClassFormatException e) {
		throw ClassFormatException(e.what());
	}
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTClassDeclaration > element) {
	//既に型が定義されている
	if (loadCount >= 1) {
		throw ClassFormatException("一つのライブラリファイルに複数の型を定義することは出来ません。");
	}
	this->loadCount++;
	ClassLoader::loadClass(package, element, parent);
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTEnumDeclaration > element) {
	//既に型が定義されている
	if (loadCount >= 1) {
		throw ClassFormatException("一つのライブラリファイルに複数の型を定義することは出来ません。");
	}
	this->loadCount++;
	ClassLoader::loadEnum(package, element, parent);
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTFieldDeclaration > element) {
	
}

void ASTIncludeVisitor::enter(std::shared_ptr<ASTMethodDeclaration > element) {
	
}

void ASTIncludeVisitor::exit(std::shared_ptr<ASTClassDeclaration > element) {
	
}

std::string ASTIncludeVisitor::getPackage() {
	return this->package;
}
//---public method
