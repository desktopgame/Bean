#include "MatcherGroupExecutor.h"
#include "../../String.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherGroupExecutor::MatcherGroupExecutor() {
}

MatcherGroupExecutor::~MatcherGroupExecutor() {
}

Object_ * const MatcherGroupExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserMatcher* um = dynamic_cast<UserMatcher*>(invoker);
	return String::allocString(um->group());
}
//---public method
