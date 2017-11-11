#include "GraphicsDrawDotExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserGraphics.h"

//public method---
GraphicsDrawDotExecutor::GraphicsDrawDotExecutor() {
}

GraphicsDrawDotExecutor::~GraphicsDrawDotExecutor() {
}
Object_ * const GraphicsDrawDotExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* ug = dynamic_cast<UserGraphics*>(invoker);
	Numeric* x = arg_cast(Numeric, 0, "Numeric");
	Numeric* y = arg_cast(Numeric, 1, "Numeric");
	ug->drawDot(x->getCInt(), y->getCInt());
	return getNull();
}
//---public method
