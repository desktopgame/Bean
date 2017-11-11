#include "MatcherEndExecutor.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherEndExecutor::MatcherEndExecutor() {
}

MatcherEndExecutor::~MatcherEndExecutor() {
}

Object_ * const MatcherEndExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMatcher* um = dynamic_cast<UserMatcher*>(invoker);
	return getInteger(um->end());
}
//---public method