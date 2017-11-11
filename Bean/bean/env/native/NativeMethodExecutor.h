#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H
#define BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H
#include <functional>
#include <vector>
#include "../Method.h"
#include "../Object_.h"
#include "../../util/Text.h"
using MsgFactory = std::function<std::string()>;
/**
 * C++で実装されるメソッドです.
 */
class NativeMethodExecutor {
public:
	NativeMethodExecutor();
	virtual ~NativeMethodExecutor();
	/**
	 * このメソッドを実行します.
	 * @param proxy
	 * @param invoker
	 * @param args
	 */
	virtual Object_* const execute(Method* const proxy, Object_* const invoker, std::vector<Object_*> args) = 0;

	/**
	 * Method#newObjectを参照してください.
	 * @param classz
	 * @param cons
	 * @param args
	 * @return
	 */
	virtual Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args);
protected:
	//
	//例外
	//
	void throw_(const std::string& className, std::vector<Object_*> args);
	void throw_simple(const std::string& className, std::string msg);

	//
	//ユーティリティ
	//インクルードする代わりにこちらを使用出来ます。
	//

	/**
	 * nullを返します.
	 * @return
	 */
	Object_* getNull();

	/**
	 * BeanのBool型へキャストします.
	 * @param b
	 * @return
	 */
	Object_* getBoolean(bool b);

	/**
	 * BeanのInt型へキャストします.
	 * @param i
	 * @return
	 */
	Object_* getInteger(int i);

	/**
	 * BeanのChar型へキャストします.
	 * @param bc
	 * @return
	 */
	Object_* getCharacter(BChar bc);
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H


