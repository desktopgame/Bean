#include "TypedNativeMethodExecutor.h"
#include "NativeCastException.h"
#include "../../env/Class.h"
#include "../../env/ClassLoader.h"
#include "../../env/Method.h"
#include "../../env/Null.h"
#include "../../env/String.h"

//public method---
TypedNativeMethodExecutor::TypedNativeMethodExecutor() {
}

TypedNativeMethodExecutor::~TypedNativeMethodExecutor() {
}

Object_ * const TypedNativeMethodExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	try {
		Object_* ret = executeImpl(proxy, invoker, args);
		return ret;
	} catch (NativeCastException e) {
		Exception::throw_e_wrap("api.exc.TypeCastError", e);
		return Null::getInstance();
	}
}
//---public method

//protected method---
void TypedNativeMethodExecutor::throw_io_error(
	Method* proxy,
	boost::filesystem::filesystem_error e) {
	Exception::throw_e_wrap("api.exc.IOException", e);
}

void TypedNativeMethodExecutor::do_io(Method* proxy, std::function<void()> f) {
	try {
		f();
	} catch (boost::filesystem::filesystem_error e) {
		throw_io_error(proxy, e);
	}
}
//---protected method
