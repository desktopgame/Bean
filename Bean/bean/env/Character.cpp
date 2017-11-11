#include "Character.h"
#include "Boolean.h"
#include "Null.h"
#include "Package.h"
#include "String.h"

//public method---
Character::Character(BChar wc)
	: Object_(nullptr) {
	lazyLoading();
	this->wc = wc;
}

Character::~Character() {
}

wchar_t Character::getCWChar() {
	return wc;
}

char Character::getCChar() {
	return static_cast<char>(wc);
}

Object_ * Character::clone() {
	return new Character(wc);
}

Object_ * Character::add(Object_ * right) {
	//Character + Character
	Character* ch = right->asCharacter();
	if (ch != nullptr) {
		BChar left = wc;
		BChar right = ch->getCWChar();
		BString* str = new BString();
		str->push_back(left);
		str->push_back(right);
		return String::refString(str);
	}
	//Character + String
	String* s = right->asString();
	if (s != nullptr) {
		BChar left = wc;
		BString right = *s->getCWString();
		BString* str = new BString();
		str->push_back(left);
		using WCharIterator = BString::iterator;
		for (WCharIterator it = right.begin(); it != right.end(); it++) {
			str->push_back(*it);
		}
		return String::refString(str);
	}
	return Null::getInstance();
}

Object_ * Character::equals(Object_ * right) {
	Character* ch = right->asCharacter();
	if (ch == nullptr) return Boolean::getFalse();
	return Boolean::get(this->getCChar() == ch->getCChar());
}

bool Character::isPrimitive() {
	return true;
}

void Character::dump() {
	std::cout << "Character(" << getCChar() << "): ";
	dumpAttrLn();
}

Character * Character::asCharacter() {
	return this;
}
//---public method

//protected method---
void Character::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Character"));
}
//---protected method

