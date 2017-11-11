#pragma once
#ifndef BEAN_UTIL_NUMBER_H
#define BEAN_UTIL_NUMBER_H
#include <string>
/**
 * 数値の型.
 */
enum class NumberType {
	Short,
	Int,
	Float,
	Double,
	Long
};

/** 
 * 数値に関するユーティリティクラス.
 */
class Number {
public:
	static const short SHORT_MIN_;
	static const short SHORT_MAX_;

	static const int INTEGER_MIN_;
	static const int INTEGER_MAX_;

	static const long LONG_MIN_;
	static const long LONG_MAX_;

	static const float FLOAT_MIN_;
	static const float FLOAT_MAX_;

	static const double DOUBLE_MIN_;
	static const double DOUBLE_MAX_;

	static const int SHORT_DIGITS;
	static const int INT_DIGITS;
	static const int LONG_DIGITS;
	static const int FLOAT_DIGITS_P;
	static const int FLOAT_DIGITS_S;
	static const int DOUBLE_DIGITS_P;
	static const int DOUBLE_DIGITS_S;
private:
	static int getDigitsPrefix(std::string s);
	static int getDigitsSuffix(std::string s);
	Number();
	~Number();
};
#endif // !BEAN_UTIL_NUMBER_H
