#pragma once
#ifndef BEAN_AST_ASTENUMDECLARATION_H
#define BEAN_AST_ASTENUMDECLARATION_H
#include <vector>
#include "ASTNode.h"
class ASTEnumItemDeclaration;
/**
 * 列挙宣言.
 */
class ASTEnumDeclaration : public ASTNode {
public:
	ASTEnumDeclaration();
	~ASTEnumDeclaration();
	/**
	 * 列挙型の名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * 列挙型の名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 列挙子を追加します.
	 * @param item
	 */
	void addEnumItem(std::shared_ptr<ASTEnumItemDeclaration> item);

	/**
	 * 指定位置の列挙子を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTEnumItemDeclaration> getEnumItemAt(int index) const;

	/**
	 * 列挙子を削除します.
	 * @param index
	 */
	void removeEnumItemAt(int index);

	/**
	 * 列挙子の数を返します.
	 * @return
	 */
	int getEnumItemCount() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_0_H(ASTEnumDeclaration)
private:
	std::shared_ptr<ASTName> name;
	std::vector<std::shared_ptr<ASTEnumItemDeclaration>> enumItemList;
};
#endif // !BEAN_AST_ASTENUMDECLARATION_H
