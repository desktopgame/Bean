#pragma once
#ifndef BEAN_AST_ASTBODY_H
#define BEAN_AST_ASTBODY_H
#include "ASTBranch.h"
/**
 * �����̖{�̂ł�.
 * ���ۍ\���؂ł͏ȗ�����܂����A���ۂɂ� { } �ň͂܂�Ă���K�v������܂��B
 */
class ASTBody : public ASTBranch {
public:
	ASTBody();
	~ASTBody();
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTBody)
};
#endif // !BEAN_AST_ASTBODY_H
