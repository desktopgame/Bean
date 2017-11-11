#include "MatcherFindExecutor.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherFindExecutor::MatcherFindExecutor() {
}

MatcherFindExecutor::~MatcherFindExecutor() {
}

Object_ * const MatcherFindExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMatcher* um = dynamic_cast<UserMatcher*>(invoker);
	return getBoolean(um->find());
}
//---public method