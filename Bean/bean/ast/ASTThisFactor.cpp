#include "ASTThisFactor.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"

//public method---
ASTThisFactor::ASTThisFactor() {
}

ASTThisFactor::~ASTThisFactor() {
}

std::string ASTThisFactor::format() const {
	return "this";
}

Object_ * ASTThisFactor::eval() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	auto ret = cll->getLock(true);
	if (ret == nullptr) {
		Exception::throw_e_simple("api.exc.RuntimeException", "���݂̃R���e�L�X�g�� this �͎Q�Əo���܂���B");
	}
	return ret;
}
IMPL_MAKE_SHARED_0_CPP(ASTThisFactor)
//---public method
