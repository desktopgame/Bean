#pragma once
#ifndef BEAN_AST_ASTPOINTER_H
#define BEAN_AST_ASTPOINTER_H
#include "ASTFactor.h"
#include "../env/pointer/Pointer.h"
/**
 * ����\�ȃA�h���X.
 */
class ASTPointer : public ASTFactor {
public:
	ASTPointer();
	/**
	 * �����̃A�h���X��Ԃ��܂�.
	 * @return
	 */
	virtual PointerSPtr getReference() = 0;
protected:
	virtual ~ASTPointer() = 0;
};
#endif // !BEAN_AST_ASTPOINTER_H


