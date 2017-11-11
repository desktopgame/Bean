#pragma once
#ifndef BEAN_ENV_CHARACTER_H
#define BEAN_ENV_CHARACTER_H
#include "Object_.h"
#include "../util/Text.h"
/**
 * �����������N���X.
 */
class Character : public Object_ {
public:
	Character(BChar wc);
	~Character();
	/**
	 * C�̌^�ŕԂ��܂�.
	 * @return
	 */
	wchar_t getCWChar();

	/**
	 * C�̕����ŕԂ��܂�.
	 */
	char getCChar();

	// Object_ ����Čp������܂���
	Object_ * clone() override;
	Object_ * add(Object_ * right) override;
	Object_ * equals(Object_ * right) override;
	bool isPrimitive() override;
	void dump() override;
	Character* asCharacter() override;
protected:
	void lazyLoading() override;
private:
	BChar wc;
};
#endif // !BEAN_ENV_CHARACTER_H


