#include "MatcherAllExecutor.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherAllExecutor::MatcherAllExecutor() {
}

MatcherAllExecutor::~MatcherAllExecutor() {
}

Object_ * const MatcherAllExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMatcher* um = dynamic_cast<UserMatcher*>(invoker);
	return getBoolean(um->all());
}
//---public method