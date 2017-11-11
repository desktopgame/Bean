#include "PaintBoxStartExecutor.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxStartExecutor::PaintBoxStartExecutor() {
}

PaintBoxStartExecutor::~PaintBoxStartExecutor() {
}

Object_ * const PaintBoxStartExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserPaintBox* upb = dynamic_cast<UserPaintBox*>(invoker);
	upb->start();
	return getNull();
}
//---public method