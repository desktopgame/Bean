#pragma once
#ifndef BEAN_AST_ASTVARIABLE_H
#define BEAN_AST_ASTVARIABLE_H
#include "ASTFactor.h"
#include "ASTPointer.h"
#include "../env/pointer/Pointer.h"
class ASTName;
/**
 * 変数.
 */
class ASTVariable : public ASTPointer {
public:
	ASTVariable(std::shared_ptr<ASTName> name);
	~ASTVariable();

	/**
	 * 変数名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	std::string format() const override;
	// ASTFactor を介して継承されました
	Object_ * eval() override;
	PointerSPtr getReference() override;
	bool isStaticReceiver() override;
	std::string getStaticClassName() override;
	DECL_MAKE_SHARED_1_H(ASTVariable, std::shared_ptr<ASTName>)
protected:
	Object_* evalThrow() override;
private:
	std::shared_ptr<ASTName> name;
	PointerSPtr pointee;
};
#endif // !BEAN_AST_ASTVARIABLE_H


