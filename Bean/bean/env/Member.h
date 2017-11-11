#pragma once
#ifndef BEAN_ENV_MEMBER_H
#define BEAN_ENV_MEMBER_H
#include <memory>
#include <string>
#include "Modifier.h"
class Class;
using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
/**
 * �t�B�[���h�A���邢�̓��\�b�h�̊��N���X�ł�.
 */
class Member {
public:
	Member(ClassSPtr const classz, Modifier modifier, const std::string& name);
	virtual ~Member() = 0;

	/**
	 * ���̃����o�[�̒�`����Ă���N���X��Ԃ��܂�.
	 * @return
	 */
	ClassWPtr const getClass() const;

	/**
	 * �C���q��Ԃ��܂�.
	 * @return
	 */
	Modifier getModifier() const;

	/**
	 * ���̃����o�[�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::string getName() const;

	/**
	 * ���̃����o�[�̏��݂�\���Z�����O��Ԃ��܂�.
	 * @return
	 */
	virtual std::string getLocation() = 0;
private:
	ClassWPtr classz;
	Modifier modifier;
	std::string name;
};
#endif // !BEAN_ENV_MEMBER_H


 
