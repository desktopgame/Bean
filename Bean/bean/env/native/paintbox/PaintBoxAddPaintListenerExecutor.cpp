#include "PaintBoxAddPaintListenerExecutor.h"
#include "../../../env/user/UserDelegate.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxAddPaintListenerExecutor::PaintBoxAddPaintListenerExecutor() {
}

PaintBoxAddPaintListenerExecutor::~PaintBoxAddPaintListenerExecutor() {
}

Object_ * const PaintBoxAddPaintListenerExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserPaintBox* upb = dynamic_cast<UserPaintBox*>(invoker);
	UserDelegate* dlg = arg_cast(UserDelegate, 0, "Delegate");
	upb->addPaintListener(dlg);
	return getNull();
}
//---public method