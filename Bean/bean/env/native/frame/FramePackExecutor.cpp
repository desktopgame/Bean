#include "FramePackExecutor.h"
#include "../../../env/user/UserFrame.h"

//public method---
FramePackExecutor::FramePackExecutor() {
}

FramePackExecutor::~FramePackExecutor() {
}

Object_ * const FramePackExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* fr = static_cast<UserFrame*>(invoker);
	fr->pack();
	return getNull();
}
//---public method