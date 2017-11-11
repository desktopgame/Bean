#include "ColorNewAExecutor.h"
#include "../../../env/Numeric.h"
#include "../../../env/user/UserColor.h"

//public method---
ColorNewAExecutor::ColorNewAExecutor() {
}

ColorNewAExecutor::~ColorNewAExecutor() {
}

Object_ * const ColorNewAExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * ColorNewAExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	Numeric* r = arg_cast(Numeric, 0, "Numeric");
	Numeric* g = arg_cast(Numeric, 1, "Numeric");
	Numeric* b = arg_cast(Numeric, 2, "Numeric");
	Numeric* a = arg_cast(Numeric, 3, "Numeric");
	if (Exception::checkColor(r, g, b, a)) {
		return getNull();
	}
	return new UserColor(
		r->getCFloat(),
		g->getCFloat(),
		b->getCFloat(),
		a->getCFloat()
	);
}
//---public method
