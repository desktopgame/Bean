#pragma once
/**
 * @file stack.h
 * @brief スタック。
 */
#ifndef BEAN_PARSER_BISON_STACK_H
#define BEAN_PARSER_BISON_STACK_H
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * スタックに格納するデータ型です。
	 * 汎用コンテナとするために void* を使用します。
	 */
	typedef void* stack_item;
	/**
	 * スタックとして機能する構造体です.
	 */
	typedef struct stack {
		stack_item value;
		struct stack* prev;
		struct stack* next;
	} stack;

	/**
	 * スタックを作成します。
	 * このメソッドで作成したスタックは delete で削除してください。
	 * @return
	 */
	stack* stack_new();

	/**
	 * スタックの末尾へ要素を追加します。
	 * @param val
	 * @param item
	 */
	void stack_push(stack* val, stack_item item);

	/**
	 * スタックの末尾の要素を返します。
	 * @param val
	 * @return
	 */
	stack_item stack_top(stack* val);

	/**
	 * スタックの末尾の要素を捨てて返します。
	 * @param val
	 * @return
	 */
	stack_item stack_pop(stack* val);

	/**
	 * スタックが空であるかどうかを返します。
	 * @param val
	 * @return
	 */
	int stack_empty(stack* val);

	/**
	 * スタックを削除します。
	 * 中身は削除されません。
	 * @param val
	 */
	void stack_delete(stack* val);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_STACK_H
