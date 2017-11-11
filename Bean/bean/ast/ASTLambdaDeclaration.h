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
	 * 引数を追加します.
	 * @param param
	 */
	void addParameter(std::shared_ptr<ASTParameter> param);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTParameter> getParameterAt(int index) const;

	/**
	 * 全ての引数の数を返します.
	 * @return
	 */
	int getParameterCount() const;

	/**
	 * 処理の本文を設定します.
	 * @param body
	 */
	void setBody(std::shared_ptr<ASTBody> body);

	/**
	 * 処理の本体を返します.
	 * @return
	 */
	std::shared_ptr<ASTBody> getBody() const;

	/**
	 * 動的メソッドのためのラムダならtrue.
	 * @param b
	 */
	void setDynamicMethod(bool b);

	/**
	 * 動的メソッドのためのラムダならtrue.
	 * @param b
	 */
	bool isDynamicMethod() const;

	// ASTFactor を介して継承されました
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


