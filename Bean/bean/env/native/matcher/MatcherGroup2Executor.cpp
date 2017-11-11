#include "MatcherGroup2Executor.h"
#include "../../Numeric.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherGroup2Executor::MatcherGroup2Executor() {
}

MatcherGroup2Executor::~MatcherGroup2Executor() {
}

Object_ * const MatcherGroup2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	auto index = arg_cast(Numeric, 0, "Numeric");
	return String::allocString(um->group(index->getCInt()));
}
//---public method
