#pragma once
/**
 * @file list.h
 * @brief リスト。
 */
#ifndef BEAN_PARSER_BISON_LIST_H
#define BEAN_PARSER_BISON_LIST_H
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * リストに格納するデータ型です。
	 * 汎用コンテナとするために void* を使用します。
	 */
	typedef void* list_item;
	/**
	 * 可変長配列として機能する構造体です.
	 */
	typedef struct list {
		list_item value;
		int* size;
		struct list* prev;
		struct list* next;
	} list;
	/**
	 * リストのデリータ関数です.
	 * @param item
	 */
	typedef void(*list_element_deleter)(list_item item);
	/**
	 * リストを作成します。
	 * このメソッドで作成したリストは delete で削除してください。
	 * @return
	 */
	list* list_new();

	/**
	 * 末尾へ要素を追加します。
	 * @param val
	 * @param item
	 */
	void list_add(list* val, list_item item);

	/**
	 * 末尾へ要素を追加します。
	 * @param dst 追加先
	 * @param sec 追加元
	 */
	void list_add_all(list* dst, list* src);

	/**
	 * 指定位置の要素を削除します。
	 * 中身は削除されません。
	 * @param val
	 * @param index
	 * @return
	 */
	list_item list_remove(list* val, int index);

	/**
	 * 指定位置の要素を返します。
	 * @param val
	 * @param index
	 * @return
	 */
	list_item list_getAt(list* val, int index);

	/**
	 * リストが空であるかどうかを返します。
	 * @param val
	 * @return
	 */
	int list_empty(list* val);

	/**
	 * リストの要素数を返します。
	 * @param val
	 * @return
	 */
	int list_size(list* val);

	/**
	 * リストとアイテムを削除します。
	 * @param val
	 * @param deleter
	 */
	void list_delete_with_item(list* val, list_element_deleter deleter);

	/**
	 * リストを削除します。
	 * 中身は削除されません。
	 * @param val
	 */
	void list_delete(list* val);

	/**
	 * デリートを行わないデリータです。
	 * @param item
	 */
	void list_deleter_non_delete(list_item item);

	/**
	 * freeによって削除するデリータです。
	 * @param item
	 */
	void list_deleter_free(list_item item);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_LIST_H
