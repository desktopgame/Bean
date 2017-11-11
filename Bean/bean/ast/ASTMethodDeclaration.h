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
 * メソッド宣言を表す要素です.
 */
class ASTMethodDeclaration : public ASTMemberDeclaration {
public:
	ASTMethodDeclaration();
	virtual ~ASTMethodDeclaration();

	/**
	 * 処理の本体を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * 処理の本体を返します.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * 引数を追加します.
	 * @param parameter
	 */
	void addParameter(std::shared_ptr<ASTParameter> parameter);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTParameter> getParameterAt(int index) const;

	/**
	 * 引数の数を返します.
	 * @return
	 */
	int getParameterCount() const;

	/**
	 * このメソッドの本文が省略されているかどうかを設定します.
	 * @param isSimple
	 */
	void setSimple(bool isSimple);

	/**
	 * このメソッドの本文が省略されているなら true を返します.
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
