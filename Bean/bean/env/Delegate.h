#pragma once
#ifndef BEAN_ENV_DELEGATE_H
#define BEAN_ENV_DELEGATE_H
#include <vector>
class Object_;
class ClassLoader;
#include "ClassLoaderSkeleton.h"
#include "../threads/Thread.h"
/**
 * 匿名関数の実装です.
 */
class Delegate {
public:
	Delegate();
	virtual ~Delegate() = 0;
	/**
	 * 関数を指定のスレッドで実行します.
	 * @param t
	 * @param cll
	 * @param args
	 */
	virtual Object_* call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) = 0;

	/**
	 * 関数をこのデリゲートが定義されたスコープで実行します.
	 * @param cll
	 * @param args
	 * @return
	 */
	virtual Object_* call(ClassLoaderSPtr cll, std::vector<Object_*> args) = 0;

	/**
	 * このラムダが要求する引数の数を返します.
	 * @return
	 */
	virtual int requestArgumentCount() = 0;

	/**
	 * 仮想フィールドを返します.
	 * @return
	 */
	virtual std::vector<Object_*> getVirtualField(ClassLoaderSPtr cll);

	/**
	 * 動的メソッドのためのデリゲートならtrue.
	 * ラムダによって作成された場合のみtrueです。
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * 動的メソッドのためのデリゲートならtrue.
	 * ラムダによって作成された場合のみtrueです。
	 * @param b
	 */
	bool isDynamicMethod();
private:
	bool dynamicMethod;
};
#endif // !BEAN_ENV_DELEGATE_H


