#pragma once
#ifndef BEAN_AST_ASTDYNMETHODDECLARATION_H
#define BEAN_AST_ASTDYNMETHODDECLARATION_H
#include "ASTNode.h"
/**
 * 動的メソッド宣言.
 * obj::name() = lamda() -> { ... };
 */
class ASTDynMethodDeclaration : public ASTNode {
public:
	ASTDynMethodDeclaration();
	~ASTDynMethodDeclaration();

	/**
	 * 対象を設定します.
	 * @param invoker
	 */
	void setInvoker(std::shared_ptr<ASTFactor> invoker);

	/**
	 * 対象を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getInvoker() const;

	/**
	 * 名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * 名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 本文を設定します.
	 * @param lambda
	 */
	void setLambda(std::shared_ptr<ASTLambdaDeclaration> lambda);

	/**
	 * 本文を返します.
	 * @return
	 */
	std::shared_ptr<ASTLambdaDeclaration> getLambda() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTDynMethodDeclaration)
private:
	std::shared_ptr<ASTFactor> invoker;
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTLambdaDeclaration> lambda;
};
#endif // !BEAN_AST_ASTDYNMETHODDECLARATION_H
