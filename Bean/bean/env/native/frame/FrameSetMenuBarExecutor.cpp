#include "FrameSetMenuBarExecutor.h"
#include "../../../env/user/UserFrame.h"
#include "../../../env/user/UserMenuBar.h"

//public method---
FrameSetMenuBarExecutor::FrameSetMenuBarExecutor() {
}

FrameSetMenuBarExecutor::~FrameSetMenuBarExecutor() {
}

Object_ * const FrameSetMenuBarExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* fr = static_cast<UserFrame*>(invoker);
	UserMenuBar* menubar = arg_cast(UserMenuBar, 0, "MenuBar");
	fr->setMenuBar(menubar->getWXMenuBar());
	return getNull();
}
//---public method