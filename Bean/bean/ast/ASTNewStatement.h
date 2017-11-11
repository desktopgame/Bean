#pragma once
#ifndef BEAN_AST_ASTNEWSTATEMENT_H
#define BEAN_AST_ASTNEWSTATEMENT_H
#include "ASTFactor.h"
#include "ASTName.h"
//NOTE:	�g�p����Ă��܂���B
//		new�̓��\�b�h�Ăяo���Ɠ����ɂȂ�܂���
/**
 * new
 */
class ASTNewStatement : public ASTFactor {
public:
	ASTNewStatement();
	~ASTNewStatement();
	/**
	 * ���������N���X����ݒ肵�܂�.
	 * @param className
	 */
	void setClassName(std::shared_ptr<ASTName> className);

	/**
	 * ���������N���X����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getClassName() const;

	/**
	 * �R���X�g���N�^�Ăяo���Ɉ�����ǉ����܂�.
	 * @param factor
	 */
	void addArgument(std::shared_ptr<ASTFactor> factor);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * �S�Ă̈����̐���Ԃ��܂�.
	 * @return
	 */
	int getArgumentCount() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTNewStatement)
protected:
private:
	std::shared_ptr<ASTName> className;
	std::vector<std::shared_ptr<ASTFactor>> arguments;
};
#endif // !BEAN_AST_ASTNEWSTATEMENT_H
