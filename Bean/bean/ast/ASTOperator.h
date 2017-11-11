#pragma once
#ifndef BEAN_AST_ASTOPERATOR_H
#define BEAN_AST_ASTOPERATOR_H
#include "ASTFactor.h"
/**
 * ���Z�q�̊��N���X�ł�.
 * �D��x�ƌ��������`���܂��B
 */
class ASTOperator : public ASTFactor {
public:
	ASTOperator();
	virtual Object_* eval() = 0;
protected:
	virtual ~ASTOperator() = 0;
};
#endif // !BEAN_AST_ASTOPERATOR_H


