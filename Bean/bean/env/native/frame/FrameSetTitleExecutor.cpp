#include "FrameSetTitleExecutor.h"
#include "../../../env/user/UserFrame.h"

//public method---
FrameSetTitleExecutor::FrameSetTitleExecutor() {
}

FrameSetTitleExecutor::~FrameSetTitleExecutor() {
}

Object_ * const FrameSetTitleExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* uf = dynamic_cast<UserFrame*>(invoker);
	String* title = arg_cast(String, 0, "String");
	uf->setTitle(*title->getCString());
	return getNull();
}
//---public method