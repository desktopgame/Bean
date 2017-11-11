#pragma once
#ifndef BEAN_AST_ASTBRANCH_H
#define BEAN_AST_ASTBRANCH_H
#include <vector>
#include "ASTNode.h"
#include "visitor/ASTVisitor.h"
/**
 * �q�v�f�����Ă�v�f.
 */
class ASTBranch : public ASTNode {
public:
	ASTBranch();
	virtual ~ASTBranch();
	/**
	 * �����ɗv�f��ǉ����܂�.
	 * @param child
	 */
	void add(ASTNodeSPtr child);

	/**
	 * �w��ʒu�ɗv�f��}�����܂�.
	 * @param child
	 * @param index
	 */
	void insert(ASTNodeSPtr child, int index);

	/**
	 * �w��ʒu�̗v�f���폜���܂�.
	 * @param index
	 */
	void remove(int index);

	/**
	 * �S�Ă̎q�v�f���폜.
	 */
	void clear();

	/**
	 * �w��ʒu�̗v�f��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	ASTNodeSPtr getChildrenAt(int index) const;

	/**
	 * �q�v�f�̐���Ԃ��܂�.
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
