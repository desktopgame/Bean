#pragma once
#ifndef BEAN_AST_ASTPARAMETER_H
#define BEAN_AST_ASTPARAMETER_H
#include "ASTName.h"
#include "ASTNode.h"
/**
 * メソッド、あるいは関数の引数です.
 */
class ASTParameter : public ASTNode {
public:
	ASTParameter(std::shared_ptr<ASTName> name);
	~ASTParameter();
	/**
	 * 引数名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	std::string format() const override;
	DECL_MAKE_SHARED_1_H(ASTParameter, std::shared_ptr<ASTName>)
protected:
private:
	std::shared_ptr<ASTName> name;
	bool isArgs;
};
#endif
