/**
 * @file yyinterface.h
 * @brief Flex/Bisonの薄いラッパーです。
 */
#pragma once
#ifndef BEAN_PARSER_BISON_YYINTERFACE_H
#define BEAN_PARSER_BISON_YYINTERFACE_H
#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * デバッグ用の関数です.
	 * 指定のファイルを解析してツリーを出力します。
	 * コンパイラスタックは呼び出し前も呼び出し後も 0 です.
	 * @param filePath
	 */
	int debug_yyparse(const char* filePath);

	/**
	 * yyparseを呼び出して結果を返すだけのメソッドです.
	 * ファイルをオープン出来なかった場合には解析せずに失敗します。
	 * @parma filePath
	 */
	int compile_yyparse(const char* filePath);

	/**
	 * 文字列を入力元して解析します.
	 */
	int compile_yyparsestr(char *source);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_YYINTERFACE_H
