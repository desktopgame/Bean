#pragma once
#ifndef BEAN_AST_ASTENUMITEMDECLARATION_H
#define BEAN_AST_ASTENUMITEMDECLARATION_H
#include "ASTNode.h"
class ASTFactor;
class ASTName;
/**
 * �񋓎q�̐錾.
 */
class ASTEnumItemDeclaration : public ASTNode {
public:
	ASTEnumItemDeclaration();
	~ASTEnumItemDeclaration();
	/**
	 * �񋓎q�̏����l��ݒ肵�܂�.
	 * @param value
	 */
	void setValue(std::shared_ptr<ASTFactor> value);

	/**
	 * �񋓎q�̏����l��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getValue() const;

	/**
	 * �񋓎q�̖��O��ݒ肵�܂�.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * �񋓎q�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;
	DECL_MAKE_SHARED_0_H(ASTEnumItemDeclaration)
private:
	std::shared_ptr<ASTFactor> value;
	std::shared_ptr<ASTName> name;
};
#endif
