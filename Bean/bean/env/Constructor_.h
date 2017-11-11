#pragma once
#ifndef BEAN_ENV_CONSTRUCTOR_H
#define BEAN_ENV_CONSTRUCTOR_H
#include "Method.h"
#include "../ast/ASTConstructorChain.h"
using ClassSPtr = std::shared_ptr<Class>;
/**
 * コンストラクタ.
 * コンストラクタを実行するためには、フィールドを格納する領域を先に用意しなければいけないので、
 * UserObjectを生成し、それをinvokerとしてproxyへ委譲します。
 */
class Constructor_ : public Method {
public:
	Constructor_(ClassSPtr const classz, Modifier modifier, std::string name, Method* proxy);
	virtual ~Constructor_();

	/**
	 * 連鎖先を設定します.
	 * @param chain
	 */
	virtual void setChain(std::shared_ptr<ASTConstructorChain> chain);

	/**
	 * 連鎖先を返します.
	 * @return
	 */
	virtual std::shared_ptr<ASTConstructorChain> getChain() const;

	//内部のproxyへも委譲します。
	virtual void addParameter(Parameter* param) override;
	virtual Parameter* const getParameterAt(int index) const override;
	virtual void removeParameterAt(int index) override;
	virtual int getParameterCount() const override;
	/**
	 * 戻り値は委譲メソッドの戻り値ではなく(これは常にnullなので)
	 * 生成されたUserObjectをラップするObject_です.
	 * @param invoker 無視されます。
	 * @param args
	 */
	virtual Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;

	/**
	 * コンストラクタの実装を返します.
	 * @return
	 */
	virtual Method* const getProxy() const;
protected:

	bool deleteProxy;
private:
	Method* proxy;
	std::shared_ptr<ASTConstructorChain> chain;
};
#endif // !BEAN_ENV_CONSTRUCTOR_H


