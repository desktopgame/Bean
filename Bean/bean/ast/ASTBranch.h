#pragma once
#ifndef BEAN_AST_ASTBRANCH_H
#define BEAN_AST_ASTBRANCH_H
#include <vector>
#include "ASTNode.h"
#include "visitor/ASTVisitor.h"
/**
 * 子要素を持てる要素.
 */
class ASTBranch : public ASTNode {
public:
	ASTBranch();
	virtual ~ASTBranch();
	/**
	 * 末尾に要素を追加します.
	 * @param child
	 */
	void add(ASTNodeSPtr child);

	/**
	 * 指定位置に要素を挿入します.
	 * @param child
	 * @param index
	 */
	void insert(ASTNodeSPtr child, int index);

	/**
	 * 指定位置の要素を削除します.
	 * @param index
	 */
	void remove(int index);

	/**
	 * 全ての子要素を削除.
	 */
	void clear();

	/**
	 * 指定位置の要素を返します.
	 * @param index
	 * @return
	 */
	ASTNodeSPtr getChildrenAt(int index) const;

	/**
	 * 子要素の数を返します.
	 * @return
	 */
	int getChildrenCount() const;
	void accept(ASTVisitor* visitor) override;
	virtual std::string format() const override;


	DECL_MAKE_SHARED_0_H(ASTBranch)
protected:
private:
	std::vector<ASTNodeSPtr> children;
};
#endif // !BEAN_AST_ASTBRANCH_H
