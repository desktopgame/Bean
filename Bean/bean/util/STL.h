#pragma once
#ifndef BEAN_UTIL_STL
#define BEAN_UTIL_STL
#include <functional>
#include <map>
#include <string>
#include <vector>
/**
 * STLに関する汎用的な処理をまとめたクラス.
 */
class STL {
public:
	/**
	 * 指定の要素が含まれるならtrueを返します.
	 */
	template<typename T>
	static bool contains(std::vector<T> container, T item);

	/**
	 * 指定のコンテナを逆順で巡回します.
	 * @param container
	 * @param preErase 削除するならtrue.
	 * @param postErase 削除した後の処理
	 */
	template<typename T>
	static void each_reverse(std::vector<T> container, std::function<bool(T)> preErase, std::function<void(T)> postErase);

	/**
	 * 指定の要素を削除します.
	 * @param container
	 * @param item
	 * @param consumer
	 */
	template<typename T>
	static void remove(std::vector<T> container, T item, std::function<void(T)> consumer);

	/**
	 * 全ての要素を削除します.
	 * @param container
	 * @param consuemr
	 */
	template<typename T>
	static void removeAll(std::vector<T> container, std::function<void(T)> consumer);

	/**
	 * 指定の値を削除します.
	 * @param container
	 * @param value
	 * @param consumer
	 */
	template<typename K, typename V>
	static void remove(std::map<K, V> container, V value, std::function<void(K, V)> consumer);

	/**
	 * 全ての要素を削除します.
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

