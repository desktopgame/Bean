#pragma once
#ifndef BEAN_AST_ASTFIELDDECLARATION_H
#define BEAN_AST_ASTFIELDDECLARATION_H
#include "ASTMemberDeclaration.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * �t�B�[���h�錾��\���v�f.
 */
class ASTFieldDeclaration : public ASTMemberDeclaration {
public:
	ASTFieldDeclaration();
	~ASTFieldDeclaration();
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	/**
	 * �t�B�[���h�̃f�t�H���g�l��ݒ肵�܂�.
	 * @param defaultValue
	 */
	void setDefaultValue(std::shared_ptr<ASTFactor> defaultValue);

	/**
	 * �t�B�[���h�̃f�t�H���g�l��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getDefaultValue() const;

	/**
	 * �Z�b�^�[����ݒ肵�܂�.
	 * @param setMethodName
	 */
	void setSetMethodName(std::shared_ptr<ASTName> setMethodName);

	/**
	 * �Z�b�^�[����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getSetMethodName() const;

	/**
	 * �Q�b�^�[����ݒ肵�܂�.
	 * @param getMethodName
	 */
	void setGetMethodName(std::shared_ptr<ASTName> getMethodName);

	/**
	 * �Q�b�^�[����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getGetMethodName() const;
	DECL_MAKE_SHARED_0_H(ASTFieldDeclaration)
private:
	std::shared_ptr<ASTFactor> defaultValue;
	std::shared_ptr<ASTName> setMethodName;
	std::shared_ptr<ASTName> getMethodName;
};
#endif // !BEAN_AST_ASTFIELDDECLARATION_H


