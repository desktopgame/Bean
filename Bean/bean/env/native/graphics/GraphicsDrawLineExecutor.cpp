#include "GraphicsDrawLineExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserGraphics.h"

//public method---
GraphicsDrawLineExecutor::GraphicsDrawLineExecutor() {
}

GraphicsDrawLineExecutor::~GraphicsDrawLineExecutor() {
}
Object_ * const GraphicsDrawLineExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* ug = dynamic_cast<UserGraphics*>(invoker);
	Numeric* x1 = arg_cast(Numeric, 0, "Numeric");
	Numeric* y1 = arg_cast(Numeric, 1, "Numeric");
	Numeric* x2 = arg_cast(Numeric, 2, "Numeric");
	Numeric* y2 = arg_cast(Numeric, 3, "Numeric");
//	ug->drawEllipse(x->getCInt(), y->getCInt(), w->getCInt(), h->getCInt());
	ug->drawLine(x1->getCInt(), y1->getCInt(), x2->getCInt(), y2->getCInt());
	return getNull();
}
//---public method
