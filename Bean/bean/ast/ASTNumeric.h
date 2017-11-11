#pragma once
#ifndef BEAN_AST_ASTNUMERIC_H
#define BEAN_AST_ASTNUMERIC_H
#include "ASTFactor.h"
#include "../env/Reference.h"
#include "../util/Number.h"
#include "../util/Text.h"
class Numeric;
class Object_;
/**
 * ���l��\���v�f.
 */
class ASTNumeric : public ASTFactor, public Reference {
public:
	ASTNumeric(short val);
	ASTNumeric(int val);
	ASTNumeric(long val);
	ASTNumeric(float val);
	ASTNumeric(double val);
	~ASTNumeric();
	/**
	 * ������Ƃ��Ă̐��l��Ԃ��܂�.
	 * @return
	 */
	BString getSource() const;

	Object_ * eval() override;
	std::string format() const override;
	DECL_MAKE_SHARED_1_H(ASTNumeric, short)
	DECL_MAKE_SHARED_1_H(ASTNumeric, int)
	DECL_MAKE_SHARED_1_H(ASTNumeric, long)
	DECL_MAKE_SHARED_1_H(ASTNumeric, float)
	DECL_MAKE_SHARED_1_H(ASTNumeric, double)
protected:
private:
	/**
	* ���l��Ԃ��܂�.
	* @return
	*/
	Object_* const getValue();
	
	union {
		short s_val;
		int i_val;
		float f_val;
		double d_val;
		long l_val;
	} u;
	bool data_initialized;

	void init(NumberType nt);
	void getValueImpl();
	BString source;
	NumberType type;
	Object_* n;
};
#endif // !BEAN_AST_ASTNUMERIC_H


