#pragma once
#ifndef BEAN_ENV_MESSAGEINFO_H
#define BEAN_ENV_MESSAGEINFO_H
#include <memory>
#include <string>
class ClassLoader;
class Class;
class Method;
class Function;
using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
#include "ClassLoaderSkeleton.h"
/**
 * そのメソッド呼び出しが行われたスタックフレームに関する情報をカプセル化します.
 * 例外が捕捉されなかったときに呼び出し階層をダンプするために使用されます。
 */
class MessageInfo {
public:
	MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Method* method);
	MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Function* func);
	~MessageInfo();

	/**
	 * トップレベルであることを示す特別な MessageInfo インスタンスを返します.
	 * @return
	 */
	static MessageInfo* createTop();

	/**
	 * このメッセージ生成時のソースコードを実行したクラスローダーを返します.
	 * @return
	 */
	ClassLoaderWPtr getClassLoader() const;

	/**
	 * このメッセージを生成したクラスを返します.
	 * @return
	 */
	ClassSPtr getClass() const;

	/**
	 * このメッセージを生成したメソッドを返します.
	 * @return
	 */
	Method* const getMethod() const;

	/**
	 * トップレベルで実行されている場合のみ使用可能です.
	 * @return
	 */
	Function* const getFunction() const;

	/**
	 * 現在実行中のコード位置を返します.
	 * @return
	 */
	std::string getLocation();
private:
	MessageInfo(bool top);
	ClassLoaderWPtr classLoader;
	ClassWPtr classz;
	Method* method;
	Function* func;
	bool top;
};
#endif // !BEAN_ENV_MESSAGEINFO_H


