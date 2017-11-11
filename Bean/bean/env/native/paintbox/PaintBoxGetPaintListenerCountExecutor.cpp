#include "PaintBoxGetPaintListenerCountExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxGetPaintListenerCountExecutor::PaintBoxGetPaintListenerCountExecutor() {
}

PaintBoxGetPaintListenerCountExecutor::~PaintBoxGetPaintListenerCountExecutor() {
}

Object_ * const PaintBoxGetPaintListenerCountExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserPaintBox* upb = dynamic_cast<UserPaintBox*>(invoker);
	int i = upb->getPaintListenerCount();
	return Numeric::newInteger(i);
}
//---public methods
