#pragma once
#ifndef BEAN_AST_ASTDYNMETHODDECLARATION_H
#define BEAN_AST_ASTDYNMETHODDECLARATION_H
#include "ASTNode.h"
/**
 * ���I���\�b�h�錾.
 * obj::name() = lamda() -> { ... };
 */
class ASTDynMethodDeclaration : public ASTNode {
public:
	ASTDynMethodDeclaration();
	~ASTDynMethodDeclaration();

	/**
	 * �Ώۂ�ݒ肵�܂�.
	 * @param invoker
	 */
	void setInvoker(std::shared_ptr<ASTFactor> invoker);

	/**
	 * �Ώۂ�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getInvoker() const;

	/**
	 * ���O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * ���O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �{����ݒ肵�܂�.
	 * @param lambda
	 */
	void setLambda(std::shared_ptr<ASTLambdaDeclaration> lambda);

	/**
	 * �{����Ԃ��܂�.
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
