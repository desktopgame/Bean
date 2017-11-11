#include "GraphicsDrawStringExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/String.h"
#include "../../../env/user/UserGraphics.h"

//public method---
GraphicsDrawStringExecutor::GraphicsDrawStringExecutor() {
}

GraphicsDrawStringExecutor::~GraphicsDrawStringExecutor() {
}

Object_ * const GraphicsDrawStringExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* ug = dynamic_cast<UserGraphics*>(invoker);
	String* s = arg_cast(String, 0, "String");
	Numeric* x = arg_cast(Numeric, 1, "Numeric");
	Numeric* y = arg_cast(Numeric, 2, "Numeric");
	ug->drawString(*s->getCString(), x->getCInt(), y->getCInt());
	return getNull();
}
//---public method
