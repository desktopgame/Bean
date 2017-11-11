#pragma once
#ifndef BEAN_AST_ASTIFCAUSESTATEMENT_H
#define BEAN_AST_ASTIFCAUSESTATEMENT_H
#include "ASTFactor.h"
#include "ASTNode.h"
/**
 * if elseif �̊��N���X.
 */
class ASTIfCauseStatement : public ASTNode {
public:
	ASTIfCauseStatement();
	virtual ~ASTIfCauseStatement();
	/**
	 * ��������ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ��������Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;

	/**
	 * ���̕��̏�������������Ă���Ƃ��Ɏ��s����镶��ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * ���̕��̏�������������Ă���Ƃ��Ɏ��s����镶��ݒ肵�܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;
private:
	std::shared_ptr<ASTBody> body;
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTIFCAUSESTATEMENT_H


