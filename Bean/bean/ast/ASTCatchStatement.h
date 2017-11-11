#pragma once
#ifndef BEAN_AST_ASTCATCHSTATEMENT_H
#define BEAN_AST_ASTCATCHSTATEMENT_H
#include "ASTNode.h"
/**
 * catch(hoge) { ... } 構文です.
 */
class ASTCatchStatement : public ASTNode {
public:
	ASTCatchStatement();
	~ASTCatchStatement();
	/**
	 * catchされる例外の変数名を設定します.
	 * @param captureExceptionName
	 */
	void setCaptureExceptionName(std::shared_ptr<ASTName> captureExceptionName);

	/**
	 * catchされる例外の変数名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getCaptureExceptionName() const;

	/**
	 * catchされたときに実行される処理の本文を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * catchされたときに実行される処理の本文を返します.
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
