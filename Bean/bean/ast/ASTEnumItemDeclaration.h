#pragma once
#ifndef BEAN_AST_ASTENUMITEMDECLARATION_H
#define BEAN_AST_ASTENUMITEMDECLARATION_H
#include "ASTNode.h"
class ASTFactor;
class ASTName;
/**
 * 列挙子の宣言.
 */
class ASTEnumItemDeclaration : public ASTNode {
public:
	ASTEnumItemDeclaration();
	~ASTEnumItemDeclaration();
	/**
	 * 列挙子の初期値を設定します.
	 * @param value
	 */
	void setValue(std::shared_ptr<ASTFactor> value);

	/**
	 * 列挙子の初期値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getValue() const;

	/**
	 * 列挙子の名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * 列挙子の名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;
	DECL_MAKE_SHARED_0_H(ASTEnumItemDeclaration)
private:
	std::shared_ptr<ASTFactor> value;
	std::shared_ptr<ASTName> name;
};
#endif
