#include "Object_.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <iterator>
#include "Boolean.h"
#include "Class.h"
#include "ClassLoader.h"
#include "Delegate.h"
#include "DelegateMethod.h"
#include "Exception.h"
#include "Field.h"
#include "Method.h"
#include "Null.h"
#include "Object_.h"
#include "../Debug.h"
#include "gc/Block.h"
#include "gc/GCProgress.cpp"
#include "gc/Heap.h"
#include "user/UserDelegate.h"
#include "../util/Memory.h"
#include "../util/STL.h"
#include "../util/Text.h"
#include "../threads/Thread.h"

//public method---
Object_::Object_(ClassSPtr classz) {
	this->thread = std::weak_ptr<Thread>(Thread::getCurrent());
	this->classz = std::weak_ptr<Class>(classz);
	this->notify = false;
	this->state = createState();
	this->dynFields = std::unordered_map<std::string, Object_*>();
	this->dynMethods = std::unordered_map<std::string, std::vector<UserDelegate*>>();
	Block::getInstance()->recordObject(this);
	Heap::getInstance()->add(this);
}

Object_::~Object_() {
	//弱参照へ通知
	getState()->onDelete(this);
	//フィールドの開放
	ClassSPtr cls = getClass();
	if (cls) {
		cls->freeField(this);
	}
}

Object_ * Object_::add(Object_ * right) {
	return Null::getInstance();
}

Object_ * Object_::sub(Object_ * right) {
	return Null::getInstance();
}

Object_ * Object_::mul(Object_ * right) {
	return Null::getInstance();
}

Object_ * Object_::div(Object_ * right) {
	return Null::getInstance();
}

Object_ * Object_::mod(Object_ * right) {
	return Null::getInstance();
}

Object_ * Object_::equals(Object_ * right) {
	return Boolean::get(this == right);
}

Object_ * Object_::biggest(Object_ * right) {
	return Boolean::getFalse();
}

Object_ * Object_::e_biggest(Object_ * right) {
	return Boolean::getFalse();
}

Object_ * Object_::smallest(Object_ * right) {
	return Boolean::getFalse();
}

Object_ * Object_::e_smallest(Object_ * right) {
	return Boolean::getFalse();
}

void Object_::increment() {
}

void Object_::decrement() {
}

void Object_::setClass(ClassSPtr classz) {
	this->classz = std::weak_ptr<Class>(classz);
	if (classz) {
		classz->allocateField(this);
	}
}

void Object_::chainConstruct(ClassSPtr concrete) {
	//std::cout << "chain " << concrete->getName() << std::endl;
	this->classz = std::weak_ptr<Class>(concrete);
	for (int i = 0; i < concrete->getFieldCount(); i++) {
		Field* elem = concrete->getFieldAt(i);
		elem->alloc(this);
	}
}

ClassSPtr const Object_::getClass() {
	ClassSPtr cls = classz.lock();
	if (cls == nullptr) {
		lazyLoading();
		cls = classz.lock();
	}
	return cls;
}

ObjectStateSPtr Object_::getState() {
	if (!state) {
		this->state = createState();
	}
	return this->state;
}

ThreadWPtr Object_::getGenThread() const {
	return this->thread;
}

bool Object_::isPrimitive() {
	return false;
}

void Object_::markTree() {
	if (getState()->isMarked()) {
		return;
	}
	markTreeImpl();
}

void Object_::dump() {
	std::cout << "Object: ";
	dumpAttrLn();
}

Object_ * Object_::data() {
	return isPrimitive() ? clone() : this;
}

void Object_::defineDynField(const std::string & name, Object_ * value) {
	if (Text::isWord(name)) {
		Exception::throw_e_simple("api.exc.ArgumentException", "予約語で動的フィールドは定義出来ません:" + name);
		return;
	}
	dynFields.insert_or_assign(name, value);
}

void Object_::defineDynMethod(const std::string & name, UserDelegate * value) {
	if (Text::isWord(name)) {
		Exception::throw_e_simple("api.exc.ArgumentException", "予約語で動的メソッドは定義出来ません:" + name);
		return;
	}
	//一つの名前に対して紐づけられた
	//シグネチャの異なるメソッドの一覧を設定
	if (dynMethods.count(name) == 0) {
		dynMethods.insert_or_assign(name, std::vector<UserDelegate*>());
	}
	//同じメソッドがあったら上書き
	auto methods = dynMethods.at(name);
	for (int i = 0; i < methods.size(); i++) {
		auto method = methods.at(i);
		//既に同じメソッドが登録されてる
		if (method->getDelegate()->requestArgumentCount() ==
			value->getDelegate()->requestArgumentCount()) {
			methods.erase(methods.begin() + i);
			break;
		}
	}
	dynMethods.at(name).push_back(value);
}

Object_ * Object_::findDynField(const std::string & name) {
	if (this->dynFields.count(name) != 0) {
		return dynFields.at(name);
	}
	return nullptr;
}

