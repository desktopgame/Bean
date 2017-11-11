#include "compiler.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "string_buffer.h"

//prototype
compiler* p__compiler_malloc();
compiler* p__compiler_new();
void p__compiler_free(compiler* com);

//public
void init_compiler_stack() {
	compiler_stack = stack_new();
}

void push_compiler() {
	ast_start_compile();
	string_buffer_start_compile();
	stack_push(compiler_stack, p__compiler_new());
}

compiler * get_compiler() {
	return stack_top(compiler_stack);
}

void pop_compiler(BBOOL fail) {
	compiler* com = (compiler*)stack_pop(compiler_stack);
	//Ž¸”s‚µ‚Ä‚¢‚éê‡‚É‚Í
	//ast_compile_end‚Å‘S‚Äíœ
	if (fail) {
		com->root = NULL;
	}
	ast_end_compile(fail);
	string_buffer_end_compile(fail);
	p__compiler_free(com);
}

void destroy_compiler_stack() {
	stack_delete(compiler_stack);
}

void compiler_cur_clear_string_buffer() {
	compiler* com = get_compiler();
	compiler_clear_string_buffer(com);
}

void compiler_cur_append_string_buffer(YYBChar ch) {
	compiler* com = get_compiler();
	compiler_append_string_buffer(com, ch);
}

ast * compiler_cur_reduce_string_buffer() {
	compiler* com = get_compiler();
	return compiler_reduce_string_buffer(com);
}

void compiler_cur_parsing_field_start() {
	compiler_parsing_field_start(get_compiler());
}

void compiler_cur_parsing_field_end() {
	compiler_parsing_field_end(get_compiler());
}

BBOOL compiler_cur_parsing_field() {
	return get_compiler()->parsing_field_now;
}

void compiler_cur_nextcolumn() {
	compiler_nextcolumn(get_compiler());
}

void compiler_cur_nextline() {
	compiler_nextline(get_compiler());
}

void compiler_cur_set_errorline(YYBString str) {
	compiler_set_errorline(get_compiler(), str);
}

void compiler_clear_string_buffer(compiler* com) {
	if (com->string_literal != NULL) {
		string_buffer_delete(com->string_literal);
	}
	com->string_literal = string_buffer_new();
}

void compiler_append_string_buffer(compiler * com, YYBChar ch) {
	string_buffer_append(com->string_literal, ch);
}

ast * compiler_reduce_string_buffer(compiler * com) {
	ast* ret = ast_malloc();
	ret->tag = t_String;
	if (com->string_literal->length == 0) {
		ret->u.string_value = "";
	} else {
		//compiler#string_literal
		//‚ÉŠi”[‚³‚ê‚½’l‚ÍAST‚Éíœ‚µ‚Ä‚à‚ç‚¤
		ret->u.string_value = com->string_literal->pointee;
		ret->allocStr = BTRUE;
		free(com->string_literal);
		com->string_literal = NULL;
	}
	return ret;
}

void compiler_parsing_field_start(compiler * com) {
	com->parsing_field_now = BTRUE;
}

void compiler_parsing_field_end(compiler * com) {
	com->parsing_field_now = BFALSE;
}

void compiler_nextcolumn(compiler * com) {
	com->col = 0;
}

void compiler_nextline(compiler * com) {
	com->row++;
	com->col = 0;
}

void compiler_set_errorline(compiler * com, YYBString str) {
	com->error_line = str;
}

short compiler_char_to_short(char * yytext) {
	CONVERT_FUNC_IMPL(short, 's', 'S', atoi);
}

int compiler_char_to_int(char * yytext) {
	CONVERT_FUNC_IMPL(int, 'i', 'I', atoi);
}

long compiler_char_to_long(char * yytext) {
	CONVERT_FUNC_IMPL(long, 'l', 'L', atol);
}

float compiler_char_to_float(char * yytext) {
	CONVERT_FUNC_IMPL(float, 'f', 'F', atof);
}

double compiler_char_to_double(char * yytext) {
	CONVERT_FUNC_IMPL(double, 'd', 'D', atof);
}

void compiler_conv_feedback(char * text) {
}

int compiler_char_to_int_nonoise(char * yytext) {
	return atoi(yytext);
}

double compiler_char_to_double_nonoise(char * yytext) {
	return (double)atof(yytext);
}

//private
compiler* p__compiler_malloc() {
	compiler* com = (compiler*)mem_malloc(sizeof(compiler));
	com->row = 0;
	com->col = 0;
	com->file_name = NULL;
	com->im = im_file;
	return com;
}

compiler* p__compiler_new() {
	compiler* com = p__compiler_malloc();
	com->root = ast_malloc();
	com->root->tag = t_Root;
	com->string_literal = NULL;
	return com;
}

void p__compiler_free(compiler* com) {
	string_buffer_delete(com->string_literal);
	com->string_literal = NULL;

	if (com->root != NULL) {
		ast_delete(com->root);
		com->root = NULL;
	}

	free(com);
}
