#include "ObjectOpAddExecutor.h"
#include "../../Object_.h"
#include "../../String.h"

//public method---
ObjectOpAddExecutor::ObjectOpAddExecutor() {
}

ObjectOpAddExecutor::~ObjectOpAddExecutor() {
}

Object_ * const ObjectOpAddExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* self = invoker;
	Object_* right = args.at(0);
	//FIXME:String‚ª•Ô‚Á‚Ä‚­‚é‚Ü‚ÅtoString‚·‚é
	std::string leftStr = *self->execute("toString")->asString()->getCString();
	std::string rightStr = *right->execute("toString")->asString()->getCString();
	return String::allocString(leftStr + rightStr);
}
//---public method