UserDelegate * Object_::findDynMethod(const std::string & name, int argc) {
	if (dynMethods.count(name) == 0) {
		return nullptr;
	}
	auto methods = dynMethods.at(name);
	for (auto method : methods) {
		if (method->getDelegate()->requestArgumentCount() ==
			argc) {
			return method;
		}
	}
	return nullptr;
}

std::unordered_map<std::string, Object_*> Object_::getDynFields() const {
	return this->dynFields;
}

Object_ * const Object_::execute(std::string name) {
	std::vector<Object_*> args = std::vector<Object_*>();
	Object_* retVal = execute(name, args);
	return retVal;
}

Object_ * const Object_::execute(std::string name, Object_ * arg1) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(arg1);
	Object_* retVal = execute(name, args);
	return retVal;
}

Object_ * const Object_::execute(std::string name, std::vector<Object_*> args) {
	//動的メソッドを検索
	UserDelegate* ud = findDynMethod(name, args.size());
	Method* m = nullptr;
	if (ud != nullptr) {
		m = new DelegateMethod(this, name, ud);
	}
	//見つからなければメソッドを検索
	if (m == nullptr) {
		m = getClass()->findMethod(name, args.size(), false);
	}
	//それでも見つからないので諦める
	if (m == nullptr) {
		return nullptr;
	}
	Object_* self = newExecutor();
	ClassLoaderSPtr cll = getClass()->getClassLoader().lock();
	cll->lockInstance(self);
	Block::pushCurrent();
	Object_* retVal = m->execute(self, args);
	Block::popCurrent();
	cll->unlockInstance();
	deleteExecutor(self);
	//使い終わったら削除
	if (ud != nullptr) {
		delete m;
	}
	return retVal;
}

bool Object_::die() {
	ClassSPtr cls = getClass();
	deleteSelf();
	return true;
}

bool Object_::isSingleton() {
	return false;
}

Boolean * Object_::asBoolean() {
	return nullptr;
}

Numeric * Object_::asNumeric() {
	return nullptr;
}

Character * Object_::asCharacter() {
	return nullptr;
}

String * Object_::asString() {
	return nullptr;
}

UserDelegate * Object_::asUserDelegate() {
	return nullptr;
}

UserObject * Object_::asUserObject() {
	return nullptr;
}

UserArray * Object_::asUserArray() {
	return nullptr;
}

UserThread * Object_::asUserThread() {
	return nullptr;
}

UserComponent * Object_::asUserComponent() {
	return nullptr;
}

std::vector<Object_*> Object_::getVirtualField() {
	return getDynamicMembers();
}
//---public method


//protected method---
void Object_::lazyLoading() {
}

ObjectStateSPtr Object_::createState() {
	return std::make_shared<ObjectState>(this);
}

void Object_::dumpAttrLn() {
	auto state = getState();
	ClassSPtr cls = getClass();
	std::string clsName = "none name";
	if (cls) {
		clsName = cls->getName();
	}
	std::cout <<
		"name=" << clsName <<
		" mark=" << state->isMarked() <<
		" rank=" << state->getRank() <<
		" sc=" << state->getStrongReferenceCount() <<
		" progress=" << state->getProgressStr() <<
	std::endl;
}

void Object_::deleteSelf() {
	//Heap::deleteItem(this);
	//Heap::getInstance()->remove(this);
	delete this;
}

std::vector<Object_*> Object_::concatDynamicMembers(std::vector<Object_*> a) {
	std::vector<Object_*> copy = a;
	std::vector<Object_*> content = getDynamicMembers();
	std::copy(content.begin(), content.end(), std::back_inserter(copy));
	return copy;
}

std::vector<Object_*> Object_::getDynamicMembers() {
	auto ret = std::vector<Object_*>();
	for (auto elem : this->dynFields) {
		ret.push_back(elem.second);
	}
	for (auto pair : this->dynMethods) {
		auto methods = dynMethods.at(pair.first);
		for (auto method : methods) {
			ret.push_back(method);
		}
	}
	return ret;
}
//---protected method


//private method---
void Object_::markTreeImpl() {
	getState()->setMarked(true);
	ClassWPtr clsW = getClass();
	ClassSPtr clsS = clsW.lock();
	if (clsS == nullptr) return;
	do {
		std::vector<Field*> fields = clsS->getFields();
		for (Field* field : fields) {
			if (field->getModifier().isStatic()) continue;
			Object_* fieldVal = field->getValue(this);
			fieldVal->markTree();
		}
		clsS = clsS->getSuper().lock();
	} while (clsS != nullptr);
	//仮想フィールドもマーク
	for (Object_* obj : getVirtualField()) {
		//FIXME:？
		if (obj == NULL) continue;
		obj->markTree();
	}
}

Object_ * Object_::newExecutor() {
//	return GCSystem::getInstance()->lookup(this);
//	return nullptr;
	Object_* ret = this;
	return ret;
}

void Object_::deleteExecutor(Object_ * ref) {
	//ref->deleteOnlyRef();
}
//---private method
