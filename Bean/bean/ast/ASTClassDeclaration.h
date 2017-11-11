#pragma once
#ifndef BEAN_AST_ASTCLASSDECLARATION_H
#define BEAN_AST_ASTCLASSDECLARATION_H
#include "ASTBranch.h"
#include "ASTFieldDeclaration.h"
#include "ASTMethodDeclaration.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * �N���X�錾��\���v�f�ł�.
 */
class ASTClassDeclaration : public ASTBranch {
public:
	ASTClassDeclaration();
	~ASTClassDeclaration();

	/**
	 * �N���X����ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �N���X����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �e�N���X����ݒ肵�܂�.
	 * @param sueprClass
	 */
	void setSuperClass(std::shared_ptr<ASTName> superClass);

	/**
	 * �e�N���X����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getSuperClass() const;

	/**
	 * �t�B�[���h��ǉ����܂�.
	 * @param
	 */
	void addField(std::shared_ptr<ASTFieldDeclaration> field);

	/**
	 * �w��ʒu�̃t�B�[���h��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFieldDeclaration> getFieldAt(int index);

	/**
	 * �t�B�[���h�̐���Ԃ��܂�.
	 * @return
	 */
	int getFieldCount();

	/**
	 * ���\�b�h��ǉ����܂�.
	 * @param method
	 */
	void addMethod(std::shared_ptr<ASTMethodDeclaration> method);

	/**
	 * �w��ʒu�̃��\�b�h��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTMethodDeclaration> getMethodAt(int index) const;

	/**
	 * �S�Ẵ��\�b�h�̐���Ԃ��܂�.
	 * @return
	 */
	int getMethodCount()const;

	std::string format() const override;
	void accept(ASTVisitor* visitor);
	DECL_MAKE_SHARED_0_H(ASTClassDeclaration)
private:
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTName> superClass;
	std::vector<std::shared_ptr<ASTFieldDeclaration>> fields;
	std::vector<std::shared_ptr<ASTMethodDeclaration>> methods;
};
#endif // !BEAN_AST_ASTCLASSDECLARATION_H
