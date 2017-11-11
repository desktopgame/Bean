#pragma once
#ifndef BEAN_UTIL_CONSOLE_H
#define BEAN_UTIL_CONSOLE_H
#include <string>
#include "Text.h"
/**
 * �W��I/O�����b�v����N���X.
 */
class Console {
public:
	/**
	 * �K�v�ɉ����Č^��ϊ����Ă���o�͂��܂�.
	 * @param str
	 */
	static void fixedPrint(const BString& str) {
#ifdef BTEXT_WIDE
		std::string fixed = std::string(str.begin(), str.end());
		print(fixed);
#else
		print(str);
#endif // BTEXT_MULTI
	}

	/**
	 * �K�v�ɉ����Č^��ϊ����Ă���o�͂��܂�.
	 * @param str
	 */
	static void fixedPrintln(const BString& str) {
#ifdef BTEXT_WIDE
		std::string fixed = std::string(str.begin(), str.end());
		println(fixed);
#else
		println(str);
#endif // BTEXT_MULTI
	}

	/**
	 * �w��̕������o�͂��܂�.
	 * @param str
	 */
	static void print(const std::string& str);

	/**
	 * �w��̕��������s�t���ŏo�͂��܂�.
	 * @param str
	 */
	static void println(const std::string& str);

	/**
	 * �R���\�[�������s���͂��܂�.
	 * @return
	 */
	static BString readln();
private:
	Console();
	~Console();
};

#endif // !BEAN_UTIL_CONSOLE_H
