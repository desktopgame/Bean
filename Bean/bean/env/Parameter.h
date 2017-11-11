#pragma once
#ifndef BEAN_ENV_PARAMETER_H
#define BEAN_ENV_PARAMETER_H
#include <string>
/**
 * ���\�b�h�A�R���X�g���N�^�̈��������f�������܂�.
 */
class Parameter {
public:
	Parameter(const std::string& name);
	~Parameter();
	/**
	 * ���̈����̖��O��Ԃ��܂�.
	 * @return
	 */
	std::string getName();

	/**
	 * �������܂�.
	 * @return
	 */
	Parameter* clone();
private:
	std::string name;
};
#endif // !BEAN_ENV_PARAMETER_H


