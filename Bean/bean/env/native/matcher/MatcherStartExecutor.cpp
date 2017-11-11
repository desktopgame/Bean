#include "MatcherStartExecutor.h"
#include "../../user/UserMatcher.h"

//public method---
MatcherStartExecutor::MatcherStartExecutor() {
}

MatcherStartExecutor::~MatcherStartExecutor() {
}

Object_ * const MatcherStartExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	return getInteger(um->start());
}
//---public method