#include "GraphicsDrawBitmapExecutor.h"
#include "../../Numeric.h"
#include "../../user/UserBitmap.h"
#include "../../user/UserGraphics.h"

//public method---
GraphicsDrawBitmapExecutor::GraphicsDrawBitmapExecutor() {
}

GraphicsDrawBitmapExecutor::~GraphicsDrawBitmapExecutor() {
}

Object_ * const GraphicsDrawBitmapExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* g = dynamic_cast<UserGraphics*>(invoker);
	UserBitmap* ubmp = arg_cast(UserBitmap, 0, "Bitmap");
	Numeric* x = arg_cast(Numeric, 1, "Numeric");
	Numeric* y = arg_cast(Numeric, 2, "Numeric");
	g->drawBitmap(ubmp, x->getCInt(), y->getCInt());
	return getNull();
}
//---public method
