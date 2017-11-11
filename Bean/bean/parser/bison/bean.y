%{
#include <stdio.h>
#include <stdlib.h>
#include "yyinterface.h"
#include "ast.h"
#include "assign_type.h"
#include "modifier_type.h"
#include "constructor_chain_type.h"
#define YYDEBUG 1
#define YYERROR_VERBOSE 1
%}
%union {
	char char_value;
	const char* ident_value;
	ast* ast_value;
	assign_type assign_type_value;
	modifier_type modifier_type_value;
	constructor_chain_type constructor_chain_type_value;
}
%token <ast_value>			SHORT
%token <ast_value>			INT
%token <ast_value>			LONG
%token <ast_value>			FLOAT
%token <ast_value>			DOUBLE
%token <ast_value>			CHAR_LITERAL
%token <ast_value>			STRING_LITERAL
%token <ident_value>			IDENT
%type <assign_type_value>	assign_type
%type <modifier_type_value> modifier_type_T
%type <constructor_chain_type_value>	constructor_chain_type_T;
%token ADD SUB MUL DIV MOD AND ANDAND
		EQUAL NOTEQUAL BIGGEST EBIGGEST
		SMALLEST ESMALLEST NOT DOT COMMA
		N_ASSIGN_T ADD_ASSIGN_T SUB_ASSIGN_T MUL_ASSIGN_T 
		DIV_ASSIGN_T MOD_ASSIGN_T VAR
		INC DEC DEF TRUE FALSE NULL_VALUE SEMI
		OR OROR CR LCB RCB LRB RRB LSB RSB
		FOR WHILE IF ELSE ELSEIF BREAK CONTINUE
		RETURN TRY CATCH FINALLY PUBLIC PRIVATE
		PROTECTED STATIC USE FINAL CLASS AT
		THROW SET GET NATIVE COLON ARROW THIS SUPER
		ENUM LAMBDA NEW ALIAS COLO_COLO
%type <ast_value> root top_level func_define 
					parameter_list stmt_list
					expression assignExpr 
					or and equal compare prefix
					addsub muldiv unary postfix 
					primary_expression
					primary_no_new_array
					argument_list
					for_stmt
					for_stmt_fixed
					while_stmt
					break_stmt
					continue_stmt
					return_stmt
					include
					namespace
					modifier_define
					modifier_list
					class_define
					class_super
					field_define
					member_define
					member_define_list
					try_stmt
					field_set_get
					field_default_value
					throw_stmt
					lambda
					new_array
					alias_T
					dyn_field_define
					dyn_method_define
					constructor_define
					constructor_chain
					constructor_chain_optional
					enum_define
					enum_item_list
					enum_item_define
					expression_optional
					stmt if_stmt elsif_list elsif
					variable_define block block_optional
%%
root
	: top_level
	| root top_level
	| error '\n'
	{
		$$ = ast_new_blank();
	}
	;
top_level
	: include
	{
		ast_compile_entry($1);
	}
	| alias_T
	{
		ast_compile_entry($1);
	}
	| class_define
	{
		ast_compile_entry($1);
	}
	| func_define
	{
		ast_compile_entry($1);
	}
	| enum_define
	{
		ast_compile_entry($1)
	}
	| stmt
	{
		ast_compile_entry($1);
	}
	;
include
	: USE namespace SEMI
	{
		$$ = ast_new_include($2);
	}
	;
alias_T
	: ALIAS IDENT N_ASSIGN_T namespace SEMI
	{
		$$ = ast_new_alias($2, $4);
	}
	;
namespace
	: IDENT
	{
		$$ = ast_new_namespace($1);
	}
	| namespace DOT IDENT
	{
		$$ = ast_new_namespace_list($1, $3);
	}
	;
class_define
	: CLASS IDENT class_super LCB member_define_list RCB
	{
		$$ = ast_new_class($2, $3, $5);
	}
	;
class_super
	: /* empty */
	{
		$$ = ast_new_blank();
	}
	| COLON IDENT
	{
		$$ = ast_new_superclass($2);
	}
	;
enum_define
	: ENUM IDENT LCB enum_item_list RCB
	{
		$$ = ast_new_enum($2, $4);
	}
	;
enum_item_list
	: enum_item_define
	{
		$$ = $1;
	}
	| enum_item_list COMMA enum_item_define
	{
		$$ = ast_new_enum_item_list($1, $3);
	}
	;
