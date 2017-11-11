#include "ASTSuperFactor.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"

//public method---
ASTSuperFactor::ASTSuperFactor() {
}

ASTSuperFactor::~ASTSuperFactor() {
}

Object_ * ASTSuperFactor::eval() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	auto ret = cll->getLock(true);
	if (ret == nullptr) {
		Exception::throw_e_simple("api.exc.RuntimeException", "現在のコンテキストで this は参照出来ません。");
	}
	return ret;
}

ClassSPtr ASTSuperFactor::getBaseLine(ClassSPtr classz) {
	ClassSPtr cls = classz->getSuper().lock();
	if (classz->getSuper().expired() || !cls) {
		return classz;
	}
	return cls;
}
IMPL_MAKE_SHARED_0_CPP(ASTSuperFactor)
//---public method
