#pragma once
#ifndef BEAN_AST_ASTALIASSTATEMENT_H
#define BEAN_AST_ASTALIASSTATEMENT_H
#include "ASTNode.h"
/**
 * alias 宣言.
 */
class ASTAliasStatement : public ASTNode {
public:
	ASTAliasStatement();
	~ASTAliasStatement();
	/**
	 * 古い名前を設定します.
	 * @param oldName
	 */
	void setOldName(std::shared_ptr<ASTName> oldName);

	/**
	 * 古い名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getOldName() const;

	/**
	 * 新しい名前を設定します.
	 * @param newName
	 */
	void setNewName(std::shared_ptr<ASTName> newName);

	/**
	 * 新しい名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getNewName() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTAliasStatement)
private:
	std::shared_ptr<ASTName> newName;
	std::shared_ptr<ASTName> oldName;
};
#endif //!BEAN_AST_ASTALIASSTATEMENT_H