#pragma once
#ifndef BEAN_ENV_METHOD_H
#define BEAN_ENV_METHOD_H
#include <memory>
#include <vector>
#include "Member.h"
class Constructor_;
class Object_;
class Parameter;
class Object_;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * �߂�l�ƈ����ŕ\�����葱���ł�.
 */
class Method : public Member {
public:
	Method(ClassSPtr classz, Modifier modifier, std::string name);
	virtual ~Method();

	/**
	 * ���̃��\�b�h�Ɉ�����ǉ����܂�.
	 * @param param
	 */
	virtual void addParameter(Parameter* param);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 * @return
	 */
	virtual Parameter* const getParameterAt(int index) const;

	/**
	 * �w��ʒu�̈������폜���܂�.
	 * @param index
	 */
	virtual void removeParameterAt(int index);

	/**
	 * �S�Ă̈����̐���Ԃ��܂�.
	 * @return
	 */
	virtual int getParameterCount() const;

	/**
	 * ���̃��\�b�h�����s���܂�.
	 * @param invoker
	 * @param args
	 * @param currentClassLoader
	 * @return
	 */
	virtual Object_* const execute(Object_* const invoker, std::vector<Object_*> args, bool currentClassLoader) = 0;

	/**
	 * ���݂̃N���X���[�_�[��ݒ肵�ČĂяo���܂�.
	 * @param invoker
	 * @param args
	 */
	virtual Object_* const execute(Object_* const invoker, std::vector<Object_*> args);

	/**
	 * ���̃��\�b�h���R���X�g���N�^�Ƀ��b�v�����Ƃ��A
	 * �N���X�̃R���e�i�Ƃ��ċ@�\����N���X��Ԃ��܂�.
	 * �f�t�H���g�ł�UserObject��Ԃ��܂��B
	 * @param classz
	 * @param cons
	 * @param args
	 * @return
	 */
	virtual Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args);

	/**
	 * ���̃��\�b�h�̏��݂���ӂɕ\���������Ԃ��܂�.
	 * @return
	 */
	std::string toUID();
	std::string getLocation() override;
private:
	std::vector<Parameter*> parameters;

};
#endif // !BEAN_ENV_METHOD_H
