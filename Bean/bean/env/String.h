#pragma once
#ifndef BEAN_ENV_STRING_H
#define BEAN_ENV_STRING_H
#include <string>
#include <unicode/unistr.h>
#include "Object_.h"
#include "../util/Text.h"
class Numeric;
class Boolean;
/**
 * ������z��ň����N���X.
 */
class String : public Object_ {
public:
	
	~String();

	/**
	 * String�I�u�W�F�N�g�������̒����I�u�W�F�N�g�ŕێ������std::wstring���\�[�X�Ƃ���String�𐶐����܂�.
	 * @param fieldPtr
	 * @return
	 */
	static String* const ownedString(BString* fieldPtr);

	/**
	 * �w��̕������\��String�𐶐����܂�.
	 * �\�[�X����V���ȕ�����𐶐����܂��B
	 * @param str
	 * @return
	 */
	static String* const allocString(const std::string& str);

#ifdef BTEXT_WIDE
	static String* const allocString(std::wstring str) {
		String* ret = new String(new BString(str));
		ret->newWString = true;
		return ret;
	}
#endif // BTEXT_WIDE

	/**
	 * �w��̕������\��String�𐶐����܂�.
	 * �N���C�A���g�œ��I�Ɋm�ۂ��ꂽ��������\�[�X�ɂ���ꍇ������g�p���܂��B
	 * @param str
	 */
	static String* const refString(BString* str);

	/**
	 * �\�ߊ�ꂳ�ꂽ�W���̕�����ŕԂ��܂�.
	 * @return
	 */
	BString* const getBString();

	/**
	 * C�̃}���`�o�C�g������ŕԂ��܂�.
	 * @return
	 */
	std::string* const getCString();

	/**
	 * C�̃��C�h������ŕԂ��܂�.
	 * @return
	 */
	BString* const getCWString() const;

	/**
	 * Unicode�K�i�ŕԂ��܂�.
	 * @return
	 */
	icu::UnicodeString* const getUString();

	/**
	 * ���̕�������G���R�[�h�����������Ԃ��܂�.
	 * @param encoding
	 * @return
	 */
	String* encode(const std::string& encoding);

	/**
	 * ���̕�����̒�����w��̕�������������܂�.
	 * @param find
	 * @return
	 */
	Numeric* const indexOf(String* find);

	/**
	 * ���̕�����̒�����pos�ȍ~�Ɍ����w��̕�������������܂�.
	 * @param find
	 * @param pos
	 * @return
	 */
	Numeric* const indexOf(String* find, int pos);

	/**
	 * ���̕�����̌�납��w��̕�������������܂�.
	 * @param find
	 * @return
	 */
	Numeric* const lastIndexOf(String* find);

	/**
	 * ���̕�����̌�납��w��̕�������������܂�.
	 * @param find
	 * @param pos
	 * @return
	 */
	Numeric* const lastIndexOf(String* find, int pos);

	/**
	 * ��������Ԃ��܂�.
	 * @return
	 */
	Numeric* const length();

	/**
	 * ���̕�����̎w��͈̔͂�؂蔲���܂�.
	 * @param offset
	 * @param len
	 * @return
	 */
	String* const substring(int offset, int len);

	/**
	 * ���̕�����̎w��̈ʒu�ɕ������}�����܂�.
	 * @param offset
	 * @param str
	 * @return
	 */
	String* const insert(int offset, String* str);

	/**
	 * ���̕����񂩂�w��͈̔͂���菜���܂�.
	 * @param offset
	 * @param len
	 * @return
	 */
	String* const remove(int offset, int len);

	/**
	 * ���̕����񂪎w��̕����񂩂�J�n����Ȃ�true.
	 * @param head
	 * @return
	 */
	Boolean* const startsWith(String* head);

	/**
	 * ���̕����񂪎w��̕�����ŏI������Ȃ�true.
	 * @param foot
	 * @return
	 */
	Boolean* const endsWith(String* foot);

	// Object_ ����Čp������܂���
	Object_ * clone() override;
	Object_ * add(Object_ * right) override;
	Object_ * equals(Object_ * right) override;
	bool die() override;
	void dump() override;
	String* asString() override;
protected:
	void lazyLoading() override;
private:
	std::string encoding;
	BString* wstring;
	std::string string;
	icu::UnicodeString* ustring;
	void init();
private:
	String(BString* wstring, const std::string& encoding);
	String(BString* wstring);
	String(String* parent);
	String* parent;
	int count;
	bool initCString;
	bool newWString;
};
#endif // !BEAN_ENV_STRING_H


