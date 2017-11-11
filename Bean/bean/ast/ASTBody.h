#pragma once
#ifndef BEAN_AST_ASTBODY_H
#define BEAN_AST_ASTBODY_H
#include "ASTBranch.h"
/**
 * 処理の本体です.
 * 抽象構文木では省略されますが、実際には { } で囲まれている必要があります。
 */
class ASTBody : public ASTBranch {
public:
	ASTBody();
	~ASTBody();
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTBody)
};
#endif // !BEAN_AST_ASTBODY_H
