#pragma once
#ifndef BEAN_ENV_USER_USERSYSTEM_H
#define BEAN_ENV_USER_USERSYSTEM_H
#include "../../util/Properties.h"
#include "../../util/Text.h"
/**
 * ユーザによって書き換え可能なマップ.
 * 環境変数の代替として使用されます。
 */
class UserSystem {
public:
	UserSystem(const UserSystem&) = delete;
	UserSystem& operator=(const UserSystem&) = delete;
	UserSystem(UserSystem&&) = delete;
	UserSystem& operator=(UserSystem&&) = delete;
	/**
	* 唯一のインスタンスを返します.
	* @return
	*/
	static UserSystem* const getInstance() {
		static UserSystem inst;
		return &inst;
	}

	/**
	 * Bean設定ファイルへのパスを返します.
	 */
	static std::string getSysPath();

	/**
	 * Properties への 委譲です.
	 */
	void put(const std::string& key, const std::string& val);
	/**
	 * Properties への 委譲です.
	 */
	void put(const std::string& key, const char* val);

	/**
	 * Properties への 委譲です.
	 */
	template<typename T>
	void put(const std::string& key, T val);

	/**
	 * Properties への 委譲です.
	 */
	std::string get(const std::string& key);

	/**
	 * Properties への 委譲です.
	 */
	std::string str(const std::string& key);

	/**
	 * Properties への 委譲です.
	 */
	std::string str(const std::string& key, const std::string& val);

	/**
	 * Properties への 委譲です.
	 */
	template<typename T>
	T value(const std::string& key);

	/**
	 * Properties への 委譲です.
	 */
	template<typename T>
	T value(const std::string& key, T defaultValue);

	/**
	 * Properties への 委譲です.
	 */
	std::string remove(const std::string& key);

	/**
	 * Properties への 委譲です.
	 */
	bool contains(const std::string& key);

	/**
	 * マップをデフォルトか既に存在するファイルから読み出します.
	 */
	static void initialize();

	/**
	 * マップをデフォルトで上書きします.
	 */
	void defaults();

	/**
	 * マップをクリアしてから指定のファイルを読み込みます.
	 * @param filePath
	 */
	void load(std::string filePath);

	/**
	 * 現在のマップの内容をファイルへ書き出します.
	 * @param filePath
	 */
	void apply(std::string filePath);

	/**
	 * イベントリスナーの一覧を返します.
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
