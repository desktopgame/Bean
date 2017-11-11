#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H
#define BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H
#include <functional>
#include <vector>
#include "../Method.h"
#include "../Object_.h"
#include "../../util/Text.h"
using MsgFactory = std::function<std::string()>;
/**
 * C++�Ŏ�������郁�\�b�h�ł�.
 */
class NativeMethodExecutor {
public:
	NativeMethodExecutor();
	virtual ~NativeMethodExecutor();
	/**
	 * ���̃��\�b�h�����s���܂�.
	 * @param proxy
	 * @param invoker
	 * @param args
	 */
	virtual Object_* const execute(Method* const proxy, Object_* const invoker, std::vector<Object_*> args) = 0;

	/**
	 * Method#newObject���Q�Ƃ��Ă�������.
	 * @param classz
	 * @param cons
	 * @param args
	 * @return
	 */
	virtual Object_* newObject(ClassSPtr classz, Constructor_* cons, std::vector<Object_*> args);
protected:
	//
	//��O
	//
	void throw_(const std::string& className, std::vector<Object_*> args);
	void throw_simple(const std::string& className, std::string msg);

	//
	//���[�e�B���e�B
	//�C���N���[�h�������ɂ�������g�p�o���܂��B
	//

	/**
	 * null��Ԃ��܂�.
	 * @return
	 */
	Object_* getNull();

	/**
	 * Bean��Bool�^�փL���X�g���܂�.
	 * @param b
	 * @return
	 */
	Object_* getBoolean(bool b);

	/**
	 * Bean��Int�^�փL���X�g���܂�.
	 * @param i
	 * @return
	 */
	Object_* getInteger(int i);

	/**
	 * Bean��Char�^�փL���X�g���܂�.
	 * @param bc
	 * @return
	 */
	Object_* getCharacter(BChar bc);
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODEXECUTOR_H


