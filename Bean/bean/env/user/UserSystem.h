#pragma once
#ifndef BEAN_ENV_USER_USERSYSTEM_H
#define BEAN_ENV_USER_USERSYSTEM_H
#include "../../util/Properties.h"
#include "../../util/Text.h"
/**
 * ���[�U�ɂ���ď��������\�ȃ}�b�v.
 * ���ϐ��̑�ւƂ��Ďg�p����܂��B
 */
class UserSystem {
public:
	UserSystem(const UserSystem&) = delete;
	UserSystem& operator=(const UserSystem&) = delete;
	UserSystem(UserSystem&&) = delete;
	UserSystem& operator=(UserSystem&&) = delete;
	/**
	* �B��̃C���X�^���X��Ԃ��܂�.
	* @return
	*/
	static UserSystem* const getInstance() {
		static UserSystem inst;
		return &inst;
	}

	/**
	 * Bean�ݒ�t�@�C���ւ̃p�X��Ԃ��܂�.
	 */
	static std::string getSysPath();

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	void put(const std::string& key, const std::string& val);
	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	void put(const std::string& key, const char* val);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	template<typename T>
	void put(const std::string& key, T val);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	std::string get(const std::string& key);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	std::string str(const std::string& key);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	std::string str(const std::string& key, const std::string& val);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	template<typename T>
	T value(const std::string& key);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	template<typename T>
	T value(const std::string& key, T defaultValue);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	std::string remove(const std::string& key);

	/**
	 * Properties �ւ� �Ϗ��ł�.
	 */
	bool contains(const std::string& key);

	/**
	 * �}�b�v���f�t�H���g�����ɑ��݂���t�@�C������ǂݏo���܂�.
	 */
	static void initialize();

	/**
	 * �}�b�v���f�t�H���g�ŏ㏑�����܂�.
	 */
	void defaults();

	/**
	 * �}�b�v���N���A���Ă���w��̃t�@�C����ǂݍ��݂܂�.
	 * @param filePath
	 */
	void load(std::string filePath);

	/**
	 * ���݂̃}�b�v�̓��e���t�@�C���֏����o���܂�.
	 * @param filePath
	 */
	void apply(std::string filePath);

	/**
	 * �C�x���g���X�i�[�̈ꗗ��Ԃ��܂�.
	 * @return
	 */
	PropertyChangeListenerList* onPropertyChange();

	static const std::string LIB_PATH_KEY;
	static const std::string DEFAULT_USE_NAMESPACES;
	static const std::string DEFAULT_USE_CLASSES;
	static const std::string PERFORMANCETEST;
	static const std::string GC_REPORT;
	static const std::string GC_TYPE;
	static const std::string GC_THRESHOLD;
	static const std::string GC_ALWAYS;
	static const std::string GC_INC_MAG_MARKS;
	static const std::string GC_INC_MAG_SWEEPS;
	static const std::string GC_INC_MIN_MARKS;
	static const std::string GC_INC_MIN_SWEEPS;
	static const std::string GC_INC_LIMIT_FULL_SWEEPS;
private:
	UserSystem();
	~UserSystem();
	Properties props;
};
template<typename T>
inline void UserSystem::put(const std::string &key, T val) {
	props.put<T>(key, val);
}

template<typename T>
inline T UserSystem::value(const std::string & key) {
	return props.value<T>(key);
}

template<typename T>
inline T UserSystem::value(const std::string & key, T defaultValue) {
	return props.value<T>(key, defaultValue);
}
#endif // !BEAN_ENV_USER_USERSYSTEM_H
