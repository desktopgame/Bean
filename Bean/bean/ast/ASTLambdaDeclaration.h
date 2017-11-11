#pragma once
#ifndef BEAN_AST_ASTLAMBDADECLARATION_H
#define BEAN_AST_ASTLAMBDADECLARATION_H
#include "ASTBody.h"
#include "ASTFactor.h"
#include "ASTParameter.h"
/**
 * lambda(, , , ) -> {  };
 */
class ASTLambdaDeclaration : public ASTFactor {
public:
	ASTLambdaDeclaration();
	~ASTLambdaDeclaration();

	/**
	 * ������ǉ����܂�.
	 * @param param
	 */
	void addParameter(std::shared_ptr<ASTParameter> param);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTParameter> getParameterAt(int index) const;

	/**
	 * �S�Ă̈����̐���Ԃ��܂�.
	 * @return
	 */
	int getParameterCount() const;

	/**
	 * �����̖{����ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * �����̖{�̂�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * ���I���\�b�h�̂��߂̃����_�Ȃ�true.
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * ���I���\�b�h�̂��߂̃����_�Ȃ�true.
	 * @param b
	 */
	bool isDynamicMethod() const;

	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTLambdaDeclaration)
private:
	bool dynamicMethod;
	std::vector<std::shared_ptr<ASTParameter>> parameters;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTLAMBDADECLARATION_H


