#pragma once
#ifndef BEAN_UTIL_STL
#define BEAN_UTIL_STL
#include <functional>
#include <map>
#include <string>
#include <vector>
/**
 * STL�Ɋւ���ėp�I�ȏ������܂Ƃ߂��N���X.
 */
class STL {
public:
	/**
	 * �w��̗v�f���܂܂��Ȃ�true��Ԃ��܂�.
	 */
	template<typename T>
	static bool contains(std::vector<T> container, T item);

	/**
	 * �w��̃R���e�i���t���ŏ��񂵂܂�.
	 * @param container
	 * @param preErase �폜����Ȃ�true.
	 * @param postErase �폜������̏���
	 */
	template<typename T>
	static void each_reverse(std::vector<T> container, std::function<bool(T)> preErase, std::function<void(T)> postErase);

	/**
	 * �w��̗v�f���폜���܂�.
	 * @param container
	 * @param item
	 * @param consumer
	 */
	template<typename T>
	static void remove(std::vector<T> container, T item, std::function<void(T)> consumer);

	/**
	 * �S�Ă̗v�f���폜���܂�.
	 * @param container
	 * @param consuemr
	 */
	template<typename T>
	static void removeAll(std::vector<T> container, std::function<void(T)> consumer);

	/**
	 * �w��̒l���폜���܂�.
	 * @param container
	 * @param value
	 * @param consumer
	 */
	template<typename K, typename V>
	static void remove(std::map<K, V> container, V value, std::function<void(K, V)> consumer);

	/**
	 * �S�Ă̗v�f���폜���܂�.
	 * @param container
	 * @param consuemr
	 */
	template<typename K, typename V>
	static void removeAll(std::map<K, V> container, std::function<void(K, V)> consumer);
private:
	STL();
	~STL();
};
#include "STLImpl.cpp"
#endif // !BEAN_UTIL_STL

