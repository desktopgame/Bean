#pragma once
#ifndef BEAN_UTIL_TEXT_H
#define BEAN_UTIL_TEXT_H
#include <functional>
#include <string>
#include <vector>

//���s���ŕ�����ނ�I������
//�f�o�b�O���ꎞ�I��MULTI/WIDE��؂�ւ���Ƃ��͗v���r���h

//
//WindowOS�ł� whcar_t/wstring
//����̓��P�[���ɂ���ďo�͂��؂�ւ��
//Windows�ł͕W���o�͂�Windows�p�̃G���R�[�f�B���O�����o�͂ł��Ȃ�
#if defined(_WIN32) | defined(_WIN64)
#define BTEXT_WIDE
//Linux�n�ł�string(UTF-8)���f�t�@�N�g�炵��
#elif defined(__linux__)
#define BTEXT_WIDE
//����ȊO
#else
#define BTEXT_WIDE
#endif

//�}���`���I�����ꂽ
#ifdef BTEXT_MULTI
	using BChar = char;
	using BString = std::string;
	#define CH(A) A
	#define STR(A) std::string(A)
	#define IS_MULTI true
	#define IS_WIDE false
#endif // BTEXT_MULTI

//���C�h���I�����ꂽ
#ifdef BTEXT_WIDE
	using BChar = wchar_t;
	using BString = std::wstring;
	#define CH(A) L##A
	#define STR(A) L##A
	#define IS_MULTI false
	#define IS_WIDE true
#endif // BTEXT_WIDE

/**
 * �����񑀍�̃��[�e�B���e�B�N���X.
 */
class Text {
public:
	/**
	 * �}���`�o�C�g������������Ȃ�true.
	 * @return
	 */
	static bool isMulti();

	/**
	 * �󔒂Ȃ�true.
	 * @param uc
	 * @return
	 */
	static bool isSpace(BChar uc);

	/**
	 * �A���t�@�x�b�g�Ȃ�true.
	 * @param uc
	 * @return
	 */
	static bool isAlpha(BChar uc);

	/**
	 * �w��̈ꕶ�����A���t�@�x�b�g/���l�Ȃ�true.
	 * @param uc
	 * @return
	 */
	static bool isAlnum(BChar uc);

	/**
	 * �w��̈ꕶ�������l�Ȃ�true.
	 * @param uc
	 * @return
	 */
	static bool isDigit(BChar uc);

	/**
	 * �w��̈ꕶ�������l�^���w�肷�镶���Ȃ�true.
	 * @param uc
	 * @return
	 */
	static bool isSuffixOfDigit(BChar uc);

	/**
	 * ���s�����Ȃ�true.
	 */
	static bool isLineSeparator(BChar uc);

	/**
	 * Bean�ŗL����FQCN�Ȃ�true.
	 * @param str
	 */
	static bool isFQCN(const std::string& str);

	/**
	 * Bean�Ŏg�p�\�ȕ������s�R�[�h��Ԃ��܂�.
	 * @return
	 */
	static BString getLineSeparator();

	/**
	 * �}���`�o�C�g�ŉ��s������Ԃ��܂�.
	 * @return
	 */
	static std::string getMultiLineSeparator();

	/**
	 * ���C�h�L�����N�^�[�ŉ��s������Ԃ��܂�.
	 * @return
	 */
	static std::wstring getWideLineSeparator();

	/**
	 * ���C�h�����񂩂�}���`�o�C�g������.
	 * @param src
	 * @param dst
	 */
	static std::string wideToMulti(const std::wstring& arg_wstr);

	/**
	 * �}���`�o�C�g�����񂩂烏�C�h������.
	 * @param src
	 * @param dst
	 */
	static std::wstring multiToWide(const std::string& arg_str);

	/**
	 * �}���`�o�C�g�����񂩂烏�C�h������.
	 * @param ch
	 */
	static wchar_t multiToWide(char ch);

	/**
	 * src �� c �ŕ������܂�.
	 * @param src
	 * @param c
	 */
	static std::vector<std::string> split(std::string src, char c);

	/**
	 * �w��̈ꕶ����ʂ̕����֒u���������������Ԃ��܂�.
	 * @param src
	 * @param findChar
	 * @param newChar
	 */
	static std::string replace(std::string src, char findChar, char newChar);

	/**
	 * �G�X�P�[�v���ꂽ�����Ȃ� true.
	 * @param bc
	 */
	static bool isEscaped(BChar bc);

	/**
	 * �w��̈ꕶ�����G�X�P�[�v���܂�.
	 * @param bc
	 * @return
	 */
	static BChar escape(BChar bc);

	/**
	 * �w��̕������\���Ȃ�true.
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
