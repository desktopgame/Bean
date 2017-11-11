#include "BitmapGetWidthExecutor.h"
#include "../../user/UserBitmap.h"

BitmapGetWidthExecutor::BitmapGetWidthExecutor() {
}

BitmapGetWidthExecutor::~BitmapGetWidthExecutor() {
}

Object_ * const BitmapGetWidthExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserBitmap* ubmp = arg_cast(UserBitmap, 0, "Bitmap");
	return getInteger(ubmp->getWidth());
}
