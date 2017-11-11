#include "MatcherReset2Executor.h"
#include "../../String.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherReset2Executor::MatcherReset2Executor() {
}

MatcherReset2Executor::~MatcherReset2Executor() {
}

Object_ * const MatcherReset2Executor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto str = arg_cast(String, 0, "String");
	auto um = dynamic_cast<UserMatcher*>(invoker);
	um->reset(*str->getCString());
	return getNull();
}
//---public method
