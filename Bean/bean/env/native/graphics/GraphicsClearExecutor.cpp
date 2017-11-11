#include "GraphicsClearExecutor.h"
#include "../../../env/user/UserGraphics.h"

//public method---
GraphicsClearExecutor::GraphicsClearExecutor() {
}

GraphicsClearExecutor::~GraphicsClearExecutor() {
}

Object_ * const GraphicsClearExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserGraphics* ug = dynamic_cast<UserGraphics*>(invoker);
	ug->clear();
	return getNull();
}
//---public method