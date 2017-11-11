#include "String.h"
#include <iostream>
#include <unicode/unistr.h>
#include "Boolean.h"
#include "Character.h"
#include "Null.h"
#include "Numeric.h"
#include "Package.h"
#include "gc/Heap.h"
#include "../util/Memory.h"

//public method---
std::string* const String::getCString() {
	if (parent != nullptr) {
		return parent->getCString();
	}
#if defined(BTEXT_MULTI)
	return getBString();
#elif defined(BTEXT_WIDE)
	//this->string = std::string(wstring->begin(), wstring->end());
	std::wstring temp = std::wstring(wstring->begin(), wstring->end());
	this->string = Text::wideToMulti(temp);
	this->initCString = true;
	return &string;
#endif // BTEXT_MULTI
}

BString* const String::getCWString()  const {
	if (parent != nullptr) {
		return parent->getCWString();
	}
	return wstring;
}

icu::UnicodeString* const String::getUString() {
	if (parent != nullptr) {
		return parent->getUString();
	}
	if (ustring == nullptr) {
		this->ustring = new icu::UnicodeString(string.c_str(), encoding.c_str());
	}
	return ustring;
}

String * String::encode(const std::string& encoding) {
	std::string buff;
	getUString()->toUTF8String(buff);

	BString* clone = new BString(buff.begin(), buff.end());
	String* str = new String(clone, encoding);
	str->newWString = true;
	return str;
}

bool String::die() {
	if (count == 0) {
		if (parent != nullptr) {
			if (--parent->count == 0) {
				delete parent;
			}
			deleteSelf();
			return true;
		}
		deleteSelf();
		return true;
	}
	if (count > 0) {
		count--;
		return false;
	}
	deleteSelf();
	return true;
}

void String::dump() {
	std::cout << "String: " << getCString() << std::endl;
}

String * String::asString() {
	return this;
}

String * const String::ownedString(BString * fieldPtr) {
#if defined(BTEXT_MULTI)
	return new String(fieldPtr);
#elif defined(BTEXT_WIDE)
	String* ret = new String(fieldPtr);
	ret->string = Text::wideToMulti(*fieldPtr);
	ret->initCString = true;
	return ret;
#endif
}

String * const String::allocString(const std::string& str) {
#if defined(BTEXT_MULTI)
	String* ret = new String(new BString(str.begin(), str.end()));
#elif defined(BTEXT_WIDE)
	String* ret = new String(new std::wstring(Text::multiToWide(str)));
	//ret->initCString = false;
	//ret->string = std::string();
#endif
	ret->newWString = true;
	return ret;
}

String * const String::refString(BString * str) {
	String* ret = new String(str);
	ret->newWString = true;
	return ret;
}

BString * const String::getBString() {
	return this->wstring;
}

Numeric* const String::indexOf(String * find) {
	int offs = getUString()->indexOf(*find->getUString());
	return Numeric::newInteger(offs);
}

Numeric* const String::indexOf(String * find, int pos) {
	int offs = getUString()->indexOf(*find->getUString(), pos);
	return Numeric::newInteger(offs);
}

Numeric* const String::lastIndexOf(String * find) {
	int offs = getUString()->lastIndexOf(*find->getUString());
	return Numeric::newInteger(offs);
}

Numeric* const String::lastIndexOf(String * find, int pos) {
	int offs = getUString()->lastIndexOf(*find->getUString(), pos);
	return Numeric::newInteger(offs);
}

Numeric * const String::length() {
	return Numeric::newInteger(getUString()->length());
}

String * const String::substring(int offset, int len) {
	icu::UnicodeString ustr = getUString()->tempSubString(offset, len);
	std::string s;
	ustr.toUTF8String(s);
	return allocString(s);
}

String * const String::insert(int offset, String * str) {
	icu::UnicodeString ustr = getUString()->insert(offset, *str->getUString());
	std::string s;
	ustr.toUTF8String(s);
	return allocString(s);
}

String * const String::remove(int offset, int len) {
	icu::UnicodeString ustr = getUString()->remove(offset, len);
	std::string s;
	ustr.toUTF8String(s);
	return allocString(s);
}

Boolean * const String::startsWith(String * head) {
	bool b = getUString()->startsWith(*head->getUString());
	return Boolean::get(b);
}

Boolean * const String::endsWith(String * foot) {
	bool b = getUString()->endsWith(*foot->getUString());
	return Boolean::get(b);
}

Object_ * String::clone() {
	return allocString(*getCString());
}

Object_ * String::add(Object_ * right) {
	String* other = right->asString();
	if (other == nullptr) {
		Heap* heap = Heap::getInstance();
		heap->lock();
		Object_* ref = right->execute("toString");
		heap->unlock();
		Object_* obj = ref;
		other = obj->asString();
	}
	String* retStr = new String(
		new BString(
			*getCWString() + 
			*other->getCWString()
		)
	);
	retStr->newWString = true;
	return retStr;
}

Object_ * String::equals(Object_ * right) {
	String* sRight = right->asString();
	Object_* retVal = nullptr;
	if (sRight == nullptr || sRight == NULL) {
		retVal = Boolean::get(false);
	} else {
		retVal = Boolean::get(string == sRight->string);
	}
	return retVal;
}
//---public method

//protected method---
void String::lazyLoading() {
	setClass(Package::getClassOrLoad("api.String"));
}
//---protected method

//private method---
String::String(BString * wstring, const std::string& encoding)
	: Object_(nullptr) {
	this->parent = nullptr;
	this->wstring = wstring;
	//this->string = new std::string(wstring->begin(), wstring->end());
	this->string = std::string(wstring->begin(), wstring->end());
	this->encoding = encoding;
	this->ustring = nullptr;
	this->count = 0;
	this->newWString = false;
	init();
}

String::String(BString* wstring)
	: String(wstring, "utf-8") {

}

String::String(String* parent)
	: Object_(nullptr) {
	this->parent = parent;
	this->count = 0;
	this->newWString = false;
	this->encoding = parent->encoding;
	init();
}

String::~String() {
	if (newWString) {
		delete wstring;
	}
	delete ustring;
}

void String::init() {
	//lazyLoading();
	//	std::string buff = std::string();
	//	getUString().toUTF8String();
}
//---private method
