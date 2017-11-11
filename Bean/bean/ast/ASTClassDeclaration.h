#pragma once
#ifndef BEAN_AST_ASTCLASSDECLARATION_H
#define BEAN_AST_ASTCLASSDECLARATION_H
#include "ASTBranch.h"
#include "ASTFieldDeclaration.h"
#include "ASTMethodDeclaration.h"
#include "ASTName.h"
#include "ASTNode.h"
/**
 * クラス宣言を表す要素です.
 */
class ASTClassDeclaration : public ASTBranch {
public:
	ASTClassDeclaration();
	~ASTClassDeclaration();

	/**
	 * クラス名を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * クラス名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 親クラス名を設定します.
	 * @param sueprClass
	 */
	void setSuperClass(std::shared_ptr<ASTName> superClass);

	/**
	 * 親クラス名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getSuperClass() const;

	/**
	 * フィールドを追加します.
	 * @param
	 */
	void addField(std::shared_ptr<ASTFieldDeclaration> field);

	/**
	 * 指定位置のフィールドを返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFieldDeclaration> getFieldAt(int index);

	/**
	 * フィールドの数を返します.
	 * @return
	 */
	int getFieldCount();

	/**
	 * メソッドを追加します.
	 * @param method
	 */
	void addMethod(std::shared_ptr<ASTMethodDeclaration> method);

	/**
	 * 指定位置のメソッドを返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTMethodDeclaration> getMethodAt(int index) const;

	/**
	 * 全てのメソッドの数を返します.
	 * @return
	 */
	int getMethodCount()const;

	std::string format() const override;
	void accept(ASTVisitor* visitor);
	DECL_MAKE_SHARED_0_H(ASTClassDeclaration)
private:
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTName> superClass;
	std::vector<std::shared_ptr<ASTFieldDeclaration>> fields;
	std::vector<std::shared_ptr<ASTMethodDeclaration>> methods;
};
#endif // !BEAN_AST_ASTCLASSDECLARATION_H
