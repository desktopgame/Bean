#include "PaintBoxNewExecutor.h"
#include "../../../wxgui/PaintBox.h"
#include "../../../env/user/UserContainer.h"
#include "../../../env/user/UserPaintBox.h"

//public method---
PaintBoxNewExecutor::PaintBoxNewExecutor() {
}

PaintBoxNewExecutor::~PaintBoxNewExecutor() {
}

Object_ * const PaintBoxNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}

Object_ * PaintBoxNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	UserContainer* cont = arg_cast(UserContainer, 0, "Container");
	UserPaintBox* box = new UserPaintBox(new PaintBox(cont));
	return box;
}
//---public method
