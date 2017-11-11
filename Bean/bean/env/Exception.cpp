#include "Exception.h"
#include "Class.h"
#include "ClassLoader.h"
#include "Method.h"
#include "Null.h"
#include "Numeric.h"
#include "String.h"
#include "gc/Block.h"
#include "../threads/Thread.h"


//public method---
Object_ * Exception::new_e(const std::string & className, std::vector<Object_*> args) {
	return Class::dynamicNewInstance(className, args);
}

Object_ * Exception::new_e_simple(const std::string & className, const std::string & msg) {
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(Null::getInstance());
	args.push_back(String::allocString(msg));
	return new_e(className, args);
}

void Exception::throw_e(Object_ * ref) {
	Thread::getCurrent()->setException(ref);
}

void Exception::throw_e(std::string className, std::vector<Object_*> args) {
	Block::pushCurrent();
	throw_e(Class::dynamicNewInstance(className, args));
	Block::popCurrent();
}

void Exception::throw_e_zero_args(std::string className) {
	std::vector<Object_*> args = std::vector<Object_*>();
	throw_e(className, args);
}

void Exception::throw_e_simple(std::string className, std::string msg) {
	throw_e(new_e_simple(className, msg));
}

void Exception::throw_e_wrap(std::string className, std::exception e) {
	throw_e_simple(className, e.what());
}

bool Exception::checkIndexNegative(Numeric * v) {
	int cIndex = v->getCInt();
	if (cIndex < 0) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "負の値は使用出来ません。:" + std::to_string(cIndex));
		return true;
	}
	return false;
}

bool Exception::checkIndexRange(Numeric * v, int min, int max) {
	int cIndex = v->getCInt();
	if (cIndex < min || cIndex > max) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "範囲外です。:" + std::to_string(cIndex));
		return true;
	}
	return false;
}

bool Exception::checkColor(Numeric * r, Numeric * g, Numeric * b) {
	int cR = r->getCInt();
	int cG = g->getCInt();
	int cB = b->getCInt();
	if ((cR < 0 || cR > 255)) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "(RED)0~255 の範囲外です。:" + std::to_string(cR));
		return true;
	}
	if ((cG < 0 || cG > 255)) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "(GREEN)0~255 の範囲外です。:" + std::to_string(cG));
		return true;
	}
	if ((cB < 0 || cB > 255)) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "(BLUE)0~255 の範囲外です。:" + std::to_string(cB));
		return true;
	}
	return false;
}

bool Exception::checkColor(Numeric * r, Numeric * g, Numeric * b, Numeric * a) {
	if (checkColor(r, g, b)) {
		return true;
	}
	int cA = a->getCInt();
	if ((cA < 0 || cA > 255)) {
		Exception::throw_e_simple("api.exc.OutOfRangeError", "(ALPHA)0~255 の範囲外です。:" + std::to_string(cA));
		return true;
	}
	return false;
}
//---public method


//private method---
Exception::Exception() {
}

Exception::~Exception() {
}
//---private method
