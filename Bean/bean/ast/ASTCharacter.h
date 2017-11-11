#pragma once
#ifndef BEAN_ENV_ASTCHARACTER_H
#define BEAN_ENV_ASTCHARACTER_H
#include "ASTFactor.h"
#include "../env/Reference.h"
#include "../util/Text.h"
class Character;
class ASTCharacter : public ASTFactor, public Reference {
public:
	ASTCharacter(BChar wc);
#ifdef BTEXT_WIDE
	ASTCharacter(char ch)
		: ASTCharacter(Text::multiToWide(ch)) {

	}
#endif // BTEXT_WIDE
	~ASTCharacter();
	/**
	 * ���̃m�[�h���i�[���镶����Ԃ��܂�.
	 * @return
	 */
	Character* getValue();
	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;
#ifdef BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTCharacter, char)
#endif // BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTCharacter, BChar)
private:
	BChar wc;
	Character* value;
};
#endif // !BEAN_ENV_ASTCHARACTER_H
