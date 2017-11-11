#pragma once
#ifndef BEAN_AST_ASTCATCHSTATEMENT_H
#define BEAN_AST_ASTCATCHSTATEMENT_H
#include "ASTNode.h"
/**
 * catch(hoge) { ... } �\���ł�.
 */
class ASTCatchStatement : public ASTNode {
public:
	ASTCatchStatement();
	~ASTCatchStatement();
	/**
	 * catch������O�̕ϐ�����ݒ肵�܂�.
	 * @param captureExceptionName
	 */
	void setCaptureExceptionName(std::shared_ptr<ASTName> captureExceptionName);

	/**
	 * catch������O�̕ϐ�����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getCaptureExceptionName() const;

	/**
	 * catch���ꂽ�Ƃ��Ɏ��s����鏈���̖{����ݒ肵�܂�.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * catch���ꂽ�Ƃ��Ɏ��s����鏈���̖{����Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTCatchStatement)
private:
	std::shared_ptr<ASTName> captureExceptionName;
	std::shared_ptr<ASTBody> body;
};
#endif // !BEAN_AST_ASTCATCHSTATEMENT_H
