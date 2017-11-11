#pragma once
#ifndef BEAN_AST_ASTDYNFIELDDECLARATION_H
#define BEAN_AST_ASTDYNFIELDDECLARATION_H
#include "ASTNode.h"
/**
 * ���I�t�B�[���h�錾.
 * obj::name = val;
 */
class ASTDynFieldDeclaration : public ASTNode {
public:
	ASTDynFieldDeclaration();
	~ASTDynFieldDeclaration();
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
	 * �V���ɍ쐬�����t�B�[���h�̖��O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �V���ɍ쐬�����t�B�[���h�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �V���ɍ쐬�����t�B�[���h�̃f�t�H���g�l��ݒ肵�܂�.
	 * @param value
	 */
	void setValue(std::shared_ptr<ASTFactor> value);

	/**
	 * �V���ɍ쐬�����t�B�[���h�̃f�t�H���g�l��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getValue() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTDynFieldDeclaration)
private:
	std::shared_ptr<ASTFactor> invoker;
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTFactor> value;
};
#endif // !BEAN_AST_ASTDYNFIELDDECLARATION_H
