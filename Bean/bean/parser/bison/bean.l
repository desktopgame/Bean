%{
//http://kmaebashi.com/programmer/devlang/diksam.html
#undef YY_INPUT
#define YY_INPUT(buf, result, max_size) (result = my_yyinput(buf, max_size))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bean.tab.h"
#include "compiler.h"
#include "string_buffer.h"
//#include "ast.h"

//for C4996
#ifdef _MSC_VER
#pragma warning(disable:4996)
#elif
#pragma warning(disable:4996)
#endif
int yymain(void) {
	yyparse();
	return(0);
}

int yywrap(void) {
	return 1;
}

int yyerror(char * err_str) {
	fprintf(stderr,err_str);
	printf("\n");
	printf("file-name=%s", get_compiler()->file_name);
	printf(" row=%d", get_compiler()->row);
	printf(" col=%d", 0);
	printf("\n");
}

void yyexit() {
}

static int file_input(char *buf, int max_size) {
	int ch;
	int len;

	if (feof(yyin))
		return 0;

	for (len = 0; len < max_size; len++) {
		ch = getc(yyin);
		if (ch == EOF)
			break;
		buf[len] = ch;
	}
    return len;
}

static char* yaccSourceBuffer;
static int yaccSourceOffset;
 
void yy_setstr(char* source) {
	yaccSourceBuffer = source;
	yaccSourceOffset = 0;
}

void yy_clearstr() {
	free(yaccSourceBuffer);
	yaccSourceBuffer = NULL;
	yaccSourceOffset = 0;
}

static int string_input(char *buf, int max_size) {
	int len = 0;
	int startOffset = yaccSourceOffset;
	for(; (yaccSourceOffset < yaccSourceOffset + max_size); yaccSourceOffset++) {
		if(yaccSourceBuffer[yaccSourceOffset] == '\0') {
			break;
		}
		buf[yaccSourceOffset - startOffset] = yaccSourceBuffer[yaccSourceOffset];
		len++;
	}
	return len;
}

static int my_yyinput(char *buf, int max_size) {
	int result;

	switch (get_compiler()->im) {
	case im_file:
		result = file_input(buf, max_size);
		break;
    case im_str:
		result = string_input(buf, max_size);
		break;
	default:
		return 0;
	}
	return result;
}
%}
%option yy_scan_string
%option yy_scan_buffer
%option yy_scan_bytes
%start ML_COMMENT L_COMMENT STRING_LITERAL_STATE
%%

<INITIAL>"."				{ return (DOT); }
<INITIAL>","				{ return (COMMA); }
<INITIAL>":"				{ return (COLON); }
<INITIAL>"::"				{ return (COLO_COLO); }


<INITIAL>"+"				{ return (ADD); }
<INITIAL>"-"				{ return (SUB); }
<INITIAL>"*"				{ return (MUL); }
<INITIAL>"/"				{ return (DIV); }
<INITIAL>"%"				{ return (MOD); }
<INITIAL>"!"				{ return (NOT); }


<INITIAL>"="				{ return (N_ASSIGN_T); }
<INITIAL>"+="				{ return (ADD_ASSIGN_T); }
<INITIAL>"-="				{ return (SUB_ASSIGN_T); }
<INITIAL>"*="				{ return (MUL_ASSIGN_T); }
<INITIAL>"/="				{ return (DIV_ASSIGN_T); }
<INITIAL>"%="				{ return (MOD_ASSIGN_T); }

<INITIAL>"=="				{ return (EQUAL); }
<INITIAL>"!="				{ return (NOTEQUAL); }


<INITIAL>"++"				{ return (INC); }
<INITIAL>"--"				{ return (DEC); }

<INITIAL>">"				{ return (BIGGEST); }
<INITIAL>">="				{ return (EBIGGEST); }
<INITIAL>"<"				{ return (SMALLEST); }
<INITIAL>"<="				{ return (ESMALLEST); }
<INITIAL>"->"				{ return (ARROW); }

<INITIAL>"&"				{ return (AND); }
<INITIAL>"&&"			{ return (ANDAND); }
<INITIAL>"|"				{ return (OR); }
<INITIAL>"||"			{ return (OROR); }
<INITIAL>"{"				{ return (LCB); }
<INITIAL>"}"				{ return (RCB); }
<INITIAL>"("				{ return (LRB); }
<INITIAL>")"				{ return (RRB); }
<INITIAL>"["				{ return (LSB); }
<INITIAL>"]"				{ return (RSB); }
<INITIAL>use				{ return (USE); }
<INITIAL>alias				{ return (ALIAS); }
<INITIAL>class				{ return (CLASS); }
<INITIAL>enum				{ return (ENUM); }
<INITIAL>true				{ return (TRUE); }
<INITIAL>false				{ return (FALSE); }
<INITIAL>null				{ return (NULL_VALUE); }
<INITIAL>for				{ return (FOR); }
<INITIAL>while			{ return (WHILE); }
<INITIAL>if				{ return (IF); }
<INITIAL>else			{ return (ELSE); }
<INITIAL>elseif			{ return (ELSEIF); }
<INITIAL>break			{ return (BREAK); }
<INITIAL>continue		{ return (CONTINUE); }
<INITIAL>return			{ return (RETURN); }
<INITIAL>new				{ return (NEW); }
<INITIAL>lambda				{ return (LAMBDA); }
<INITIAL>def				{ return (DEF); }
<INITIAL>throw				{ return (THROW); }
<INITIAL>try				{ return (TRY); }
<INITIAL>catch			{ return (CATCH); }
<INITIAL>finally			{ return (FINALLY); }
<INITIAL>public			{ return (PUBLIC); }
<INITIAL>private			{ return (PRIVATE); }
<INITIAL>protected		{ return (PROTECTED); }
<INITIAL>static			{ return (STATIC); }
<INITIAL>final			{ return (FINAL); }
<INITIAL>native			{ return (NATIVE); }
<INITIAL>var			{ return (VAR); }
<INITIAL>this			{ return (THIS); }
<INITIAL>super			{ return (SUPER); }

<INITIAL>"@" { 
	compiler_cur_parsing_field_start(); 
	return (AT); 
}
<INITIAL>";" { 
	compiler_cur_parsing_field_end(); 
	return (SEMI); 
}
<INITIAL>set { 
	if(compiler_cur_parsing_field()) {
		return SET;
	}
	yylval.ident_value = string_buffer_clone(yytext);
	return IDENT;
}
<INITIAL>get {
	if(compiler_cur_parsing_field()) {
		return GET;
	}
	yylval.ident_value = string_buffer_clone(yytext);
	return IDENT;
}


<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
    yylval.ident_value = string_buffer_clone(yytext);
    return IDENT;
}

<INITIAL>[1-9][0-9]*[s|S] {
	yylval.ast_value = ast_new_short(compiler_char_to_short(yytext));
	return SHORT;
}

<INITIAL>[1-9][0-9]*[i|I]? {
	yylval.ast_value = ast_new_int(compiler_char_to_int(yytext));
	return INT;
}

<INITIAL>[1-9][0-9]*[l|L] {
	yylval.ast_value = ast_new_long(compiler_char_to_long(yytext));
	return LONG;
}

<INITIAL>"0" {
    yylval.ast_value = ast_new_int(0);
    return INT;
}

<INITIAL>[1-9][0-9]*[f|F] {
	yylval.ast_value = ast_new_float(compiler_char_to_float(yytext));
	return FLOAT;
}

<INITIAL>[0-9]*\.[0-9]+[f|F] {
	yylval.ast_value = ast_new_float(compiler_char_to_float(yytext));
	return FLOAT;
}

<INITIAL>[0-9]*\.[0-9]+[d|D]? {
	yylval.ast_value = ast_new_double(compiler_char_to_double(yytext));
	return DOUBLE;
}
<INITIAL>[1-9][0-9]*[d|D]? {
	yylval.ast_value = ast_new_double(compiler_char_to_double(yytext));
	return DOUBLE;
}

<INITIAL>\" {
	compiler_cur_clear_string_buffer();
    BEGIN STRING_LITERAL_STATE;
}
<INITIAL>[ \t] ;
<INITIAL>[\r\n] { compiler_cur_nextline(); }

<INITIAL>"/*"     BEGIN ML_COMMENT;
<INITIAL>"//"     BEGIN L_COMMENT;
<ML_COMMENT>\n     compiler_cur_nextline();
<ML_COMMENT>"*/"     {
    BEGIN INITIAL;
}
<ML_COMMENT>.      ;
<L_COMMENT>\n  {
    compiler_cur_nextline();
    BEGIN INITIAL;
}
<L_COMMENT><<EOF>>   {
	BEGIN INITIAL;
}
<L_COMMENT>.   ;
<INITIAL>\'\\r\' {
	yylval.ast_value = ast_new_char('\r');
	return CHAR_LITERAL;
}
<INITIAL>\'\\n\' {
	yylval.ast_value = ast_new_char('\n');
	return CHAR_LITERAL;
}
<INITIAL>\'\\t\' {
	yylval.ast_value = ast_new_char('\t');
	return CHAR_LITERAL;
}
<INITIAL>\'\\b\' {
	yylval.ast_value = ast_new_char('\b');
	return CHAR_LITERAL;
}
<INITIAL>\'.\' {
	yylval.ast_value = ast_new_char(yytext[1]);
	return CHAR_LITERAL;
}
<STRING_LITERAL_STATE>\" {
	yylval.ast_value = compiler_cur_reduce_string_buffer();
    BEGIN INITIAL;
	return STRING_LITERAL;
}
<STRING_LITERAL_STATE>\\\"      compiler_cur_append_string_buffer('"');
<STRING_LITERAL_STATE>\\\'       compiler_cur_append_string_buffer('\'');
<STRING_LITERAL_STATE>\\r       compiler_cur_append_string_buffer('\r');
<STRING_LITERAL_STATE>\\n       compiler_cur_append_string_buffer('\n');
<STRING_LITERAL_STATE>\\t       compiler_cur_append_string_buffer('\t');
<STRING_LITERAL_STATE>\\\\      compiler_cur_append_string_buffer('\\');
<STRING_LITERAL_STATE>.         {
	compiler_cur_append_string_buffer(yytext[0]);
}
%%