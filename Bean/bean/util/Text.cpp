#include "Text.h"
#include <algorithm>
#include <assert.h>
#include <codecvt>
#include <sstream>

#if defined(_WIN32)
#include <Windows.h>
#endif

const BChar Text::S = CH('s');
const BChar Text::SS = CH('S');
const BChar Text::I = CH('i');
const BChar Text::II = CH('I');
const BChar Text::L = CH('l');
const BChar Text::LL = CH('L');
const BChar Text::F = CH('f');
const BChar Text::FF = CH('F');
const BChar Text::D = CH('d');
const BChar Text::DD = CH('D');
const BChar Text::LN = CH('\n');
const BChar Text::LR = CH('\r');
const BChar Text::LRLN = CH('\r\n');
const BString Text::EMPTY = STR("");
const BString Text::REI = STR("0");
const BString Text::ZERO = STR("\0");
const BString Text::DOT = STR(".");
const BString Text::OBJECT = STR("Object");
const BString Text::SET = STR("set");
const BString Text::GET = STR("get");
const BString Text::EQ = STR("=");

const BString Text::WIF = STR("if");
const BString Text::WELSE = STR("else");
const BString Text::WELSEIF = STR("elseif");
const BString Text::WFOR = STR("for");
const BString Text::WWHILE = STR("while");
const BString Text::WDEF = STR("def");
const BString Text::WRETURN = STR("return");
const BString Text::WCONTINUE = STR("continue");
const BString Text::WBREAK = STR("break");
const BString Text::WCLASS = STR("class");
const BString Text::WENUM = STR("enum");
const BString Text::WVAR = STR("var");
const BString Text::WUSE = STR("use");
const BString Text::WTRUE = STR("true");
const BString Text::WFALSE = STR("false");
const BString Text::WNULL = STR("null");
const BString Text::WPUBLIC = STR("public");
const BString Text::WSTATIC = STR("static");
const BString Text::WPRIVATE = STR("private");
const BString Text::WPROTECTED = STR("protected");
const BString Text::WFINAL = STR("final");
const BString Text::WTHIS = STR("this");
const BString Text::WSUPER = STR("super");
const BString Text::WTHROW = STR("throw");
const BString Text::WTRY = STR("try");
const BString Text::WCATCH = STR("catch");
const BString Text::WFINALLY = STR("finally");
const BString Text::WLAMBDA = STR("lambda");

std::string Text::mLineSeparator = std::string();
std::wstring Text::wLineSeparator = std::wstring();
std::vector<BString> Text::words = std::vector<BString>();

bool Text::isMulti() {
#if defined (BTEXT_MULTI)
	return true;
#else
	return false;
#endif
}

//public method---
bool Text::isSpace(BChar uc) {
#if defined(BTEXT_MULTI)
	return iswspace(uc);
//	return isspace(uc);
#elif defined(BTEXT_WIDE)
	return iswspace(uc);
#endif // BTEXT_MULTI
}

bool Text::isAlpha(BChar uc) {
#if defined(BTEXT_MULTI)
	return iswalpha(uc);
//	return isalpha(uc);
#elif defined(BTEXT_WIDE)
	return iswalpha(uc);
#endif // BTEXT_MULTI
}

bool Text::isAlnum(BChar uc) {
#if defined(BTEXT_MULTI)
	return iswalnum(uc);
//	return isalnum(uc);
#elif defined(BTEXT_WIDE)
	return iswalnum(uc);
#endif // BTEXT_MULTI
}

bool Text::isDigit(BChar uc) {
#if defined(BTEXT_MULTI)
	return isdigit(uc);
//	return isdigit(uc);
#elif defined(BTEXT_WIDE)
	return iswdigit(uc);
#endif // BTEXT_MULTI
}

bool Text::isSuffixOfDigit(BChar uc) {
	return 
		(uc == S || uc == I || uc == L || uc == F || uc == D) ||
		(uc == SS || uc == II || uc == LL || uc == FF || uc == DD);
}

bool Text::isLineSeparator(BChar c) {
	return c == LN || c == LR || c == LRLN;
}

bool Text::isFQCN(const std::string & str) {
	for (auto ch : str) {
		if ((!isalpha(ch) &&
			 !isdigit(ch)  &&
			 ch != '_') &&
			 ch != '.') {
			return false;
		}
	}
	return true;
}

BString Text::getLineSeparator() {
#ifdef BTEXT_MULTI
	return getMultiLineSeparator();
#endif // BTEXT_MULTI
#ifdef BTEXT_WIDE
	return getWideLineSeparator();
#endif // BTEXT_WIDE
}

std::string Text::getMultiLineSeparator() {
	if (mLineSeparator.empty()) {
		std::stringstream ss;
		ss << std::endl;
		Text::mLineSeparator = ss.str();
	}
	return mLineSeparator;
}

std::wstring Text::getWideLineSeparator() {
	if (mLineSeparator.empty()) {
		std::wstringstream ss;
		ss << std::endl;
		Text::wLineSeparator = ss.str();
	}
	return wLineSeparator;
}

