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
 * 文字を配列で扱うクラス.
 */
class String : public Object_ {
public:
	
	~String();

	/**
	 * Stringオブジェクトより寿命の長いオブジェクトで保持されるstd::wstringをソースとしてStringを生成します.
	 * @param fieldPtr
	 * @return
	 */
	static String* const ownedString(BString* fieldPtr);

	/**
	 * 指定の文字列を表すStringを生成します.
	 * ソースから新たな文字列を生成します。
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
	 * 指定の文字列を表すStringを生成します.
	 * クライアントで動的に確保された文字列をソースにする場合これを使用します。
	 * @param str
	 */
	static String* const refString(BString* str);

	/**
	 * 予め基底された標準の文字列で返します.
	 * @return
	 */
	BString* const getBString();

	/**
	 * Cのマルチバイト文字列で返します.
	 * @return
	 */
	std::string* const getCString();

	/**
	 * Cのワイド文字列で返します.
	 * @return
	 */
	BString* const getCWString() const;

	/**
	 * Unicode規格で返します.
	 * @return
	 */
	icu::UnicodeString* const getUString();

	/**
	 * この文字列をエンコードした文字列を返します.
	 * @param encoding
	 * @return
	 */
	String* encode(const std::string& encoding);

	/**
	 * この文字列の中から指定の文字列を検索します.
	 * @param find
	 * @return
	 */
	Numeric* const indexOf(String* find);

	/**
	 * この文字列の中からpos以降に現れる指定の文字列を検索します.
	 * @param find
	 * @param pos
	 * @return
	 */
	Numeric* const indexOf(String* find, int pos);

	/**
	 * この文字列の後ろから指定の文字列を検索します.
	 * @param find
	 * @return
	 */
	Numeric* const lastIndexOf(String* find);

	/**
	 * この文字列の後ろから指定の文字列を検索します.
	 * @param find
	 * @param pos
	 * @return
	 */
	Numeric* const lastIndexOf(String* find, int pos);

	/**
	 * 文字数を返します.
	 * @return
	 */
	Numeric* const length();

	/**
	 * この文字列の指定の範囲を切り抜きます.
	 * @param offset
	 * @param len
	 * @return
	 */
	String* const substring(int offset, int len);

	/**
	 * この文字列の指定の位置に文字列を挿入します.
	 * @param offset
	 * @param str
	 * @return
	 */
	String* const insert(int offset, String* str);

	/**
	 * この文字列から指定の範囲を取り除きます.
	 * @param offset
	 * @param len
	 * @return
	 */
	String* const remove(int offset, int len);

	/**
	 * この文字列が指定の文字列から開始するならtrue.
	 * @param head
	 * @return
	 */
	Boolean* const startsWith(String* head);

	/**
	 * この文字列が指定の文字列で終了するならtrue.
	 * @param foot
	 * @return
	 */
	Boolean* const endsWith(String* foot);

	// Object_ を介して継承されました
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


