#pragma once
#ifndef BEAN_AST_ASTVARIABLEDECLARATION_H
#define BEAN_AST_ASTVARIABLEDECLARATION_H
#include "ASTFactor.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * var要素.
 */
class ASTVariableDeclaration : public ASTNode {
public:
	ASTVariableDeclaration();
	~ASTVariableDeclaration();
	/**
	 * 定義される変数の名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);
	/**
	 * 定義される変数の名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * この式によって定義される変数に代入される値を設定します.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * この式によって定義される変数に代入される値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTVariableDeclaration)
protected:
private:
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTVARIABLEDECLARATION_H
