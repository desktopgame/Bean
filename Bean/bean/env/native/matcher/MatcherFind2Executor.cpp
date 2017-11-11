#include "MatcherFind2Executor.h"
#include "../../Numeric.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherFind2Executor::MatcherFind2Executor() {
}

MatcherFind2Executor::~MatcherFind2Executor() {
}

Object_ * const MatcherFind2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	auto ind = arg_cast(Numeric, 0, "Numeric");
	return getBoolean(um->find(ind->getCInt()));
}
//---public method
