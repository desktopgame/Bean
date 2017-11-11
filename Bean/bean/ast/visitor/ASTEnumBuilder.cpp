#include "ASTEnumBuilder.h"
#include "../../ast/ASTEnumItemDeclaration.h"
#include "../../env/Class.h"
#include "../../env/Enum.h"
#include "../../env/EnumItem.h"
#include "../../env/Field.h"
#include "../../env/NativeMethod.h"
#include "../../env/Package.h"
#include "../../env/gc/GCLock.h"
#include "../../env/user/UserObject.h"
#include "../../env/native/enumitem/EnumItemToStringExecutor.h"

//public method---
ASTEnumBuilder::ASTEnumBuilder(std::string package, ClassSPtr classz, ClassLoaderSPtr classLoader) {
	 this->package = package;
	this->classz = classz;
	this->classLoader = classLoader;
	this->index = 0;
}

ASTEnumBuilder::~ASTEnumBuilder() {
}

void ASTEnumBuilder::enter(std::shared_ptr<ASTEnumDeclaration> element) {
	GCLock gcLock = GCLock();
	ClassSPtr enumItemCls = Package::getClass("api.EnumItem");
	ClassLoaderWPtr enumItemCll = enumItemCls->getClassLoader();
	//全ての列挙子に対して
	for (int i = 0; i < element->getEnumItemCount(); i++) {
		std::shared_ptr<ASTEnumItemDeclaration> enumItemDecl = element->getEnumItemAt(i);
		std::shared_ptr<ASTName> item = enumItemDecl->getName();
		std::shared_ptr<ASTFactor> val = enumItemDecl->getValue();
		std::string itemName = item->getCString();
		//指定の名前の静的フィールドを作成
		Field* field = new Field(
			classz, 
			Modifier(
				Modifier::PUBLIC |
				Modifier::STATIC |
				Modifier::FINAL
			),
			itemName
		);
		classz->addField(field);
		//列挙子の値はGCされない
		Heap* heap = Heap::getInstance();
		heap->lock();
		Object_* enumItemRef = (val == nullptr ? Null::getInstance() : val->eval());
		//enumItemRef->keep();
		heap->unlock();
		//EnumItem
		std::string enumItemClsName = "api.EnumItem#" + classz->getName() + "#" + itemName;
		std::shared_ptr<ClassLoader> enumItemClassLoader = std::make_shared<ClassLoader>(classLoader, std::make_shared<ASTNode>(), enumItemClsName);
		enumItemClassLoader->registerClassLoader();

		std::shared_ptr<EnumItem> enumItemClass = std::make_shared<EnumItem>(
			enumItemClassLoader,
	//		nullptr,
	//		classLoader,
			enumItemCls,
			enumItemClsName,
			i,
			enumItemRef
		);
		enumItemClass->registerClass();
		PackageSPtr pstr = Package::getPackage(package, true);
		pstr->addClass(enumItemClass);
		//この列挙子の特異メソッドを定義
		NativeMethod* toStringMethod = new NativeMethod(
			enumItemClass,
			Modifier(Modifier::PUBLIC),
			"toString",
			package
		);
		toStringMethod = toStringMethod->singular(new EnumItemToStringExecutor(itemName));
		enumItemClass->addMethod(toStringMethod);
		//列挙子は代入不可
		UserObject* o = new UserObject(enumItemClass);
		field->setValue(nullptr, o);
	}
}

void ASTEnumBuilder::exit(std::shared_ptr<ASTEnumDeclaration> element) {
	Package::getPackage(package, true)->addClass(classz);
}
//---public method
