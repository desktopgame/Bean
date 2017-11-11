#pragma once
#ifndef BEAN_UTIL_PROPERTIES_H
#define BEAN_UTIL_PROPERTIES_H
#include <type_traits>
#include <unordered_map>
#include <boost/lexical_cast.hpp> 
#include <boost/signals2.hpp>
#include "PropertyChangeEvent.h"
using PropertyChangeListenerList = boost::signals2::signal<void(const PropertyChangeEvent&)>;
/**
 * �L�[�ƒl�̈ꗗ�ł�.
 * ���Ԃ͕ۏ؂���܂���B
 */
class Properties {
public:
	Properties();
	~Properties();
	//������Z�q
	Properties& operator=(const Properties& rhs) {
		this->map = rhs.map;
		return *this;
	}
	/**
	 * �w��̃L�[�ƒl��R�Â��܂�.
	 * @param key
	 * @param val
	 */
	void put(const std::string& key, const std::string& val);
	/**
	 * �w��̃L�[�ƒl��R�Â��܂�.
	 * @param key
	 * @param val
	 */
	void put(const std::string& key, const char* val);

	/**
	 * T �� std::to_string �ŕϊ����܂�.
	 * @param key
	 * @param val
	 */
	template<typename T>
	void put(const std::string& key, T val);

	/**
	 * �w��̃L�[�ɕR�Â���ꂽ�l��Ԃ��܂�.
	 * @param key
	 * @return
	 */
	std::string get(const std::string& key);

	/**
	 * get<std::string> �ւ̈Ϗ��ł�.
	 */
	std::string str(const std::string& key);

	/**
	 * get<std::string> �ւ̈Ϗ��ł�.
	 */
	std::string str(const std::string& key, const std::string& val);

	/**
	 * �w��̃L�[�ɕR�Â���ꂽ�l��
	 * boost::lextcal_cast �ŕϊ����ĕԂ��܂��B
	 */
	template<typename T>
	T value(const std::string& key);

	/**
	 * �w��̃L�[�ɕR�Â���ꂽ�l��
	 * boost::lextcal_cast �ŕϊ����ĕԂ��܂��B
	 * �L�[�����݂��Ȃ���΃f�t�H���g�l.
	 */
	template<typename T>
	T value(const std::string& key, T defaultValue);

	/**
	 * �w��̃L�[�ɕR�Â���ꂽ�l���폜���܂�.
	 * @param key
	 * @return
	 */
	std::string remove(const std::string& key);

	/**
	 * �w��̃L�[���܂ނȂ� true.
	 * @param key
	 * @return
	 */
	bool contains(const std::string& key);

	/**
	 * ���݂̃v���p�e�B�̓��e���w��̃t�@�C���֏������݂܂�.
	 * @param fileName
	 */
	void write(const std::string& fileName);

	/**
	 * �w��̃t�@�C������v���p�e�B��ǂݍ��݂܂�.
	 * @param fileName
	 */
	void read(const std::string& fileName);

	PropertyChangeListenerList onPropertyChange;
private:
	std::unordered_map<std::string, std::string> map;
};
template<typename T>
inline void Properties::put(const std::string & key, T val) {
	assert(false);
}

template<>
inline void Properties::put(const std::string & key, int val) {
	put(key, std::to_string(val));
}

template<>
inline void Properties::put(const std::string & key, float val) {
	put(key, std::to_string(val));
}

template<>
inline void Properties::put(const std::string & key, bool val) {
	put(key, val ? "true" : "false");
}

template<typename T>
inline T Properties::value(const std::string & key) {
	assert(false);
	return T();
}

template<>
inline std::string Properties::value(const std::string & key) {
	return get(key);
}

template<>
inline int Properties::value(const std::string & key) {
	return boost::lexical_cast<int>(get(key));
}

template<>
inline float Properties::value(const std::string & key) {
	return boost::lexical_cast<float>(get(key));
}

template<>
inline bool Properties::value(const std::string & key) {
	auto str = get(key);
	if (str == "true" || str == "TRUE") {
		return true;
	} else if (str == "false" || str == "FALSE") return false;
	return boost::lexical_cast<bool>(str);
}

template<typename T>
inline T Properties::value(const std::string &key, T defaultValue) {
	if (contains(key)) {
		try {
			return value<T>(key);
		//�ϊ��֐��ŃG���[������������f�t�H���g
		} catch (...) {
			return defaultValue;
		}
	}
	return defaultValue;
}

template<>
inline std::string Properties::value(const std::string &key, std::string defaultValue) {
	if (contains(key)) {
		return get(key);
	}
	return defaultValue;
}
#endif // !BEAN_UTIL_PROPERTIES_H
