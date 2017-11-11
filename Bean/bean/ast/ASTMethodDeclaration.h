#pragma once
#ifndef BEAN_AST_ASTMETHODDECLARATION_H
#define BEAN_AST_ASTMETHODDECLARATION_H
#include "ASTBody.h"
#include "ASTMemberDeclaration.h"
#include "ASTModifier.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "ASTParameter.h"
/**
 * ���\�b�h�錾��\���v�f�ł�.
 */
class ASTMethodDeclaration : public ASTMemberDeclaration {
public:
	ASTMethodDeclaration();
	virtual ~ASTMethodDeclaration();

	/**
	 * �����̖{�̂�ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * �����̖{�̂�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * ������ǉ����܂�.
	 * @param parameter
	 */
	void addParameter(std::shared_ptr<ASTParameter> parameter);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTParameter> getParameterAt(int index) const;

	/**
	 * �����̐���Ԃ��܂�.
	 * @return
	 */
	int getParameterCount() const;

	/**
	 * ���̃��\�b�h�̖{�����ȗ�����Ă��邩�ǂ�����ݒ肵�܂�.
	 * @param isSimple
	 */
	void setSimple(bool isSimple);

	/**
	 * ���̃��\�b�h�̖{�����ȗ�����Ă���Ȃ� true ��Ԃ��܂�.
	 * @return
	 */
	bool isSimple() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTMethodDeclaration)
protected:
private:
	bool simple;
	std::shared_ptr<ASTBody> body;
	std::vector<std::shared_ptr<ASTParameter>> parameters;
};
#endif
