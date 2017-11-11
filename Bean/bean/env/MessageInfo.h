#pragma once
#ifndef BEAN_ENV_MESSAGEINFO_H
#define BEAN_ENV_MESSAGEINFO_H
#include <memory>
#include <string>
class ClassLoader;
class Class;
class Method;
class Function;
using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
#include "ClassLoaderSkeleton.h"
/**
 * ���̃��\�b�h�Ăяo�����s��ꂽ�X�^�b�N�t���[���Ɋւ�������J�v�Z�������܂�.
 * ��O���ߑ�����Ȃ������Ƃ��ɌĂяo���K�w���_���v���邽�߂Ɏg�p����܂��B
 */
class MessageInfo {
public:
	MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Method* method);
	MessageInfo(ClassLoaderSPtr classLoader, ClassSPtr classz, Function* func);
	~MessageInfo();

	/**
	 * �g�b�v���x���ł��邱�Ƃ��������ʂ� MessageInfo �C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	static MessageInfo* createTop();

	/**
	 * ���̃��b�Z�[�W�������̃\�[�X�R�[�h�����s�����N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	ClassLoaderWPtr getClassLoader() const;

	/**
	 * ���̃��b�Z�[�W�𐶐������N���X��Ԃ��܂�.
	 * @return
	 */
	ClassSPtr getClass() const;

	/**
	 * ���̃��b�Z�[�W�𐶐��������\�b�h��Ԃ��܂�.
	 * @return
	 */
	Method* const getMethod() const;

	/**
	 * �g�b�v���x���Ŏ��s����Ă���ꍇ�̂ݎg�p�\�ł�.
	 * @return
	 */
	Function* const getFunction() const;

	/**
	 * ���ݎ��s���̃R�[�h�ʒu��Ԃ��܂�.
	 * @return
	 */
	std::string getLocation();
private:
	MessageInfo(bool top);
	ClassLoaderWPtr classLoader;
	ClassWPtr classz;
	Method* method;
	Function* func;
	bool top;
};
#endif // !BEAN_ENV_MESSAGEINFO_H


