#include "FramePrintStatusExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserFrame.h"

//public method---
FramePrintStatusExecutor::FramePrintStatusExecutor() {
}

FramePrintStatusExecutor::~FramePrintStatusExecutor() {
}

Object_ * const FramePrintStatusExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserFrame* fr = static_cast<UserFrame*>(invoker);
	Numeric* index = arg_cast(Numeric, 0, "Numeric");
	String* text = arg_cast(String, 1, "String");
	fr->printStatus(index->getCInt(), *text->getCString());
	return getNull();
}
//---public method
