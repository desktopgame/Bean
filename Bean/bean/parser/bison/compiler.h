#pragma once
/**
 * @file compiler.h
 * @brief Bisonの出力先。
 */
#ifndef BEAN_PARSER_BISON_COMPILER_H
#define BEAN_PARSER_BISON_COMPILER_H
#include "ast.h"
#include "stack.h"
#include "string_buffer.h"
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * Yacc/Flex の 入力モード.
	 */
	typedef enum input_mode {
		im_file,
		im_str
	} input_mode;
	/**
	 * Bison/Flexの実行時情報を保持する構造体.
	 * yyparseから呼ばれる各アクションはこの構造体の root へノードを保存します。
	 */
	typedef struct compiler {
		string_buffer* string_literal;
		int row;
		int col;
		YYBString error_line;
		YYBString file_name;
		input_mode im;
		/**
		 * フィールド以外の場所で
		 * set getが現れた場合に IDENT として解釈します。
		 */
		BBOOL parsing_field_now;
		ast* root;
	} compiler;
	static stack* compiler_stack;
/**
 * @param RET_TYPE	戻り値の型
 * @param S_CH		マッチする文字(小文字)
 * @param L_CH		マッチする文字(大文字)
 * @param FUNC_NAME	変換関数(char*)
 */
#define CONVERT_FUNC_IMPL(RET_TYPE, S_CH, L_CH, FUNC_NAME)	buffer_ptr range = yytext;					\
															buffer_t last = range[strlen(range) - 1];	\
															RET_TYPE ret = 0;							\
															if (last == S_CH || last == L_CH) {			\
																int len = strlen(yytext);				\
																char* buff = string_buffer_substr_dynamic(yytext, 0, len - 1);	\
																ret = (RET_TYPE)FUNC_NAME(buff);								\
																compiler_conv_feedback(buff);									\
																free(buff);														\
															} else {															\
																compiler_conv_feedback(range);									\
																ret = (RET_TYPE)FUNC_NAME(range);								\
															}																	\
															return ret
	/**
	 * コンパイラスタックを作成します。
	 * プログラムの先頭で一度だけ呼び出します。
	 */
	void init_compiler_stack();

	/**
	 * コンパイラスタックへ新たなコンパイラをプッシュします。
	 * yyparseの直前で呼び出します。
	 */
	void push_compiler();

	/**
	 * コンパイラスタックの末尾を返します。
	 * @return
	 */
	compiler* get_compiler();

	/**
	 * コンパイラスタックから一つポップします。
	 * 引数failは AST/文字列 の破棄のために使用されます。
	 * @param fail Flex/Bisonがエラー終了したならtrue
	 */
	void pop_compiler(BBOOL fail);

	/**
	 * コンパイラスタックを削除します。
	 * プログラムの最後で一度だけ呼び出します。
	 */
	void destroy_compiler_stack();


	/**
	 * 現在のコンパイラで文字列バッファをクリアします。
	 * 文字列リテラル " を発見すると呼び出されます。
	 */
	void compiler_cur_clear_string_buffer();

	/**
	 * 現在のコンパイラの文字列バッファへ一文字追加します。
	 * @param ch
	 */
	void compiler_cur_append_string_buffer(YYBChar ch);

	/**
	 * 現在のコンパイラの文字列バッファをASTへ還元します。
	 * @return
	 */
	ast* compiler_cur_reduce_string_buffer();

	/**
	 * 現在のコンパイラでフィールド解析中フラグをONにします。
	 */
	void compiler_cur_parsing_field_start();

	/**
	 * 現在のコンパイラでフィールド解析中フラグをOFFにします。
	 */
	void compiler_cur_parsing_field_end();

	/**
	 * 現在のコンパイラのフィールド解析中フラグを返します。
	 * @return
	 */
	BBOOL compiler_cur_parsing_field();

	/**
	 * 現在のコンパイラで列位置を一つ進めます。
	 * エラーメッセージのために使用されます。
	 */
	void compiler_cur_nextcolumn();

	/**
	 * 現在のコンパイラで行位置を一つ進めます。
	 * エラーメッセージのために使用されます。
	 */
	void compiler_cur_nextline();

	/**
	 * 現在のコンパイラでエラーが発生した行の文字列を記録します。
	 * @param str
	 */
	void compiler_cur_set_errorline(YYBString str);


	/**
	 * 指定のコンパイラで文字列バッファをクリアします。
	 * 文字列リテラル " を発見すると呼び出されます。
	 * @param com
	 */
	void compiler_clear_string_buffer(compiler* com);

	/**
	 * 指定のコンパイラの文字列バッファへ一文字追加します。
	 * @param com
	 * @param ch
	 */
	void compiler_append_string_buffer(compiler* com, YYBChar ch);

	/**
	 * 指定のコンパイラの文字列バッファをASTへ還元します。
	 * @param com
	 * @return
	 */
	ast* compiler_reduce_string_buffer(compiler* com);

	/**
	 * 指定のコンパイラでフィールド解析中フラグをONにします。
	 * @param com
	 */
	void compiler_parsing_field_start(compiler* com);

	/**
	 * 指定のコンパイラでフィールド解析中フラグをOFFにします。
	 * @param com
	 */
	void compiler_parsing_field_end(compiler* com);

	/**
	 * 指定のコンパイラで列位置を一つ進めます。
	 * エラーメッセージのために使用されます。
	 * @param com
	 */
	void compiler_nextcolumn(compiler* com);

	/**
	 * 指定のコンパイラで行位置を一つ進めます。
	 * エラーメッセージのために使用されます。
	 * @param com
	 */
	void compiler_nextline(compiler* com);

	/**
	 * 指定のコンパイラでエラーが発生した行の文字列を記録します。
	 * @param com
	 * @param str
	 */
	void compiler_set_errorline(compiler* com, YYBString str);

	
	/**
	 * 文字列を short 型へ変換します。
	 * 末尾には s もしくは S を配置出来ます。
	 * @param yytext
	 * @return
	 */
	short compiler_char_to_short(char* yytext);

	/**
	 * 文字列を int 型へ変換します。
	 * 末尾には i もしくは I を配置出来ます。
	 * @param yytext
	 * @return
	 */
	int compiler_char_to_int(char* yytext);


	/**
	 * 文字列を long 型へ変換します。
	 * 末尾には l もしくは L を配置出来ます。
	 * @param yytext
	 * @return
	 */
	long compiler_char_to_long(char* yytext);


	/**
	 * 文字列を float 型へ変換します。
	 * 末尾には f もしくは F を配置出来ます。
	 * @param yytext
	 * @return
	 */
	float compiler_char_to_float(char* yytext);

	/**
	 * 文字列を double 型へ変換します。
	 * 末尾には d もしくは D を配置出来ます。
	 * @param yytext
	 * @return
	 */
	double compiler_char_to_double(char* yytext);


	/**
	 * 呼び出しても何も起こりません。
	 * @param text
	 */
	void compiler_conv_feedback(char* text);

	/**
	 * 文字列を int 型へ変換します。
	 * @param yytext
	 * @return
	 */
	int compiler_char_to_int_nonoise(char* yytext);

	/**
	 * 文字列を double 型へ変換します。
	 * @param yytext
	 * @return
	 */
	double compiler_char_to_double_nonoise(char* yytext);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_COMPILER_H
