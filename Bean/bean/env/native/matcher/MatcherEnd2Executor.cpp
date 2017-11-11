#include "MatcherEnd2Executor.h"
#include "../../Numeric.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherEnd2Executor::MatcherEnd2Executor() {
}

MatcherEnd2Executor::~MatcherEnd2Executor() {
}

Object_ * const MatcherEnd2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	auto index = arg_cast(Numeric, 0, "Numeric");
	return getInteger(um->end(index->getCInt()));
}
//---public method
