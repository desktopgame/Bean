#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H
#define BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H
#include "ASTFactor.h"
#include "ASTMethodInvocation.h"
/**
 * 命令によるメソッド呼び出し.
 */
class ASTMethodInvocationByMessage : public ASTMethodInvocation {
public:
	ASTMethodInvocationByMessage();
	~ASTMethodInvocationByMessage();
	/**
	 * 実行するオブジェクトを設定します.
	 * @param invoker
	 */
	void setInvoker(std::shared_ptr<ASTFactor> invoker);

	/**
	 * 実行するオブジェクトを返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getInvoker() const;
	// ASTFactor を介して継承されました
	Object_ * eval() override;
	std::shared_ptr<ASTMethodInvocationByMessage> asByMessage() override;
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTMethodInvocationByMessage)
private:
	Object_* evalImpl();
	std::shared_ptr<ASTFactor> invoker;

	//高速化されたメソッド検索処理
	//最初の一度だけ検索してそれ以降はキャッシュを返します
	ClassSPtr findClassStatic(ClassLoaderSPtr cll, std::string name);
	Method* findMethodStatic(ClassSPtr classz, std::string name, int argc);
	Method* findMethodDynamic(Object_* obj, ClassSPtr classz, std::string name, int argc);

	bool cacheCompiled;
	ClassSPtr cacheClassStatic;
	Method* cacheMethodStatic;
	Method* cacheMethodDynamic;
};
#endif // !BEAN_AST_ASTMETHODINVOCATIONBYMESSAGE_H


