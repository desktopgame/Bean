#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATIONBYSELF_H
#define BEAN_AST_ASTMETHODINVOCATIONBYSELF_H
#include "ASTMethodInvocation.h"
/**
 * 自身に定義されているメソッドの呼び出し.
 */
class ASTMethodInvocationBySelf : public ASTMethodInvocation  {
public:
	ASTMethodInvocationBySelf();
	~ASTMethodInvocationBySelf();
	Object_ * eval() override;
	std::shared_ptr<ASTMethodInvocationBySelf> asBySelf() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTMethodInvocationBySelf)
protected:
private:
	Object_* evalImpl();

	//高速化されたメソッド検索処理
	//最初の一度だけ検索してそれ以降はキャッシュを返します
	Function* findTopLevelFunction(FunctionManager* fm, std::string name, int argc);
	Method* findSelfMethod(ClassSPtr classz, std::string name, int argc);

	bool cacheCompiled;
	Function* cacheTopLevelFunction;
	Method* cacheSelfMethod;
};
#endif // BEAN_AST_ASTMETHODINVOCATIONBYSELF_H


