#pragma once
#ifndef BEAN_AST_ASTINCLUDESTATEMENT_H
#define BEAN_AST_ASTINCLUDESTATEMENT_H
#include "ASTName.h"
#include "ASTNode.h"
/**
 * �ʂ̃t�@�C���̋@�\���C���N���[�h����v�f�ł�.
 */
class ASTIncludeStatement : public ASTNode {
public:
	ASTIncludeStatement();
	~ASTIncludeStatement();
	/**
	 * ���̗v�f���C���N���[�h����Ώۂւ�FQCN��ݒ肵�܂�.
	 * @param path
	 */
	void setPath(std::shared_ptr<ASTName> path);

	/**
	 * ���̗v�f���C���N���[�h����Ώۂւ�FQCN��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getPath() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor);
	DECL_MAKE_SHARED_0_H(ASTIncludeStatement)
private:
	std::shared_ptr<ASTName> path;
};
#endif // !BEAN_AST_ASTINCLUDESTATEMENT_H
