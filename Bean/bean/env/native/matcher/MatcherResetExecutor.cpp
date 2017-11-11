#include "MatcherResetExecutor.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherResetExecutor::MatcherResetExecutor() {
}

MatcherResetExecutor::~MatcherResetExecutor() {
}

Object_ * const MatcherResetExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto um = dynamic_cast<UserMatcher*>(invoker);
	um->reset();
	return getNull();
}
//---public method