#pragma once
#ifndef BEAN_AST_ASTFIELDACCESS_H
#define BEAN_AST_ASTFIELDACCESS_H
#include "ASTPointer.h"
/**
 * hoge.piyo.
 */
class ASTFieldAccess : public ASTPointer {
public:
	ASTFieldAccess();
	~ASTFieldAccess();
	/**
	 * �v���p�e�B��������������C���X�^���X��ݒ肵�܂�.
	 * @param parent
	 */
	void setParent(std::shared_ptr<ASTFactor> parent);

	/**
	 * �v���p�e�B��������������C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getParent() const;

	/**
	 * �v���p�e�B����ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �v���p�e�B����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;
	
	/**
	 * �t�B�[���h�ւ̎Q�Ƃ�Ԃ��܂�.
	 * @return
	 */
	PointerSPtr getReference() override;

	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTFieldAccess)
protected:
	Object_* evalThrow() override;
private:
	std::shared_ptr<ASTFactor> parent;
	std::shared_ptr<ASTName> name;
	PointerSPtr pointee;
};
#endif // !BEAN_AST_ASTFIELDACCESS_H


