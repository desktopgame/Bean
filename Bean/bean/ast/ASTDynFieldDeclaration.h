#pragma once
#ifndef BEAN_AST_ASTDYNFIELDDECLARATION_H
#define BEAN_AST_ASTDYNFIELDDECLARATION_H
#include "ASTNode.h"
/**
 * 動的フィールド宣言.
 * obj::name = val;
 */
class ASTDynFieldDeclaration : public ASTNode {
public:
	ASTDynFieldDeclaration();
	~ASTDynFieldDeclaration();
	/**
	 * 対象を設定します.
	 * @param invoker
	 */
	void setInvoker(std::shared_ptr<ASTFactor> invoker);

	/**
	 * 対象を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getInvoker() const;

	/**
	 * 新たに作成されるフィールドの名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * 新たに作成されるフィールドの名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 新たに作成されるフィールドのデフォルト値を設定します.
	 * @param value
	 */
	void setValue(std::shared_ptr<ASTFactor> value);

	/**
	 * 新たに作成されるフィールドのデフォルト値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getValue() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTDynFieldDeclaration)
private:
	std::shared_ptr<ASTFactor> invoker;
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTFactor> value;
};
#endif // !BEAN_AST_ASTDYNFIELDDECLARATION_H
