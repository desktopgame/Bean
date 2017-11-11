#pragma once
#ifndef BEAN_ENV_CLASSFORMATEXCEPTION_H
#define BEAN_ENV_CLASSFORMATEXCEPTION_H
#include <stdexcept>
/**
 * クラス読み込み中の構文エラーをラップする例外です.
 */
class ClassFormatException : public std::logic_error {
public:
	ClassFormatException(std::string msg);
	~ClassFormatException();
};
#endif // !BEAN_ENV_CLASSFORMATEXCEPTION_H
