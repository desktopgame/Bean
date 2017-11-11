#pragma once
#ifndef BEAN_ENV_POINTER_POINTER_H
#define BEAN_ENV_POINTER_POINTER_H
#include <memory>
#include <string>
class Object_;
class Pointer;
using PointerSPtr = std::shared_ptr<Pointer>;
using PointerWPtr = std::weak_ptr<Pointer>;
/**
 * �I�u�W�F�N�g�̊i�[��.
 */
class Pointer {
public:
	Pointer();
	virtual ~Pointer() = 0;
	/**
	 * �l�ֈϏ����܂�.
	 */
	Object_* operator->();

	/**
	 * �l���㏑�����܂�.
	 * @param value
	 */
	virtual void setValue(Object_* obj) = 0;

	/**
	 * �l��Ԃ��܂�.
	 * @return
	 */
	virtual Object_* getValue() = 0;

	/**
	 * ����\�Ȃ�true.
	 * @return
	 */
	virtual bool isAssignable() = 0;

	/**
	 * ���̕ϐ��̏��݂�\���܂�.
	 * @return
	 */
	virtual std::string getLocation() = 0;
private:
};
#endif // !BEAN_ENV_POINTER_POINTER_H
