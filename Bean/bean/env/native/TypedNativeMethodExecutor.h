#pragma once
#ifndef BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H
#define BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H
#include <functional>
#include <boost/filesystem.hpp>
#include "NativeCastException.h"
#include "NativeMethodExecutor.h"
#include "../../env/Class.h"
#include "../../env/ClassLoader.h"
#include "../../env/Exception.h"
#include "../../env/String.h"
//
//������args �� �w��ʒu�̗v�f�̃L���X�g���{�s���܂�
//���̃}�N����executeImpl�̒��ł̂ݎg�p�\�ł��B
//t = �^��
//i = �����̔ԍ�
//r = ���҂���^
#define arg_cast(t, i, r) checkCastRequire<t>(args.at(i), r);

/**
 * �l�C�e�B�u���\�b�h���ȒP�Ɏ������邽�߂̃w���p�[�ł�.
 */
class TypedNativeMethodExecutor : public NativeMethodExecutor {
public:
	TypedNativeMethodExecutor();
	virtual ~TypedNativeMethodExecutor();
	Object_ * const execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
	virtual Object_* const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) = 0;

protected:
	/**
	 * �w��̎Q�Ƃ̎��l���L���X�g���ĕԂ��܂�.
	 * @param ref
	 * @param msg
	 * @return
	 */
	template<typename T>
	T* checkCast(Object_* ref, std::string msg);

	/**
	 * �w��̎Q�Ƃ̎��l���L���X�g���ĕԂ��܂�.
	 * @param ref
	 * @param msg
	 * @return
	 */
	template<typename T>
	T* checkCastRequire(Object_* ref, std::string requireType);

	/**
	 * boost�̗�O��bean�Ń��b�v���ăX���[���܂�.
	 * @param proxy
	 * @param e
	 */
	void throw_io_error(Method* proxy, boost::filesystem::filesystem_error e);

	/**
	 * f�Ŕ���������O�����b�v���ăX���[���܂�.
	 * @param proxy
	 * @param f
	 */
	void do_io(Method* proxy, std::function<void()> f);
};

#endif // !BEAN_ENV_NATIVE_TYPEDNATIVEMETHODEXECUTOR_H

template<typename T>
inline T * TypedNativeMethodExecutor::checkCast(Object_ * ref, std::string msg) {
	Object_* val = ref->getValue();
	if (val == NULL || val == nullptr) {
		throw NativeCastException(msg);
	}
	T* ret = dynamic_cast<T*>(val);
	if (ret == NULL || val == nullptr) {
		throw NativeCastException(msg);
	}
	return ret;
}

template<typename T>
inline T * TypedNativeMethodExecutor::checkCastRequire(Object_ * ref, std::string requireType) {
	Object_* val = ref;
	if (val == NULL || val == nullptr) {
		throw NativeCastException("null �� " + requireType + " �֕ϊ��o���܂���");
	}
	T* ret = dynamic_cast<T*>(val);
	if (ret == NULL || val == nullptr) {
		ClassWPtr classz = val->getClass();
		ClassSPtr clsSPtr = classz.lock();
		std::string typeName = clsSPtr == NULL ? "null" : clsSPtr->getName();
		throw NativeCastException(typeName + " �� " + requireType + " �֕ϊ��o���܂���");
	}
	return ret;
}
