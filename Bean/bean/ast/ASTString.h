#pragma once
#ifndef BEAN_AST_ASTSTRING_H
#define BEAN_AST_ASTSTRING_H
#include "ASTFactor.h"
#include "../env/Reference.h"
#include "../env/String.h"
#include "../util/Text.h"
/**
 * String�^�̒l������m�[�h�ł�.
 */
class ASTString : public ASTFactor, public Reference {
public:
	ASTString(const BString& src);
#ifdef BTEXT_WIDE
	ASTString(const std::string& str)
		: ASTString(Text::multiToWide(str)) {

	}
#endif // BTEXT_WIDE
	~ASTString();
	std::string format() const override;
	/**
	 * ���̃m�[�h���i�[���镶�����Ԃ��܂�.
	 * @return
	 */
	String* getValue();
	virtual Object_ * eval() override;
//	void deleteObject(Object_ * o) override;
#ifdef BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTString, std::string)
#endif // BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTString, BString)
protected:
private:
	BString src;
	String* value;
	Reference* ref;
};
#endif // !BEAN_AST_ASTSTRING_H


