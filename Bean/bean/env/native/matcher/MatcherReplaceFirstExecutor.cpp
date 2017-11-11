#include "MatcherReplaceFirstExecutor.h"
#include "../../String.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherReplaceFirstExecutor::MatcherReplaceFirstExecutor() {
}

MatcherReplaceFirstExecutor::~MatcherReplaceFirstExecutor() {
}

Object_ * const MatcherReplaceFirstExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto str = arg_cast(String, 0, "String");
	auto um = dynamic_cast<UserMatcher*>(invoker);
	return String::allocString(um->replaceFirst(*str->getCString()));
}
//---public method
