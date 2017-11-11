#pragma once
#ifndef BEAN_AST_ASTPOINTER_H
#define BEAN_AST_ASTPOINTER_H
#include "ASTFactor.h"
#include "../env/pointer/Pointer.h"
/**
 * 代入可能なアドレス.
 */
class ASTPointer : public ASTFactor {
public:
	ASTPointer();
	/**
	 * 代入先のアドレスを返します.
	 * @return
	 */
	virtual PointerSPtr getReference() = 0;
protected:
	virtual ~ASTPointer() = 0;
};
#endif // !BEAN_AST_ASTPOINTER_H


