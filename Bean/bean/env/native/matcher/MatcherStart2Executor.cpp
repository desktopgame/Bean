#include "MatcherStart2Executor.h"
#include "../../Numeric.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherStart2Executor::MatcherStart2Executor() {
}

MatcherStart2Executor::~MatcherStart2Executor() {
}

Object_ * const MatcherStart2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	auto index = arg_cast(Numeric, 0, "Numeric");
	return getInteger(um->start(index->getCInt()));
}
//---public method
