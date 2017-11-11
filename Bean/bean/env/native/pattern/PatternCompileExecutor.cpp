#include "PatternCompileExecutor.h"
#include <regex>
#include "../../Object_.h"
#include "../../user/UserPattern.h"
//public method---
PatternCompileExecutor::PatternCompileExecutor() {
}

PatternCompileExecutor::~PatternCompileExecutor() {
}

Object_ * const PatternCompileExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* tex = arg_cast(String, 0, "String");
	UserPattern* uptn = new UserPattern();
	try {
		uptn->compile(*tex->getCString());
	} catch (std::regex_error e) {
		Exception::throw_e_simple("api.exc.RegexException", (*tex->getCString()) + "は 有効なパターンではありません。");
		return getNull();
	}
	return uptn;
}
//---public method
