#pragma once
#ifndef BEAN_ENV_CLASSFORMATEXCEPTION_H
#define BEAN_ENV_CLASSFORMATEXCEPTION_H
#include <stdexcept>
/**
 * �N���X�ǂݍ��ݒ��̍\���G���[�����b�v�����O�ł�.
 */
class ClassFormatException : public std::logic_error {
public:
	ClassFormatException(std::string msg);
	~ClassFormatException();
};
#endif // !BEAN_ENV_CLASSFORMATEXCEPTION_H
