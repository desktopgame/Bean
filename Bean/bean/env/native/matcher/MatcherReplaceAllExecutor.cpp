#include "MatcherReplaceAllExecutor.h"
#include "../../String.h"
#include "../../user/UserMatcher.h"
//public method---
MatcherReplaceAllExecutor::MatcherReplaceAllExecutor() {
}

MatcherReplaceAllExecutor::~MatcherReplaceAllExecutor() {
}

Object_ * const MatcherReplaceAllExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	auto str = arg_cast(String, 0, "String");
	auto um = dynamic_cast<UserMatcher*>(invoker);
	auto ret = um->replaceAll(*str->getCString());
	return String::allocString(ret);
}
//---public method
