#pragma once
#ifndef BEAN_ENV_LAMBDADELEGATE_H
#define BEAN_ENV_LAMBDADELEGATE_H
#include <string>
#include <unordered_map>
#include "Delegate.h"
class ASTLambdaDeclaration;
/**
 * ラムダ式を利用したデリゲートの実装です.
 */
class LambdaDelegate : public Delegate {
public:
	/**
	 * @param lambdaDecl
	 */
	LambdaDelegate(ASTLambdaDeclaration* lambdaDecl);
	~LambdaDelegate();
	/**
	 * ラムダの外側の変数を追加します.
	 * ここで追加された変数はGCの対象にならず、
	 * ラムダの内側から使用することが出来ます。
	 * @param name
	 */
	void addOutsideReference(std::string name);
	// Delegate を介して継承されました
	virtual Object_* call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual Object_ * call(ClassLoaderSPtr cll, std::vector<Object_*> args) override;
	virtual int requestArgumentCount() override;
	std::vector<Object_*> getVirtualField(ClassLoaderSPtr cll) override;
private:
//	std::unordered_map<std::string, Object_*> outerObject_s;
	std::vector<std::string> outerObject_s;
	ASTLambdaDeclaration* lambdaDecl;
};
#endif // !BEAN_ENV_LAMBDADELEGATE_H


