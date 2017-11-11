#pragma once
#ifndef BEAN_AST_ASTFIELDACCESS_H
#define BEAN_AST_ASTFIELDACCESS_H
#include "ASTPointer.h"
/**
 * hoge.piyo.
 */
class ASTFieldAccess : public ASTPointer {
public:
	ASTFieldAccess();
	~ASTFieldAccess();
	/**
	 * プロパティを書き換えられるインスタンスを設定します.
	 * @param parent
	 */
	void setParent(std::shared_ptr<ASTFactor> parent);

	/**
	 * プロパティを書き換えられるインスタンスを返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getParent() const;

	/**
	 * プロパティ名を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * プロパティ名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;
	
	/**
	 * フィールドへの参照を返します.
	 * @return
	 */
	PointerSPtr getReference() override;

	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTFieldAccess)
protected:
	Object_* evalThrow() override;
private:
	std::shared_ptr<ASTFactor> parent;
	std::shared_ptr<ASTName> name;
	PointerSPtr pointee;
};
#endif // !BEAN_AST_ASTFIELDACCESS_H


