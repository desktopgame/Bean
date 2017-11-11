#pragma once
/**
 * @file string_buffer.h
 * @brief 文字列のバッファーです。
 */
#ifndef BEAN_PRASER_BISON_STRING_BUFFER_H
#define BEAN_PRASER_BISON_STRING_BUFFER_H
#include "bool.h"
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * string_bufferに格納する文字の型です。
	 */
	typedef char buffer_t;

	/**
	 * 上述の文字の配列です。
	 */
	typedef char* buffer_ptr;

	/**
	 * 文字列のコンテナです。
	 */
	typedef struct string_buffer {
		/**
		 * mallocによって動的に確保された文字の配列です。
		 * #apend, #append_str 以外の方法でこれを変更する場合、
		 * lengthも呼び出し側で修正する必要があります。
		 */
		buffer_ptr pointee;
		/**
		 * 現在のバッファの文字の長さを表します。
		 * 末尾のゼロ文字はこれに含まれません。
		 */
		int length;
	} string_buffer;
	/**
	 * ファイルの解析が開始したときに compiler より呼び出されます。
	 * 全ての文字列はASTに包含されることにより、ASTの削除時に一緒に削除されますが、
	 * Flex/Bisonがエラーを報告する場合には異なります。
	 * この場合では作成された文字列がメモリリークを起こすため、
	 * まずコンパイル前に明示的にこのメソッドを呼び出します。
	 * (同様に、コンパイル後には end_compile を呼び出します。)
	 * このメソッドが呼ばれると、それ以降の clone は全てグローバルなリストへ追加されます。
	 * end_compileの呼び出しではこのリストを開放しますが、
	 * end_compileの引数で渡されるコンパイル結果(fail=trueならエラー)
	 * により処理が異なります。
	 * 成功している場合には従来通りASTが文字列を削除しますが、
	 * 失敗している場合には end_compile が u.string_value を削除します。
	 */
	void string_buffer_start_compile();
	/**
	 * 指定の文字列をリストへ紐づけます。
	 * end_compileの呼び出し時に削除されます。
	 * @parma val
	 */
	void string_buffer_link_object(buffer_ptr val);

	/**
	 * リストに紐づけられたオブジェクトを削除します.
	 * @param fail 失敗ならtrue.
	 */
	void string_buffer_end_compile(BBOOL fail);

	/**
	 * バッファを作成します。
	 * このメソッドで作成したバッファーは delete で削除してください。
	 * @return
	 */
	string_buffer* string_buffer_new();

	/**
	 * バッファに一文字付け足します。
	 * @parma val
	 * @param t
	 */
	void string_buffer_append(string_buffer* val, buffer_t t);

	/**
	 * p の中身をコピーしてバッファへ連結します。
	 * @param val
	 * @param p
	 */
	void string_buffer_append_str(string_buffer* val, buffer_ptr p);

	/**
	 * srcを複製して返します。
	 * このとき複製は動的に確保されますが、リストに紐づけられるので
	 * 呼び出し側で削除する必要はありません。
	 * @param src
	 * @return
	 */
	buffer_ptr string_buffer_clone(buffer_ptr src);

	/**
	 * 文字列から指定の範囲を切り出します.
	 * コンパイル時に切り出す長さが決まらない場合には dynamic を使用してください。
	 * @param dst
	 * @param src
	 * @param offs
	 * @param len
	 */
	int string_buffer_substr(buffer_ptr dst, buffer_ptr src, int offs, int len);

	/**
	 * 文字列から指定の範囲を切り出します.
	 * @param src
	 * @param offs
	 * @param len
	 */
	buffer_ptr string_buffer_substr_dynamic(const buffer_ptr src, int offs, int len);

	/**
	 * val を開放します。
	 * @param val
	 */
	void string_buffer_delete(string_buffer* val);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PRASER_BISON_STRING_BUFFER_H
