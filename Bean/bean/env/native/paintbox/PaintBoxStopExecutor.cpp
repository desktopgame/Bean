#include "PaintBoxStopExecutor.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxStopExecutor::PaintBoxStopExecutor() {
}

PaintBoxStopExecutor::~PaintBoxStopExecutor() {
}

Object_ * const PaintBoxStopExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserPaintBox* upb = dynamic_cast<UserPaintBox*>(invoker);
	upb->stop();
	return getNull();
}
//---public method