#include "ColorNewExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserColor.h"

//public method---
ColorNewExecutor::ColorNewExecutor() {
}

ColorNewExecutor::~ColorNewExecutor() {
}

Object_ * const ColorNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ColorNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	Numeric* r = arg_cast(Numeric, 0, "Numeric");
	Numeric* g = arg_cast(Numeric, 1, "Numeric");
	Numeric* b = arg_cast(Numeric, 2, "Numeric");
	if (Exception::checkColor(r, g, b)) {
		return getNull();
	}
	return new UserColor(
		r->getCFloat(),
		g->getCFloat(),
		b->getCFloat()
	);
}
//---public method
