#pragma once
#ifndef BEAN_UTIL_TEXT_H
#define BEAN_UTIL_TEXT_H
#include <functional>
#include <string>
#include <vector>

//実行環境で文字種類を選択する
//デバッグ等一時的にMULTI/WIDEを切り替えるときは要リビルド

//
//WindowOSでは whcar_t/wstring
//これはロケールによって出力が切り替わる
//Windowsでは標準出力にWindows用のエンコーディングしか出力できない
#if defined(_WIN32) | defined(_WIN64)
#define BTEXT_WIDE
//Linux系ではstring(UTF-8)がデファクトらしい
#elif defined(__linux__)
#define BTEXT_WIDE
//それ以外
#else
#define BTEXT_WIDE
#endif

//マルチが選択された
#ifdef BTEXT_MULTI
	using BChar = char;
	using BString = std::string;
	#define CH(A) A
	#define STR(A) std::string(A)
	#define IS_MULTI true
	#define IS_WIDE false
#endif // BTEXT_MULTI

//ワイドが選択された
#ifdef BTEXT_WIDE
	using BChar = wchar_t;
	using BString = std::wstring;
	#define CH(A) L##A
	#define STR(A) L##A
	#define IS_MULTI false
	#define IS_WIDE true
#endif // BTEXT_WIDE

/**
 * 文字列操作のユーティリティクラス.
 */
class Text {
public:
	/**
	 * マルチバイト文字列を扱うならtrue.
	 * @return
	 */
	static bool isMulti();

	/**
	 * 空白ならtrue.
	 * @param uc
	 * @return
	 */
	static bool isSpace(BChar uc);

	/**
	 * アルファベットならtrue.
	 * @param uc
	 * @return
	 */
	static bool isAlpha(BChar uc);

	/**
	 * 指定の一文字がアルファベット/数値ならtrue.
	 * @param uc
	 * @return
	 */
	static bool isAlnum(BChar uc);

	/**
	 * 指定の一文字が数値ならtrue.
	 * @param uc
	 * @return
	 */
	static bool isDigit(BChar uc);

	/**
	 * 指定の一文字が数値型を指定する文字ならtrue.
	 * @param uc
	 * @return
	 */
	static bool isSuffixOfDigit(BChar uc);

	/**
	 * 改行文字ならtrue.
	 */
	static bool isLineSeparator(BChar uc);

	/**
	 * Beanで有効なFQCNならtrue.
	 * @param str
	 */
	static bool isFQCN(const std::string& str);

	/**
	 * Beanで使用可能な文字改行コードを返します.
	 * @return
	 */
	static BString getLineSeparator();

	/**
	 * マルチバイトで改行文字を返します.
	 * @return
	 */
	static std::string getMultiLineSeparator();

	/**
	 * ワイドキャラクターで改行文字を返します.
	 * @return
	 */
	static std::wstring getWideLineSeparator();

	/**
	 * ワイド文字列からマルチバイト文字列.
	 * @param src
	 * @param dst
	 */
	static std::string wideToMulti(const std::wstring& arg_wstr);

	/**
	 * マルチバイト文字列からワイド文字列.
	 * @param src
	 * @param dst
	 */
	static std::wstring multiToWide(const std::string& arg_str);

	/**
	 * マルチバイト文字列からワイド文字列.
	 * @param ch
	 */
	static wchar_t multiToWide(char ch);

	/**
	 * src を c で分割します.
	 * @param src
	 * @param c
	 */
	static std::vector<std::string> split(std::string src, char c);

	/**
	 * 指定の一文字を別の文字へ置き換えた文字列を返します.
	 * @param src
	 * @param findChar
	 * @param newChar
	 */
	static std::string replace(std::string src, char findChar, char newChar);

	/**
	 * エスケープされた文字なら true.
	 * @param bc
	 */
	static bool isEscaped(BChar bc);

	/**
	 * 指定の一文字をエスケープします.
	 * @param bc
	 * @return
	 */
	static BChar escape(BChar bc);

	/**
	 * 指定の文字が予約語ならtrue.
	 * @param bs
	 */
	static bool isWord(BString b);

	static const BChar S;
	static const BChar SS;
	static const BChar I;
	static const BChar II;
	static const BChar L;
	static const BChar LL;
	static const BChar F;
	static const BChar FF;
	static const BChar D;
	static const BChar DD;
	static const BChar LN;
	static const BChar LR;
	static const BChar LRLN;
	static const BString EMPTY;
	static const BString REI;
	static const BString ZERO;
	static const BString DOT;
	static const BString OBJECT;
	static const BString SET;
	static const BString GET;
	static const BString EQ;
	
	static const BString WIF;
	static const BString WELSE;
	static const BString WELSEIF;
	static const BString WFOR;
	static const BString WWHILE;
	static const BString WDEF;
	static const BString WRETURN;
	static const BString WCONTINUE;
	static const BString WBREAK;
	static const BString WCLASS;
	static const BString WENUM;
	static const BString WVAR;
	static const BString WUSE;
	static const BString WTRUE;
	static const BString WFALSE;
	static const BString WNULL;
	static const BString WPUBLIC;
	static const BString WSTATIC;
	static const BString WPRIVATE;
	static const BString WPROTECTED;
	static const BString WFINAL;
	static const BString WTHIS;
	static const BString WSUPER;
	static const BString WTHROW;
	static const BString WTRY;
	static const BString WCATCH;
	static const BString WFINALLY;
	static const BString WLAMBDA;
private:
	static std::string mLineSeparator;
	static std::wstring wLineSeparator;
	static std::vector<BString> words;
	Text() = default;
	~Text() = default;
};
#endif // !BEAN_UTIL_TEXT_H
