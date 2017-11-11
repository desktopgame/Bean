#pragma once
#ifndef BEAN_AST_ASTENUMDECLARATION_H
#define BEAN_AST_ASTENUMDECLARATION_H
#include <vector>
#include "ASTNode.h"
class ASTEnumItemDeclaration;
/**
 * �񋓐錾.
 */
class ASTEnumDeclaration : public ASTNode {
public:
	ASTEnumDeclaration();
	~ASTEnumDeclaration();
	/**
	 * �񋓌^�̖��O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �񋓌^�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * �񋓎q��ǉ����܂�.
	 * @param item
	 */
	void addEnumItem(std::shared_ptr<ASTEnumItemDeclaration> item);

	/**
	 * �w��ʒu�̗񋓎q��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTEnumItemDeclaration> getEnumItemAt(int index) const;

	/**
	 * �񋓎q���폜���܂�.
	 * @param index
	 */
	void removeEnumItemAt(int index);

	/**
	 * �񋓎q�̐���Ԃ��܂�.
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