enum_item_define
	: IDENT N_ASSIGN_T expression
	{
		$$ = ast_new_enum_item($1, $3);
	}
	| IDENT
	{
		$$ = ast_new_enum_item($1, ast_new_null());
	}
	;
member_define_list
	: /* empty */
	{
		$$ = ast_new_blank();
	}
	| member_define
	{
		$$ = ast_new_member($1);
	}
	| member_define_list member_define
	{
		$$ = ast_new_member_list($1, $2);
	}
	;
member_define
	: constructor_define
	| func_define
	| field_define
	;
constructor_define
	: modifier_define DEF NEW LRB parameter_list RRB constructor_chain_optional block_optional
	{
		$$ = ast_new_constructor($1, $5, $7, $8);
	}
	| modifier_define DEF NEW LRB RRB constructor_chain_optional block_optional
	{
		$$ = ast_new_constructor($1, ast_new_blank(), $6, $7);
	}
	;
constructor_chain
	: COLON constructor_chain_type_T LRB argument_list RRB
	{
		$$ = ast_new_constructor_chain($2, $4);
	}
	| COLON constructor_chain_type_T LRB RRB
	{
		$$ = ast_new_constructor_chain($2, ast_new_blank());
	}
	;
constructor_chain_type_T
	: SUPER
	{
		$$ = cct_super;
	}
	| THIS
	{
		$$ = cct_this;
	}
	;
constructor_chain_optional
	: /* empty */
	{
		$$ = ast_new_blank();
	}
	| constructor_chain
	;
func_define
	: modifier_define DEF IDENT LRB parameter_list RRB block_optional
	{
		$$ = ast_new_function($1, $3, $5, $7);
	}
	| modifier_define DEF IDENT LRB RRB block_optional
	{
		$$ = ast_new_function_empty_args($1, $3, $6);
	}
	;
field_define
	: modifier_define AT IDENT LRB field_set_get RRB field_default_value
	{
		$$ = ast_new_field($1, $3, $5, $7);
	}
	| modifier_define AT IDENT field_default_value
	{
		$$ = ast_new_field($1, $3, ast_new_blank(), $4);
	}
	;
field_set_get
	: GET N_ASSIGN_T IDENT COMMA SET N_ASSIGN_T IDENT
	{
		$$ = ast_new_field_accessor(ast_new_field_setter($7), ast_new_field_getter($3));
	}
	| SET N_ASSIGN_T IDENT COMMA GET N_ASSIGN_T IDENT
	{
		$$ = ast_new_field_accessor(ast_new_field_setter($3), ast_new_field_getter($7));
	}
	| SET N_ASSIGN_T IDENT
	{
		$$ = ast_new_field_accessor(ast_new_field_setter($3), ast_new_blank());
	}
	| GET N_ASSIGN_T IDENT
	{
		$$ = ast_new_field_accessor(ast_new_blank(), ast_new_field_getter($3));
	}
	;
field_default_value
	: N_ASSIGN_T expression SEMI
	{
		$$ = $2;
	}
	| SEMI
	{
		$$ = ast_new_blank();
	}
	;
modifier_define
	: /* empty */
	{
		$$ = ast_new_modifier(mt_default);
	}
	| LSB modifier_list RSB
	{
		$$ = $2;
	}
	;
modifier_list
	: modifier_type_T
	{
		$$ = ast_new_modifier($1);
	}
	| modifier_list OR modifier_type_T
	{
		$$ = ast_new_modifier_list($1, $3);
	}
	;
modifier_type_T
	: /* empty */
	{
		$$ = mt_default;
	}
	| PUBLIC
	{
		$$ = mt_public;
	}
	| PRIVATE
	{
		$$ = mt_private;
	}
	| PROTECTED
	{
		$$ = mt_protected;
	}
	| STATIC
	{
		$$ = mt_static;
	}
	| FINAL
	{
		$$ = mt_final;
	}
	| NATIVE
	{
		$$ = mt_native;
	}
	;
argument_list
	: expression
	{
		$$ = ast_new_argument_once($1);
	}
	| expression COMMA argument_list
	{
		$$ = ast_new_argument_list($1, $3);
	}
	;
parameter_list
	: IDENT
	{
		$$ = ast_new_parameter($1);
	}
	| IDENT COMMA parameter_list
	{
		$$ = ast_new_parameter_list($1, $3)
	}
	;
stmt_list
	: stmt
	{
		$$ = ast_new_stmt($1);
	}
	| stmt_list stmt
	{
		$$ = ast_new_stmt_list($1, $2);
	}
	;
expression
	: assignExpr
	;
assignExpr
	: or
	| or assign_type assignExpr
	{
		$$ = ast_new_assign_match($1, $2, $3);
	}
	;
assign_type
	: N_ASSIGN_T
	{
		$$ = ao_Assign;
	}
	| ADD_ASSIGN_T
	{
		$$ = ao_Add;
	}
	| SUB_ASSIGN_T
	{
		$$ = ao_Sub;
	}
	| MUL_ASSIGN_T
	{
		$$ = ao_Mul;
	}
	| DIV_ASSIGN_T
	{
		$$ = ao_Div;
	}
	| MOD_ASSIGN_T
	{
		$$ = ao_Mod;
	}
	;
or
	: and
	| or OR and
	{
		$$ = ast_new_or($1, $3);
	}
	| or OROR and
	{
		$$ = ast_new_oror($1, $3);
	}
	;
and
	: equal
	| and AND equal
	{
		$$ = ast_new_and($1, $3);
	}
	| and ANDAND equal
	{
		$$ = ast_new_andand($1, $3);
	}
	;
equal
	: compare
	| equal EQUAL compare
	{
		$$ = ast_new_equal($1, $3);
	}
	| equal NOTEQUAL compare
	{
		$$ = ast_new_notequal($1, $3);
	}
	;
compare
	: addsub
	| compare BIGGEST addsub
	{
		$$ = ast_new_biggest($1, $3);
	}
	| compare EBIGGEST addsub
	{
		$$ = ast_new_e_biggest($1, $3);
	}
	| compare SMALLEST addsub
	{
		$$ = ast_new_smallest($1, $3);
	}
	| compare ESMALLEST addsub
	{
		$$ = ast_new_e_smallest($1, $3);
	}
	;
addsub
	: muldiv
	| addsub ADD muldiv
	{
		$$ = ast_new_add($1, $3);
	}
	| addsub SUB muldiv
	{
		$$ = ast_new_sub($1, $3);
	}
	;
muldiv
	: unary
	| muldiv MUL unary
	{
		$$ = ast_new_mul($1, $3);
	}
	| muldiv DIV unary
	{
		$$ = ast_new_div($1, $3);
	}
	| muldiv MOD unary
	{
		$$ = ast_new_mod($1, $3);
	}
	;
unary
	: prefix
	| NOT unary
	{
		$$ = ast_new_not($2);
	}
	| SUB unary
	{
		$$ = ast_new_minus($2);
	}
	;
prefix
	: postfix
	| INC postfix
	{
		$$ = ast_new_pre_increment($2);
	}
	| DEC postfix
	{
		$$ = ast_new_pre_decrement($2);
	}
	;
postfix
	: primary_expression
	| postfix DOT IDENT
	{
		$$ = ast_new_field_access($1, $3);
	}
	| postfix DOT NEW LRB RRB
	{
		$$ = ast_new_invoke_bymessage_empty_args($1, ast_new_newident());
	}
	| postfix DOT NEW LRB argument_list RRB
	{
		$$ = ast_new_invoke_bymessage($1, ast_new_newident(), $5)
	}
	| postfix DOT IDENT LRB RRB
	{
		$$ = ast_new_invoke_bymessage_empty_args($1, $3);
	}
	| postfix DOT IDENT LRB argument_list RRB
	{
		$$ = ast_new_invoke_bymessage($1, $3, $5)
	}
	| postfix INC
	{
		$$ = ast_new_post_increment($1);
	}
	| postfix DEC
	{
		$$ = ast_new_post_decrement($1);
	}
	;
primary_expression
	: primary_no_new_array
	| new_array
	;
new_array
	: LCB RCB
	{
		$$ = ast_new_array_empty_args();
	}
	| LCB argument_list RCB
	{
		$$ = ast_new_array($2);
	}
	;
primary_no_new_array
	: LRB expression RRB
	{
		$$ = $2;
	}
	| IDENT
	{
		$$ = ast_new_variable($1);
	}
	| IDENT LRB RRB
	{
		$$ = ast_new_invoke_byself_empty_args($1);
	}
	| IDENT LRB argument_list RRB
	{
		$$ = ast_new_invoke_byself($1, $3);
	}
	| TRUE
	{
		$$ = ast_new_true();
	}
	| FALSE
	{
		$$ = ast_new_false();
	}
	| NULL_VALUE
	{
		$$ = ast_new_null();
	}
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| CHAR_LITERAL
	| STRING_LITERAL
	| THIS
	{
		$$ = ast_new_this();
	}
	| SUPER
	{
		$$ = ast_new_super();
	}
	| lambda
	;
lambda
	: LAMBDA LRB parameter_list RRB ARROW block
	{
		$$ = ast_new_lambda($3, $6);
	}
	| LAMBDA LRB RRB ARROW block
	{
		$$ = ast_new_lambda_empty_args($5);
	}
	;
stmt
	: expression SEMI
	{
		$$ = ast_new_stmt($1);
	}
	| if_stmt
	| for_stmt
	| while_stmt
	| try_stmt
	| break_stmt
	| continue_stmt
	| return_stmt
	| throw_stmt
	| variable_define
	| dyn_field_define
	| dyn_method_define
	;
if_stmt
	: IF LRB expression RRB block
	{
		$$ = ast_new_if($3, $5);
	}
	| IF LRB expression RRB block ELSE block
	{
		$$ = ast_new_if_else($3, $5, $7);
	}
	| IF LRB expression RRB block elsif_list
	{
		$$ = ast_new_if_elseif_list($3, $5, $6);
	}
	| IF LRB expression RRB block elsif_list ELSE block
	{
		$$ = ast_new_if_elseif_list_else($3, $5, $6, $8);
	}
	;
elsif_list
	: elsif
	| elsif_list elsif
	{
		$$ = ast_new_elseif_list($1, $2);
	}
	;
elsif
	: ELSEIF LRB expression RRB block
	{
		$$ = ast_new_elseif($3, $5);
	}
	;
for_stmt
	: FOR LRB expression_optional SEMI expression_optional SEMI expression_optional RRB block
	{
		$$ = ast_new_for_stmt($3, $5, $7, $9);
	}
	| for_stmt_fixed
	;
for_stmt_fixed
	: FOR LRB variable_define expression_optional SEMI expression_optional RRB block
	{
		$$ = ast_new_for_stmt($3, $4, $6, $8);
	}
	;
while_stmt
	: WHILE LRB expression RRB block
	{
		$$ = ast_new_while_stmt($3, $5);
	}
	;
try_stmt
	: TRY block CATCH LRB IDENT RRB block FINALLY block
	{
		$$ = ast_new_try_catch_finally_stmt($2, $5, $7, $9);
	}
	| TRY block FINALLY block
	{
		$$ = ast_new_try_finally_stmt($2, $4);
	}
	| TRY block CATCH LRB IDENT RRB block
	{
		$$ = ast_new_try_catch_stmt($2, $5, $7);
	}
	;
break_stmt
	: BREAK SEMI
	{
		$$ = ast_new_break();
	}
	;
continue_stmt
	: CONTINUE SEMI
	{
		$$ = ast_new_continue();
	}
	;
return_stmt
	: RETURN SEMI
	{
		$$ = ast_new_return_empty();
	}
	| RETURN expression SEMI
	{
		$$ = ast_new_return($2);
	}
	;
throw_stmt
	: THROW expression SEMI
	{
		$$ = ast_new_throw_stmt($2);
	}
	;
variable_define
	: VAR IDENT N_ASSIGN_T expression SEMI
	{
		$$ = ast_new_variable_decl($2, $4);
	}
	;
dyn_field_define
	: expression COLO_COLO IDENT N_ASSIGN_T expression SEMI
	{
		$$ = ast_new_dyn_field($1, $3, $5);
	}
	;
dyn_method_define
	: expression COLO_COLO IDENT LRB RRB N_ASSIGN_T lambda SEMI
	{
		$$ = ast_new_dyn_method($1, $3, $7);
	}
	; 
expression_optional
	: /* empty */
	{
		$$ = ast_new_blank();
	}
	| expression
	;
block
	: LCB stmt_list RCB
	{
		$$ = ast_new_codeblock($2);
	}
	| LCB RCB
	{
		$$ = ast_new_codeblock_empty();
	}
	;
block_optional
	: SEMI
	{
		$$ = ast_new_blank();
	}
	| block
	;
%%