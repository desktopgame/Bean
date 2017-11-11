#pragma once
#ifndef BEAN_AST_ASTFIELDDECLARATION_H
#define BEAN_AST_ASTFIELDDECLARATION_H
#include "ASTMemberDeclaration.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * フィールド宣言を表す要素.
 */
class ASTFieldDeclaration : public ASTMemberDeclaration {
public:
	ASTFieldDeclaration();
	~ASTFieldDeclaration();
	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	/**
	 * フィールドのデフォルト値を設定します.
	 * @param defaultValue
	 */
	void setDefaultValue(std::shared_ptr<ASTFactor> defaultValue);

	/**
	 * フィールドのデフォルト値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getDefaultValue() const;

	/**
	 * セッター名を設定します.
	 * @param setMethodName
	 */
	void setSetMethodName(std::shared_ptr<ASTName> setMethodName);

	/**
	 * セッター名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getSetMethodName() const;

	/**
	 * ゲッター名を設定します.
	 * @param getMethodName
	 */
	void setGetMethodName(std::shared_ptr<ASTName> getMethodName);

	/**
	 * ゲッター名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getGetMethodName() const;
	DECL_MAKE_SHARED_0_H(ASTFieldDeclaration)
private:
	std::shared_ptr<ASTFactor> defaultValue;
	std::shared_ptr<ASTName> setMethodName;
	std::shared_ptr<ASTName> getMethodName;
};
#endif // !BEAN_AST_ASTFIELDDECLARATION_H


