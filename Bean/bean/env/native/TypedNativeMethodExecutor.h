#pragma once
#ifndef BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H
#define BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H
#include <functional>
#include <boost/filesystem.hpp>
#include "NativeCastException.h"
#include "NativeMethodExecutor.h"
#include "../../env/Class.h"
#include "../../env/ClassLoader.h"
#include "../../env/Exception.h"
#include "../../env/String.h"
//
//引数列args の 指定位置の要素のキャストを施行します
//このマクロはexecuteImplの中でのみ使用可能です。
//t = 型名
//i = 引数の番号
//r = 期待する型
#define arg_cast(t, i, r) checkCastRequire<t>(args.at(i), r);

/**
 * ネイティブメソッドを簡単に実装するためのヘルパーです.
 */
class TypedNativeMethodExecutor : public NativeMethodExecutor {
public:
	TypedNativeMethodExecutor();
	virtual ~TypedNativeMethodExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	virtual Object_* const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) = 0;

protected:
	/**
	 * 指定の参照の持つ値をキャストして返します.
	 * @param ref
	 * @param msg
	 * @return
	 */
	template<typename T>
	T* checkCast(Object_* ref, std::string msg);

	/**
	 * 指定の参照の持つ値をキャストして返します.
	 * @param ref
	 * @param msg
	 * @return
	 */
	template<typename T>
	T* checkCastRequire(Object_* ref, std::string requireType);

	/**
	 * boostの例外をbeanでラップしてスローします.
	 * @param proxy
	 * @param e
	 */
	void throw_io_error(Method* proxy, boost::filesystem::filesystem_error e);

	/**
	 * fで発生した例外をラップしてスローします.
	 * @param proxy
	 * @param f
	 */
	void do_io(Method* proxy, std::function<void()> f);
};

#endif // !BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H

template<typename T>
inline T * TypedNativeMethodExecutor::checkCast(Object_ * ref, std::string msg) {
	Object_* val = ref->getValue();
	if (val == NULL || val == nullptr) {
		throw NativeCastException(msg);
	}
	T* ret = dynamic_cast<T*>(val);
	if (ret == NULL || val == nullptr) {
		throw NativeCastException(msg);
	}
	return ret;
}

template<typename T>
inline T * TypedNativeMethodExecutor::checkCastRequire(Object_ * ref, std::string requireType) {
	Object_* val = ref;
	if (val == NULL || val == nullptr) {
		throw NativeCastException("null を " + requireType + " へ変換出来ません");
	}
	T* ret = dynamic_cast<T*>(val);
	if (ret == NULL || val == nullptr) {
		ClassWPtr classz = val->getClass();
		ClassSPtr clsSPtr = classz.lock();
		std::string typeName = clsSPtr == NULL ? "null" : clsSPtr->getName();
		throw NativeCastException(typeName + " を " + requireType + " へ変換出来ません");
	}
	return ret;
}
