#pragma once
#ifndef BEAN_AST_ASTOPERATOR_H
#define BEAN_AST_ASTOPERATOR_H
#include "ASTFactor.h"
/**
 * 演算子の基底クラスです.
 * 優先度と結合性を定義します。
 */
class ASTOperator : public ASTFactor {
public:
	ASTOperator();
	virtual Object_* eval() = 0;
protected:
	virtual ~ASTOperator() = 0;
};
#endif // !BEAN_AST_ASTOPERATOR_H


