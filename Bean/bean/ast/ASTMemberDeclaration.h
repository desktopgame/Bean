#pragma once
#ifndef BEAN_AST_ASTMEMBERDECLARATION_H
#define BEAN_AST_ASTMEMBERDECLARATION_H
#include "ASTModifier.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * メンバー要素.
 */
class ASTMemberDeclaration : public ASTNode {
public:
	ASTMemberDeclaration();
	/**
	 * メンバー名を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * メンバー名を名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 修飾子を設定します.
	 * @param modifier
	 */
	void setModifier(std::shared_ptr<ASTModifier> modifier);

	/**
	 * 修飾子を返します.
	 * @return
	 */
	std::shared_ptr<ASTModifier> getModifier() const;
protected:
	virtual ~ASTMemberDeclaration();
private:
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTModifier> modifier;
};
#endif // !BEAN_AST_ASTMEMBERDECLARATION_H
