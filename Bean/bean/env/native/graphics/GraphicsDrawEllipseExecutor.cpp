#include "GraphicsDrawEllipseExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserGraphics.h"

//public method---
GraphicsDrawEllipseExecutor::GraphicsDrawEllipseExecutor() {
}

GraphicsDrawEllipseExecutor::~GraphicsDrawEllipseExecutor() {
}

Object_ * const GraphicsDrawEllipseExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* ug = dynamic_cast<UserGraphics*>(invoker);
	Numeric* x = arg_cast(Numeric, 0, "Numeric");
	Numeric* y = arg_cast(Numeric, 1, "Numeric");
	Numeric* w = arg_cast(Numeric, 2, "Numeric");
	Numeric* h = arg_cast(Numeric, 3, "Numeric");
	ug->drawEllipse(x->getCInt(), y->getCInt(), w->getCInt(), h->getCInt());
	return getNull();
}
//---public method
