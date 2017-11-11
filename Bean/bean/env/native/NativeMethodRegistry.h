#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
#define BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
#include <unordered_map>
#include "NativeMethodExecutor.h"
/**
 * C++�Ŏ��s����郁�\�b�h�̃��W�X�g���ł�.
 */
class NativeMethodRegistry {
public:
	NativeMethodRegistry(const NativeMethodRegistry&) = delete;
	NativeMethodRegistry& operator=(const NativeMethodRegistry&) = delete;
	NativeMethodRegistry(NativeMethodRegistry&&) = delete;
	NativeMethodRegistry& operator=(NativeMethodRegistry&&) = delete;
	/**
	* �B��̃C���X�^���X��Ԃ��܂�.
	* @return
	*/
	static NativeMethodRegistry* const getInstance() {
		static NativeMethodRegistry inst;
		return &inst;
	}

	/**
	 * �w��̃��\�b�h�����W�X�g���ɕR�Â��܂�.
	 * @param name ���O���.�N���X��#(�����̐�)
	 * @param nme
	 */
	void add(const std::string& name, NativeMethodExecutor* nme);

	/**
	 * �w��̖��O�̃��\�b�h��Ԃ��܂�.
	 * �܂܂�Ȃ��ꍇ�� nullptr ��Ԃ��܂��B
	 * @param name ���O���.�N���X��#(�����̐�)
	 * @return
	 */
	NativeMethodExecutor* const get(const std::string& name);

	/**
	 * �w��̃��\�b�h���܂܂�邩�ǂ�����Ԃ��܂�.
	 * @param name ���O���.�N���X��#(�����̐�)
	 * @return
	 */
	bool contains(const std::string& name);

	/**
	 * �w��̃��\�b�h���폜���܂�.
	 * @parma name ���O���.�N���X��#(�����̐�)
	 */
	void remove(const std::string& name);
	
	/**
	 * �S�Ẵ��\�b�h���폜���܂�.
	 */
	void clear();
private:
	NativeMethodRegistry() {
		this->map = std::unordered_map<std::string, NativeMethodExecutor*>();
	}
	~NativeMethodRegistry() {
		clear();
	}
	std::unordered_map<std::string, NativeMethodExecutor*> map;
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
