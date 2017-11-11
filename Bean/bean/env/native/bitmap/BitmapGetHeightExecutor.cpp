#include "BitmapGetHeightExecutor.h"
#include "../../user/UserBitmap.h"


BitmapGetHeightExecutor::BitmapGetHeightExecutor() {
}


BitmapGetHeightExecutor::~BitmapGetHeightExecutor() {
}

Object_ * const BitmapGetHeightExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserBitmap* ubmp = arg_cast(UserBitmap, 0, "Bitmap");
	return getInteger(ubmp->getHeight());
}
