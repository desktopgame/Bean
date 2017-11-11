#include "PaintBoxRemovePaintListenerAtExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxRemovePaintListenerAtExecutor::PaintBoxRemovePaintListenerAtExecutor() {
}

PaintBoxRemovePaintListenerAtExecutor::~PaintBoxRemovePaintListenerAtExecutor() {
}

Object_ * const PaintBoxRemovePaintListenerAtExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserPaintBox* upb = dynamic_cast<UserPaintBox*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	if (Exception::checkIndexRange(index, 0, upb->getPaintListenerCount() - 1)) {
		return getNull();
	}
	upb->removePaintListenerAt(index->getCInt());
	return getNull();
}
//---public method
