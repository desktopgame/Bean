#pragma once
#ifndef BEAN_ENV_CHARACTER_H
#define BEAN_ENV_CHARACTER_H
#include "Object_.h"
#include "../util/Text.h"
/**
 * 文字を扱うクラス.
 */
class Character : public Object_ {
public:
	Character(BChar wc);
	~Character();
	/**
	 * Cの型で返します.
	 * @return
	 */
	wchar_t getCWChar();

	/**
	 * Cの文字で返します.
	 */
	char getCChar();

	// Object_ を介して継承されました
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


