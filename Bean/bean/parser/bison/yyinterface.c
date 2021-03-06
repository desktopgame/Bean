#include "yyinterface.h"
#include "ast.h"
#include "compiler.h"
//#include "lex.yy.c"
#include <stdio.h>

int debug_yyparse(const char* filePath) {
	//YAXXの解析関数
	extern int yyparse(void);
	//YACCの入力元
	extern FILE *yyin;
	//ファイルを入力元に設定
	errno_t e = fopen_s(&yyin, filePath, "r");
	if (e != 0) {
		return BFALSE;
	}
	push_compiler();
	if (yyparse()) {
		pop_compiler(BTRUE);
		return BFALSE;
	}
	compiler* com = get_compiler();
	ast_dump(com->root);
	pop_compiler(BFALSE);
	return BTRUE;
}

int compile_yyparse(const char * filePath) {
	//YAXXの解析関数
	extern int yyparse(void);
	//YACCの入力元
	extern FILE *yyin;
	errno_t e = fopen_s(&yyin, filePath, "r");
	if (e != 0) {
		return BFALSE;
	}
	if (yyparse()) {
		return BFALSE;
	}
	return BTRUE;
}

int compile_yyparsestr(char *source) {
	extern void yy_setstr(char *source);
	extern void yy_clearstr();
	yy_setstr(source);
	if (yyparse()) {
		yy_clearstr();
		return BFALSE;
	}
	yy_clearstr();
	return BTRUE;
}
