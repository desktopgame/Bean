#include "VectorSortExecutor.h"
#include "../../Boolean.h"
#include "../../Numeric.h"
#include "../../gc/GCLock.h"
#include "../../user/UserDelegate.h"
#include "../../user/UserVector.h"
//public method---
VectorSortExecutor::VectorSortExecutor() {
}

VectorSortExecutor::~VectorSortExecutor() {
}

Object_ * const VectorSortExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	UserDelegate* ud = arg_cast(UserDelegate, 0, "Delegate");
	UserVector* uv = static_cast<UserVector*>(invoker);
	uv->getState()->addStrongReference(this);
	uv->sort([ud](Object_* left, Object_* right) {
		GCLock gcLock = GCLock();
		auto args = std::vector<Object_*>{ left, right };
		auto funcRet = ud->call(args);
		Boolean* compB = dynamic_cast<Boolean*>(funcRet);
		if (compB == nullptr) {
			Exception::throw_e_simple("api.exc.ArgumentException", "”äŠrŠÖ”‚ª^‹UŒ^‚ð•Ô‚µ‚Ü‚¹‚ñB");
			return false;
		}
		return compB->of();
	});
	uv->getState()->removeStrongReference(this, false);
	return getNull();
}
//---public method
