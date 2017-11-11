#pragma once
#ifndef BEAN_AST_ASTELSESTATEMENT_H
#define BEAN_AST_ASTELSESTATEMENT_H
#include "ASTBody.h"
#include "ASTNode.h"
/**
 * else��.
 * �q�v�f�Ƃ��ĕ��������Ƃ��o���܂��B
 */
class ASTElseStatement : public ASTNode {
public:
	ASTElseStatement();
	~ASTElseStatement();
	/**
	* ���̏�������������Ă���Ƃ��Ɏ��s����镶��ݒ肵�܂�.
	* @param body
	*/
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	* ���̏�������������Ă���Ƃ��Ɏ��s����镶��Ԃ��܂�.
	* @return
	*/
	std::shared_ptr<ASTBody> getBody() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTElseStatement)
private:
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTELSESTATEMENT_H
