#include "Field.h"
#include <assert.h>
#include "Class.h"
#include "Class.h"
#include "ClassLoader.h"
#include "IncludeManager.h"
#include "Null.h"
#include "Numeric.h"
#include "Object_.h"
#include "../Debug.h"
#include "../Debug.h"
#include "gc/GCLock.h"
#include "gc/Heap.h"
#include "../ast/ASTFactor.h"

std::vector<Field*> Field::staticFields = std::vector<Field*>();
std::vector<Field*> Field::allFields = std::vector<Field*>();
using Iterator = std::unordered_map<Object_*, Object_*>::iterator;

//public method---
Field::Field(ClassSPtr classz, Modifier modifier, const std::string& name)
	: Member(classz, modifier, name) {
	this->map = std::unordered_map<Object_*, Object_*>();
	this->defaultValue = std::weak_ptr<ASTFactor>();
	this->bInvalid = false;
	Field::allFields.push_back(this);
	//staticならGCのときにマークするため保持しとく
	if (modifier.isStatic()) {
		Field::staticFields.push_back(this);
	}
}

Field::~Field() {
	//全フィールドの一覧からこれを削除
	for (int i = 0; i < Field::allFields.size(); i++) {
		Field* field = Field::allFields.at(i);
		if (field == this) {
			Field::allFields.erase(Field::allFields.begin() + i);
			break;
		}
	}
	//静的フィールドの一覧からこれを削除
	for (int i = 0; i < Field::staticFields.size(); i++) {
		Field* field = Field::staticFields.at(i);
		if (field == this) {
			Field::staticFields.erase(Field::staticFields.begin() + i);
			break;
		}
	}
	map.clear();
}

void Field::alloc(Object_ * obj) {
	if (getModifier().isStatic()) return;
	GCLock gcLock = GCLock();
	//assert(map.count(obj) == 0);
	Object_* ref = nullptr;
	//フィールド宣言時の値を適用する
	std::shared_ptr<ASTFactor> shDefaultValue = defaultValue.lock();
	if (ref == nullptr && shDefaultValue != nullptr) {
		ClassWPtr classWPtr = getClass();
		ClassSPtr classSPtr = classWPtr.lock();
		ClassLoaderWPtr cll = classSPtr->getClassLoader();
		ClassLoader::pushCurrentClassLoader(cll.lock());
		ref = shDefaultValue->eval();
		ClassLoader::popCurrentClassLoader();
	}
	//フィールド宣言時にデフォルト値が定義されていないならnull
	if (ref == nullptr) {
		ref = Null::getInstance();
	}
	Heap::getInstance()->writeBarrier(obj, ref);
//	ref->getState()->setProgress(GCProgress::SearchNow);
	map.insert_or_assign(obj, ref);
}

void Field::free(Object_ * obj) {
	if (getModifier().isStatic()) return;
	Object_* ref = map.at(obj);
	map.erase(obj);
	//delete ref;
}

void Field::setValue(Object_* obj, Object_ * value) {
	if (getModifier().isStatic()) {
		this->staticRef = value;
		Heap::getInstance()->writeBarrier(value);
		return;
	}
	Heap::getInstance()->writeBarrier(obj, value);
	if (map.count(obj) != 0) {
		map.erase(obj);
	}
	map.insert_or_assign(obj, value);
	Numeric* num = dynamic_cast<Numeric*>(value);
}

Object_ * const Field::getValue(Object_* obj) {
	staticInit();
	if (getModifier().isStatic()) {
		return staticRef;
	}
	if (obj == nullptr || map.count(obj) == 0) {
		return nullptr;
	}
	auto val = map.at(obj);
	return val;
}

void Field::setDefaultValue(std::shared_ptr<ASTFactor> defaultValue) {
	this->defaultValue = defaultValue;
}

std::shared_ptr<ASTFactor> Field::getDefaultValue() const {
	return this->defaultValue.lock();
}

bool Field::isInvalid() const {
	return this->bInvalid;
}

void Field::eachAllValues(std::function<void(Object_*, Object_*)> f) {
	auto itr = map.begin();
	for (; itr != map.end(); itr++) {
		f(itr->first, itr->second);
	}
}

void Field::eachAllFields(std::function<void(Field*)> f) {
	for (Field* field : Field::allFields) {
		f(field);
	}
}

void Field::markStatics() {
	eachStatics([](Field* f) {
		Object_* obj = f->getValue(nullptr);
		obj->markTree();
	});
}

void Field::paintSearchNow() {
	eachStatics([](Field* f) {
		Object_* obj = f->getValue(nullptr);
		obj->getState()->setProgress(GCProgress::SearchNow);
	});
}

void Field::invalidateStatics() {
	for (Field* field : Field::staticFields) {
		field->invalidate();
	}
	Field::staticFields.clear();
}

std::string Field::getLocation() {
	return getClass().lock()->getName() + "#" + getName();
}
//---public method

//private method---
void Field::staticInit() {
	if (!getModifier().isStatic()) {
		return;
	}
	//既に静的フィールドが初期化されている
	if (staticRef != nullptr) {
		return;
	}
	//静的だがデフォルト値がない
	std::shared_ptr<ASTFactor> shDefaultValue = defaultValue.lock();
	if (getModifier().isStatic() &&
		shDefaultValue == nullptr) {
		staticRef = Null::getInstance();
	}
	if (shDefaultValue == nullptr) {
		return;
	}
	Heap::getInstance()->lock();
	std::string name = getName();
	ClassWPtr classWPtr = getClass();
	ClassSPtr classSPtr = classWPtr.lock();
	ClassLoaderWPtr cll = classSPtr->getClassLoader();
	ClassLoader::pushCurrentClassLoader(cll.lock());
	this->staticRef = defaultValue.lock()->eval();
	ClassLoader::popCurrentClassLoader();
	Heap::getInstance()->unlock();
}

void Field::invalidate() {
	if (staticRef != nullptr) {
		staticRef->getState()->setMarked(false);
	}
	this->bInvalid = false;
	this->staticRef = nullptr;
	this->defaultValue = std::weak_ptr<ASTFactor>();
}

void Field::eachStatics(std::function<void(Field*)> f) {
	for (Field* field : Field::staticFields) {
		if (!field->getModifier().isStatic()) {
			continue;
		}
		Object_* staticR = field->getValue(nullptr);
		if (staticR != NULL &&
			staticR != nullptr) {
			f(field);
		}
	}
}
//---private method
