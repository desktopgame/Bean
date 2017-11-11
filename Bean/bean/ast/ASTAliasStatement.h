#pragma once
#ifndef BEAN_AST_ASTALIASSTATEMENT_H
#define BEAN_AST_ASTALIASSTATEMENT_H
#include "ASTNode.h"
/**
 * alias �錾.
 */
class ASTAliasStatement : public ASTNode {
public:
	ASTAliasStatement();
	~ASTAliasStatement();
	/**
	 * �Â����O��ݒ肵�܂�.
	 * @param oldName
	 */
	void setOldName(std::shared_ptr<ASTName> oldName);

	/**
	 * �Â����O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getOldName() const;

	/**
	 * �V�������O��ݒ肵�܂�.
	 * @param newName
	 */
	void setNewName(std::shared_ptr<ASTName> newName);

	/**
	 * �V�������O��Ԃ��܂�.
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