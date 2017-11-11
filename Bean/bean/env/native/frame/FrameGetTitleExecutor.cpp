#include "FrameGetTitleExecutor.h"
#include "../../../env/user/UserFrame.h"

//public method---
FrameGetTitleExecutor::FrameGetTitleExecutor() {
}

FrameGetTitleExecutor::~FrameGetTitleExecutor() {
}

Object_ * const FrameGetTitleExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* fr = dynamic_cast<UserFrame*>(invoker);
	std::string title = fr->getTitle();
	return String::allocString(title);
}
//---public method