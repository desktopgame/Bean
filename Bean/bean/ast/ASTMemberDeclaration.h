#pragma once
#ifndef BEAN_AST_ASTMEMBERDECLARATION_H
#define BEAN_AST_ASTMEMBERDECLARATION_H
#include "ASTModifier.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * �����o�[�v�f.
 */
class ASTMemberDeclaration : public ASTNode {
public:
	ASTMemberDeclaration();
	/**
	 * �����o�[����ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �����o�[���𖼂�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �C���q��ݒ肵�܂�.
	 * @param modifier
	 */
	void setModifier(std::shared_ptr<ASTModifier> modifier);

	/**
	 * �C���q��Ԃ��܂�.
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
