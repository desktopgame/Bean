#include "Class.h"
#include <assert.h>
#include "ClassLoader.h"
#include "CodeBlock.h"
#include "Constructor_.h"
#include "Field.h"
#include "Member.h"
#include "Method.h"
#include "Method.h"
#include "NewMethod.h"
#include "Package.h"
#include "Parameter.h"
#include "../Debug.h"
#include "gc/Block.h"
#include "gc/GCLock.h"
#include "../util/STL.h"

//public method---
Class::Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name)
 : Class(classLoader, super, name, false){
	
}

Class::Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, bool singular) {
	init(classLoader, super, name, singular);
}

Class::Class(ClassLoaderSPtr classLoader, std::string name) {
	init(classLoader, name);
}

Class::~Class() {
	while (!constructors.empty()) {
		Constructor_* cons = constructors.at(0);
		constructors.erase(constructors.begin());
		delete cons;
	}
	while (!methods.empty()) {
		Method* met = methods.at(0);
		methods.erase(methods.begin());
		delete met;
	}
	while (!fields.empty()) {
		Field* fie = fields.at(0);
		fields.erase(fields.begin());
		delete fie;
	}
}

void Class::registerClass() {
	if (!singular) {
		Package::registerClass(shared_from_this());
	}
}

void Class::addConstructor(Constructor_ * constructor) {
	constructors.push_back(constructor);
	addMethod(new NewMethod(constructor));
}

Constructor_ * const Class::findConstructor(int paramCount, bool findParents) {
	return findConstructor(ClassLoader::getCurrentClassLoader(), paramCount, findParents);
}

Constructor_ * const Class::findConstructor(ClassLoaderSPtr cll, int paramCount, bool findParents) {
	Constructor_* retVal = nullptr;
	ClassSPtr c = shared_from_this();
	do {
		bool found = false;
		for (int i = 0; i < c->getConstructorCount(); i++) {
			Constructor_* elem = c->getConstructorAt(i);
			//privateで、自身がそのクラスでない
			//protectedで、自身がそのサブクラスでない
			Modifier mod = elem->getModifier();
			bool privateAndSelf = (mod.isPrivate() && c != cll->getClass());
			bool protectAndSup = (mod.isProtected() && !c->isSubClass(cll->getClass()));
			if ( privateAndSelf || protectAndSup ) {
				continue;
			}
			if (elem->getParameterCount() == paramCount) {
				retVal = elem;
				found = true;
				break;
			}
		}
		if (found || (c->getConstructorCount() > 0) || !findParents) {
			break;
		}
		c = c->getSuper().lock();
	} while (c != nullptr);
	return retVal;
}

Constructor_ * const Class::getConstructorAt(int index) {
	return constructors.at(index);
}

bool Class::hasDefaultConstructor() {
	for (Constructor_* cons : getConstructors()) {
		if (cons->getParameterCount() == 0) {
			Modifier mod = cons->getModifier();
			return mod.isPublic() || mod.isProtected();
		}
	}
	return false;
}

std::vector<Constructor_*> Class::getConstructors() {
	std::vector<Constructor_*> ret = std::vector<Constructor_*>();
	for (int i = 0; i < getConstructorCount(); i++) {
		ret.push_back(getConstructorAt(i));
	}
	return ret;
}

void Class::removeConstructorAt(int index) {
	Constructor_* constructor = constructors.at(index);
	constructors.erase(constructors.begin() + index);
	delete constructor;
}

int Class::getConstructorCount() {
	return constructors.size();
}

void Class::addField(Field * field) {
	for (int i = 0; i < fields.size(); i++) {
		Field* elem = fields.at(i);
		assert(field->getName() != elem->getName());
	}
	this->fields.push_back(field);
}

Field * const Class::getFieldAt(int index) {
	return fields.at(index);
}

