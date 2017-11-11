#include "MatcherGroupCountExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherGroupCountExecutor::MatcherGroupCountExecutor() {
}

MatcherGroupCountExecutor::~MatcherGroupCountExecutor() {
}

Object_ * const MatcherGroupCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	return getInteger(um->groupCount());
}
//---public method
