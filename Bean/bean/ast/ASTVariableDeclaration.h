#pragma once
#ifndef BEAN_AST_ASTVARIABLEDECLARATION_H
#define BEAN_AST_ASTVARIABLEDECLARATION_H
#include "ASTFactor.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * var�v�f.
 */
class ASTVariableDeclaration : public ASTNode {
public:
	ASTVariableDeclaration();
	~ASTVariableDeclaration();
	/**
	 * ��`�����ϐ��̖��O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);
	/**
	 * ��`�����ϐ��̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * ���̎��ɂ���Ē�`�����ϐ��ɑ�������l��ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ���̎��ɂ���Ē�`�����ϐ��ɑ�������l��Ԃ��܂�.
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
