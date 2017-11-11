#include "FrameMainLoopExecutor.h"
#include <iostream>
#include <wx/wx.h>
#include "../../Object_.h"
#include "../../../Debug.h"
#include "../../user/UserFrame.h"

//public method---
FrameMainLoopExecutor::FrameMainLoopExecutor() {
}

FrameMainLoopExecutor::~FrameMainLoopExecutor() {
}

Object_ * const FrameMainLoopExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* ox = invoker;
	UserFrame* uframe = dynamic_cast<UserFrame*>(invoker);
	uframe->mainLoop();
	return getNull();
}
//---public method
