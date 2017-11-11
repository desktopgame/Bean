#include "PatternMatcherExecutor.h"
#include "../../user/UserMatcher.h"
#include "../../user/UserPattern.h"
//public method---
PatternMatcherExecutor::PatternMatcherExecutor() {
}

PatternMatcherExecutor::~PatternMatcherExecutor() {
}

Object_ * const PatternMatcherExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* source = arg_cast(String, 0, "String");
	UserPattern* ptn = dynamic_cast<UserPattern*>(invoker);
	return new UserMatcher(*source->getCString(), ptn);
}
//---public method
