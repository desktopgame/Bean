#include "Number.h"
#include <limits>

const short Number::SHORT_MIN_ = std::numeric_limits<short>::min();
const short Number::SHORT_MAX_ = std::numeric_limits<short>::max();

const int Number::INTEGER_MIN_ = std::numeric_limits<int>::min();
const int Number::INTEGER_MAX_ = std::numeric_limits<int>::max();

const long Number::LONG_MIN_ = std::numeric_limits<long>::min();
const long Number::LONG_MAX_ = std::numeric_limits<long>::max();

const float Number::FLOAT_MIN_ = std::numeric_limits<float>::min();
const float Number::FLOAT_MAX_ = std::numeric_limits<float>::max();

const double Number::DOUBLE_MIN_ = std::numeric_limits<double>::min();
const double Number::DOUBLE_MAX_ = std::numeric_limits<double>::max();

const int Number::SHORT_DIGITS = static_cast<int>(std::to_string(SHORT_MIN_).length());
const int Number::INT_DIGITS = static_cast<int>(std::to_string(INTEGER_MIN_).length());
const int Number::LONG_DIGITS = static_cast<int>(std::to_string(LONG_MIN_).length());
const int Number::FLOAT_DIGITS_P = getDigitsPrefix(std::to_string(FLOAT_MIN_));
const int Number::FLOAT_DIGITS_S = getDigitsSuffix(std::to_string(FLOAT_MIN_));
const int Number::DOUBLE_DIGITS_P = getDigitsPrefix(std::to_string(DOUBLE_MIN_));
const int Number::DOUBLE_DIGITS_S = getDigitsSuffix(std::to_string(DOUBLE_MIN_));

//private method---
int Number::getDigitsPrefix(std::string s) {
	int dot = s.find(".");
	if (dot == std::string::npos) {
		return static_cast<int>(s.length());
	}
	return dot;
}

int Number::getDigitsSuffix(std::string s) {
	int dot = s.find(".");
	if (dot == std::string::npos) {
		return static_cast<int>(s.length());
	}
	int len = static_cast<int>(s.length());
	return len - dot;
}

Number::Number() {
}

Number::~Number() {
}
//---private method