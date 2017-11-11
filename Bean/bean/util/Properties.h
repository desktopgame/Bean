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
 * キーと値の一覧です.
 * 順番は保証されません。
 */
class Properties {
public:
	Properties();
	~Properties();
	//代入演算子
	Properties& operator=(const Properties& rhs) {
		this->map = rhs.map;
		return *this;
	}
	/**
	 * 指定のキーと値を紐づけます.
	 * @param key
	 * @param val
	 */
	void put(const std::string& key, const std::string& val);
	/**
	 * 指定のキーと値を紐づけます.
	 * @param key
	 * @param val
	 */
	void put(const std::string& key, const char* val);

	/**
	 * T を std::to_string で変換します.
	 * @param key
	 * @param val
	 */
	template<typename T>
	void put(const std::string& key, T val);

	/**
	 * 指定のキーに紐づけられた値を返します.
	 * @param key
	 * @return
	 */
	std::string get(const std::string& key);

	/**
	 * get<std::string> への委譲です.
	 */
	std::string str(const std::string& key);

	/**
	 * get<std::string> への委譲です.
	 */
	std::string str(const std::string& key, const std::string& val);

	/**
	 * 指定のキーに紐づけられた値を
	 * boost::lextcal_cast で変換して返します。
	 */
	template<typename T>
	T value(const std::string& key);

	/**
	 * 指定のキーに紐づけられた値を
	 * boost::lextcal_cast で変換して返します。
	 * キーが存在しなければデフォルト値.
	 */
	template<typename T>
	T value(const std::string& key, T defaultValue);

	/**
	 * 指定のキーに紐づけられた値を削除します.
	 * @param key
	 * @return
	 */
	std::string remove(const std::string& key);

	/**
	 * 指定のキーを含むなら true.
	 * @param key
	 * @return
	 */
	bool contains(const std::string& key);

	/**
	 * 現在のプロパティの内容を指定のファイルへ書き込みます.
	 * @param fileName
	 */
	void write(const std::string& fileName);

	/**
	 * 指定のファイルからプロパティを読み込みます.
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
		//変換関数でエラーが発生したらデフォルト
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
