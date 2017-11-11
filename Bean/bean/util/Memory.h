#pragma once
#ifndef BEAN_UTIL_MEMORY_H
#define BEAN_UTIL_MEMORY_H
#include <memory>
class Object_;
/**
 * ��������A�h���X�Ɋւ��郆�[�e�B���e�B.
 */
class Memory {
public:
	/**
	 * �w��̃I�u�W�F�N�g�̃A�h���X��Ԃ��܂�.
	 * @param p
	 */
	static int getAddres(void* p);

	/**
	 * �w��̃I�u�W�F�N�g�̃A�h���X��\�����܂�.
	 * @param p
	 */
	static void printAddres(void* p);

	/**
	 * �w��̌^��\�� null ��Ԃ��܂�.
	 * @return
	 */
	template<typename T>
	static T* getNull();

	/**
	 * �w��̌^��\�� null ��Ԃ��܂�.
	 * @return
	 */
	template<typename T>
	static std::shared_ptr<T> getSharedNull();

	/** 
	 * �w��̃|�C���^�� null �Ȃ�true.
	 * @param obj
	 * @return
	 */
	static bool isObjNull(Object_* obj);

	/**
	 * �w��̃|�C���^�� null �Ȃ�true.
	 * @param ptr
	 * @return
	 */
	template<typename T>
	static bool isNull(T* ptr);

	/**
	 * �w��̃|�C���^�� null �Ȃ�true.
	 * @param ptr
	 * @return
	 */
	template<typename T>
	static bool isSharedNull(std::shared_ptr<T> ptr);
private:
	Memory();
	~Memory();
};
#include "MemoryImpl.h"
#endif // !BEAN_UTIL_MEMORY_H