std::vector<Field*> Class::getFields() {
	std::vector<Field*> ret = std::vector<Field*>();
	for (int i = 0; i < getFieldCount(); i++) {
		ret.push_back(getFieldAt(i));
	}
	return ret;
}

Field * const Class::findField(const std::string& name) {
	Field* ret = nullptr;
	ClassSPtr c = shared_from_this();
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	do {
		bool found = false;
		for (int i = 0; i < c->getFieldCount(); i++) {
			Field* elem = c->getFieldAt(i);
			//privateで、自身がそのクラスでない
			//protectedで、自身がそのサブクラスでない
			Modifier mod = elem->getModifier();
			if ((mod.isPrivate() && c != cll->getClass()) ||
				(mod.isProtected() && !c->isSubClass(cll->getClass()))) {
				continue;
			}
			if (elem->getName() == name) {
				ret = elem;
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
		c = c->getSuper().lock();
	} while (c != nullptr);
	return ret;
}

void Class::removeFieldAt(int index) {
	Field* field = fields.at(index);
	fields.erase(fields.begin() + index);
	delete field;
}

int Class::getFieldCount() {
	return fields.size();
}

void Class::addMethod(Method * method) {
	//assert(method != NULL && method != nullptr);
	for (int i = 0; i < methods.size(); i++) {
		Method* elem = methods.at(i);
		assert(method->getName() != elem->getName() || method->getParameterCount() != elem->getParameterCount());
	}
	this->methods.push_back(method);
}

Method * const Class::getMethodAt(int index) {
	return methods.at(index);
}

std::vector<Method*> Class::getMethods() {
	std::vector<Method*> ret = std::vector<Method*>();
	for (int i = 0; i < getMethodCount(); i++) {
		ret.push_back(getMethodAt(i));
	}
	return ret;
}

Method * const Class::findMethod(const std::string& name, int paramCount, bool findParentsIfConstructor, bool extractProxy) {
	//NOTE:コンストラクタ名は常にnew
	if (extractProxy && name == "new") {
		Constructor_* c = findConstructor(paramCount, findParentsIfConstructor);
		if (c == nullptr) {
			return nullptr;
		}
		return c->getProxy();
	}
	bool cons = name == "new";
	Method* ret = nullptr;
	ClassSPtr c = shared_from_this();
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	do {
		bool found = false;
		for (int i = 0; i < c->getMethodCount(); i++) {
			Method* elem = c->getMethodAt(i);
			//privateで、自身がそのクラスでない
			//protectedで、自身がそのサブクラスでない
			Modifier mod = elem->getModifier();
			if ((mod.isPrivate() && c != cll->getClass()) ||
				(mod.isProtected() && !c->isSubClass(cll->getClass()))) {
				continue;
			}
			if (elem->getName() == name &&
				elem->getParameterCount() == paramCount) {
				ret = elem;
				found = true;
				break;
			}
		}
		if (found || (!findParentsIfConstructor && cons)) {
			break;
		}
		c = c->getSuper().lock();
	} while (c != nullptr);
	return ret;
}

Method * const Class::findMethod(const std::string& name, int paramCount, bool findParentsIfConstructor) {
	return findMethod(name, paramCount, findParentsIfConstructor, false);
}

void Class::removeMethodAt(int index) {
	Method* method = methods.at(index);
	methods.erase(methods.begin() + index);
	delete method;
}

int Class::getMethodCount() {
	return methods.size();
}

ClassWPtr const Class::getSuper() {
	return this->super;
}

std::string Class::getName() const {
	return this->name;
}

bool Class::isSubClass(Class * classz) {
	ClassSPtr p = getSuper().lock();
	if (p == NULL) {
		return classz == nullptr;
	}
	if (classz == nullptr) {
		return false;
	}
	if (this == classz) {
		return true;
	}
	do {
		if (p == NULL) {
			return true;
		}
		p = p->getSuper().lock();
	} while (p != nullptr);
	return false;
}

bool Class::isSubClass(ClassSPtr classSPtr) {
	return isSubClass(classSPtr.get());
}

bool Class::isEnum() const {
	return false;
}

bool Class::isSingular() const {
	return this->singular;
}

ClassLoaderWPtr Class::getClassLoader() const {
	return classLoader;
}

void Class::allocateField(Object_ * o) {
	ClassSPtr c = shared_from_this();
	do {
		for (int i = 0; i < c->getFieldCount(); i++) {
			Field* elem = c->getFieldAt(i);
			elem->alloc(o);
		}
		c = c->getSuper().lock();
	} while (c != nullptr);
}

void Class::freeField(Object_ * o) {
	ClassSPtr c = shared_from_this();
	do {
		for (int i = 0; i < c->getFieldCount(); i++) {
			Field* elem = c->getFieldAt(i);
			elem->free(o);
		}
		c = c->getSuper().lock();
	} while (c != nullptr);
}

void Class::deleteClassLoader(const ClassLoader * const classLoader) {
	this->nullOfClassLoader = true;
}

ClassSPtr Class::dynamicLoading(const std::string& fqcn) {
	ClassSPtr cls = Package::getClass(fqcn);
	if (cls == nullptr) {
		ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
		cls = cll->loadClass(fqcn);
	}
	return cls;
}

Object_ * Class::dynamicNewInstance(const std::string& fqcn, std::vector<Object_*> args) {
	GCLock gcLock = GCLock();
	ClassSPtr cls = dynamicLoading(fqcn);
	Method* cons = cls->findMethod("new", args.size(), false);
	//引数の作成
	//これを行わないとコンストラクタ呼び出しで変数を参照出来ない
	ClassLoaderSPtr cll = cons->getClass().lock()->getClassLoader().lock();
	CodeBlock* cdb = cll->getCodeBlock();
	Block::pushCurrent();
	cdb->enter(false);
	for (int i = 0; i < args.size(); i++) {
		auto name = cons->getParameterAt(i)->getName();
		cdb->writeReference(
			name,
			args.at(i)
		);
	}
	Object_* ret = cons->execute(nullptr, args);
	cdb->exit(true);
	Block::popCurrent();
	return ret;
}

Object_ * Class::dynamicNewInstance(const std::string& fqcn) {
	std::vector<Object_*> args = std::vector<Object_*>();
	Object_* retVal = dynamicNewInstance(fqcn, args);
	return retVal;
}

Object_ * Class::dynamicNewInstance(const std::string& fqcn, Object_ * arg1) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(arg1);
	return dynamicNewInstance(fqcn, args);
}

Object_ * Class::dynamicNewInstance(const std::string& fqcn, Object_ * arg1, Object_ * arg2) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(arg1);
	args.push_back(arg2);
	return dynamicNewInstance(fqcn, args);
}

Object_ * Class::dynamicNewInstance(const std::string& fqcn, Object_ * arg1, Object_ * arg2, Object_ * arg3) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(arg1);
	args.push_back(arg2);
	args.push_back(arg3);
	return dynamicNewInstance(fqcn, args);
}

Object_ * Class::dynamicStaticCall(const std::string& fqcn, std::string methodName, std::vector<Object_*> args) {
	Method* m = dynamicLoading(fqcn)->findMethod(methodName, args.size(), true);
	Object_* ret = m->execute(nullptr, args);
	return ret;
}
//---public method


//private method---
void Class::init(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, bool singular) {
	init(classLoader, name);
	this->super = std::weak_ptr<Class>(super);
	this->singular = singular;
}

void Class::init(ClassLoaderSPtr classLoader, std::string name) {
	this->classLoader = std::weak_ptr<ClassLoader>(classLoader);
	this->name = name;
	this->constructors = std::vector<Constructor_*>();
	this->fields = std::vector<Field*>();
	this->methods = std::vector<Method*>();
	this->nullOfClassLoader = false;
	this->singular = false;
	//classLoader->registerClass();
}
//---private method
