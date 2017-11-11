#pragma once
#ifndef BEAN_AST_ASTPARAMETER_H
#define BEAN_AST_ASTPARAMETER_H
#include "ASTName.h"
#include "ASTNode.h"
/**
 * ���\�b�h�A���邢�͊֐��̈����ł�.
 */
class ASTParameter : public ASTNode {
public:
	ASTParameter(std::shared_ptr<ASTName> name);
	~ASTParameter();
	/**
	 * ��������Ԃ��܂�.
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
