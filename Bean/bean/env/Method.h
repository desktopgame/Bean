#pragma once
#ifndef BEAN_ENV_METHOD_H
#define BEAN_ENV_METHOD_H
#include <memory>
#include <vector>
#include "Member.h"
class Constructor_;
class Object_;
class Parameter;
class Object_;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * 戻り値と引数で表される手続きです.
 */
class Method : public Member {
public:
	Method(ClassSPtr classz, Modifier modifier, std::string name);
	virtual ~Method();

	/**
	 * このメソッドに引数を追加します.
	 * @param param
	 */
	virtual void addParameter(Parameter* param);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 * @return
	 */
	virtual Parameter* const getParameterAt(int index) const;

	/**
	 * 指定位置の引数を削除します.
	 * @param index
	 */
	virtual void removeParameterAt(int index);

	/**
	 * 全ての引数の数を返します.
	 * @return
	 */
	virtual int getParameterCount() const;

	/**
	 * このメソッドを実行します.
	 * @param invoker
	 * @param args
	 * @param currentClassLoader
	 * @return
	 */
	virtual Object_* const execute(Object_* const invoker, std::vector<Object_*> args, bool currentClassLoader) = 0;

	/**
	 * 現在のクラスローダーを設定して呼び出します.
	 * @param invoker
	 * @param args
	 */
	virtual Object_* const execute(Object_* const invoker, std::vector<Object_*> args);

	/**
	 * このメソッドがコンストラクタにラップされるとき、
	 * クラスのコンテナとして機能するクラスを返します.
	 * デフォルトではUserObjectを返します。
	 * @param classz
	 * @param cons
	 * @param args
	 * @return
	 */
	virtual Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args);

	/**
	 * このメソッドの所在を一意に表す文字列を返します.
	 * @return
	 */
	std::string toUID();
	std::string getLocation() override;
private:
	std::vector<Parameter*> parameters;

};
#endif // !BEAN_ENV_METHOD_H
