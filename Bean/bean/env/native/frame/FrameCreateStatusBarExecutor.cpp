#include "FrameCreateStatusBarExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserFrame.h"

//public method---
FrameCreateStatusBarExecutor::FrameCreateStatusBarExecutor() {
}

FrameCreateStatusBarExecutor::~FrameCreateStatusBarExecutor() {
}

Object_ * const FrameCreateStatusBarExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* fr = static_cast<UserFrame*>(invoker);
	Numeric* length = arg_cast(Numeric, 0, "Numeric");
	fr->createStatusBar(length->getCInt());
	return getNull();
}
//---public method
