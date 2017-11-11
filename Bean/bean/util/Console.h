#pragma once
#ifndef BEAN_UTIL_CONSOLE_H
#define BEAN_UTIL_CONSOLE_H
#include <string>
#include "Text.h"
/**
 * 標準I/Oをラップするクラス.
 */
class Console {
public:
	/**
	 * 必要に応じて型を変換してから出力します.
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
	 * 必要に応じて型を変換してから出力します.
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
	 * 指定の文字を出力します.
	 * @param str
	 */
	static void print(const std::string& str);

	/**
	 * 指定の文字を改行付きで出力します.
	 * @param str
	 */
	static void println(const std::string& str);

	/**
	 * コンソールから一行入力します.
	 * @return
	 */
	static BString readln();
private:
	Console();
	~Console();
};

#endif // !BEAN_UTIL_CONSOLE_H