std::string Text::wideToMulti(const std::wstring & arg_wstr) {
#if defined(_WIN32)
	static_assert(sizeof(wchar_t) == 2, "this function is windows only");
	const int len = ::WideCharToMultiByte(CP_ACP, 0, arg_wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string re(len * 2, '\0');
	if (!::WideCharToMultiByte(CP_ACP, 0, arg_wstr.c_str(), -1, &re[0], len, nullptr, nullptr)) {
		const auto ec = ::GetLastError();
		switch (ec) {
			case ERROR_INSUFFICIENT_BUFFER:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INSUFFICIENT_BUFFER"); break;
			case ERROR_INVALID_FLAGS:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INVALID_FLAGS"); break;
			case ERROR_INVALID_PARAMETER:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INVALID_PARAMETER"); break;
			default:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: unknown(" + std::to_string(ec) + ')'); break;
		}
	}
	const std::size_t real_len = std::strlen(re.c_str());
	re.resize(real_len);
	re.shrink_to_fit();
	return re;
#else
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(arg_wstr);
#endif
}

std::wstring Text::multiToWide(const std::string & arg_str) {
#if defined(_WIN32)
	static_assert(sizeof(wchar_t) == 2, "this function is windows only");
	const int len = ::MultiByteToWideChar(CP_ACP, 0, arg_str.c_str(), -1, nullptr, 0);
	std::wstring re(len * 2 + 2, L'\0');
	if (!::MultiByteToWideChar(CP_ACP, 0, arg_str.c_str(), -1, &re[0], len)) {
		const auto ec = ::GetLastError();
		switch (ec) {
			case ERROR_INSUFFICIENT_BUFFER:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INSUFFICIENT_BUFFER"); break;
			case ERROR_INVALID_FLAGS:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INVALID_FLAGS"); break;
			case ERROR_INVALID_PARAMETER:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_INVALID_PARAMETER"); break;
			case ERROR_NO_UNICODE_TRANSLATION:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: ERROR_NO_UNICODE_TRANSLATION"); break;
			default:
				throw std::runtime_error("in function utf_16_to_shift_jis, WideCharToMultiByte fail. cause: unknown(" + std::to_string(ec) + ')'); break;
		}
	}
	const std::size_t real_len = std::wcslen(re.c_str());
	re.resize(real_len);
	re.shrink_to_fit();
	return re;
#else
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(arg_str);
#endif
}

wchar_t Text::multiToWide(char ch) {
	std::wstring wc(sizeof(char), L'#');
	mbstowcs(&wc[0], &ch, sizeof(char));
	return wc[0];
}

std::vector<std::string> Text::split(std::string src, char c) {
	std::vector<std::string> ret = std::vector<std::string>();
	std::string buff;
	for (int i = 0; i < src.length(); i++) {
		char elem = src.at(i);
		if (elem == c) {
			ret.push_back(buff);
			buff = std::string();
		} else {
			buff.push_back(elem);
		}
	}
	if (ret.empty()) {
		ret.push_back(src);
	} else {
		ret.push_back(buff);
	}
	return ret;
}

std::string Text::replace(std::string src, char findChar, char newChar) {
	std::string buff = std::string();
	for (int i = 0; i < src.length(); i++) {
		char c = src.at(i);
		if (c == findChar) {
			c = newChar;
		}
		buff.push_back(c);
	}
	return buff;
}

bool Text::isEscaped(BChar bc) {
	return
		bc == '\r' ||
		bc == '\n' ||
		bc == '\b' ||
		bc == '\f' ||
		bc == '\t';
}

BChar Text::escape(BChar bc) {
	switch (bc) {
		case 'b':
			return '\b';
		case 'f':
			return '\f';
		case 'r':
			return '\r';
		case 'n':
			return '\n';
		case 't':
			return '\t';
		case '\'':
			return '\'';
		case '\"':
			return '\"';
	}
	return bc;
}

bool Text::isWord(BString b) {
	if (words.empty()) {
		words.emplace_back(WIF);
		words.emplace_back(WELSE);
		words.emplace_back(WELSEIF);
		words.emplace_back(WFOR);
		words.emplace_back(WWHILE);
		words.emplace_back(WDEF);
		words.emplace_back(WRETURN);
		words.emplace_back(WCONTINUE);
		words.emplace_back(WBREAK);
		words.emplace_back(WCLASS);
		words.emplace_back(WENUM);
		words.emplace_back(WVAR);
		words.emplace_back(WUSE);
		words.emplace_back(WTRUE);
		words.emplace_back(WFALSE);
		words.emplace_back(WNULL);
		words.emplace_back(WPUBLIC);
		words.emplace_back(WPRIVATE);
		words.emplace_back(WPROTECTED);
		words.emplace_back(WFINAL);
		words.emplace_back(WTHIS);
		words.emplace_back(WSUPER);
		words.emplace_back(WTHROW);
		words.emplace_back(WTRY);
		words.emplace_back(WCATCH);
		words.emplace_back(WFINALLY);
		words.emplace_back(WLAMBDA);
		std::sort(words.begin(), words.end());
	}
	return std::binary_search(words.begin(), words.end(), b);
}
//---public method
