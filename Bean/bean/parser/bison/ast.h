#pragma once
/**
 * @file ast.h
 * @brief	C言語のレベルで提供されるASTです。
 *			後で C++ 向けに再変換されます。
 */
#ifndef BEAN_PARSER_BISON_AST_H
#define BEAN_PARSER_BISON_AST_H
#include "assign_type.h"
#include "bool.h"
#include "constructor_chain_type.h"
#include "list.h"
#include "modifier_type.h"
#include "string.h"
#include "string_buffer.h"

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * AST(Abstract Source Tree) の種類を表すタグです.
	 * 再帰構造を表すために、 C++側で展開される xxxList というタグが使用されます。
	 */
	typedef enum ast_tag {
		t_YACC_ROOT,
		t_YACC_ROOOT_LIST,
		t_Root,
		t_Blank,
		t_CodeBlock,
		t_Add,
		t_Sub,
		t_Mul,
		t_Div,
		t_Mod,

		t_Def_Dyn_Field,
		t_Def_Dyn_Method,

		t_This,
		t_Super,

		t_Namespace,
		t_NamespaceList,

		t_Add_Assign,
		t_Sub_Assign,
		t_Mul_Assign,
		t_Div_Assign,
		t_Mod_Assign,

		t_Not,
		t_Minus,

		t_Or,
		t_OrOr,
		t_And,
		t_AndAnd,

		t_Equal,
		t_NotEqual,

		t_Biggest,
		t_EBiggest,
		t_Smallest,
		t_ESmallest,

		t_FieldAccess,
		t_InvokeBySelf,
		t_InvokeByMessage,

		t_Lambda,
		t_Class,
		t_SuperClass,

		t_Constructor,
		t_ConstructorChainThis,
		t_ConstructorChainSuper,

		t_Enum,
		t_EnumItem,
		t_EnumItem_List,

		t_MemberList,
		t_Function,
		t_Field,
		t_FieldAccessor,
		t_FieldSetter,
		t_FieldGetter,
		t_ModifierList,
		t_Public,
		t_Private,
		t_Protected,
		t_Static,
		t_Native,
		t_Final,
		t_Modifier_Blank,
		t_Argument,
		t_ArgumentList,

		t_Parameter,
		t_ParameterList,
		t_Variable,
		t_VariableDecl,
		t_Include,
		t_Alias,

		t_For,
		t_While,
		t_Break,
		t_Return,
		t_Continue,

		t_If,
		t_Else,
		t_IfElse,
		t_IfElseIfList,
		t_IfElseIfListElse,
		t_ElseIfList,
		t_ElseIf,

		t_Stmt,
		t_StmtList,

		t_PreIncrement,
		t_PreDecrement,
		t_PostIncrement,
		t_PostDecrement,

		t_Null,
		t_Ident,
		t_Assign,

		t_TryCatch,
		t_TryFinally,
		t_TryCatchFinally,
		t_Try,
		t_Catch,
		t_CatchFinally,
		t_Finally,
		t_Throw,

		t_Short,
		t_Int,
		t_Long,
		t_Float,
		t_Double,

		t_True,
		t_False,
		t_Character,
		t_String,
		t_Array
	} ast_tag;

	/**
	 * ソースコード中の要素を表します.
	 */
	typedef struct ast {
		union {
			short short_value;
			int int_value;
			long long_value;
			float float_value;
			double double_value;
			YYBChar char_value;
			YYBString string_value;
			BBOOL bool_value;
		} u;
		ast_tag tag;
		list* children;
		BBOOL allocStr;
	} ast;

	/**
	 * 指定のノードを検索するかどうかを返します.
	 * @param node
	 * @return bool
	 */
	typedef BBOOL(*ast_filter)(ast* node);

	/**
	 * 更に子階層を検索するかどうかを返します.
	 * @param node
	 * @param bool
	 */
	typedef BBOOL(*ast_tree)(ast* node);

	/**
	 * 指定のノードを追加するかどうかを返します.
	 * @param node
	 * @return bool
	 */
	typedef BBOOL(*ast_accept)(ast* node);

	/**
	 * string_buffer と同様の理由で使用されます。
	 */
	void ast_start_compile();
	/**
	 * string_buffer と同様の理由で使用されます。
	 */
	void ast_link_object(ast* elem);
	/**
	 * string_buffer と同様の理由で使用されます。
	 */
	void ast_end_compile(BBOOL fail);

	ast* ast_push(ast* val, ast* next);
	ast* ast_get_first(ast* val);
	ast* ast_get_left(ast* val);
	ast* ast_get_right(ast* val);
	ast* ast_set_childAt(ast* val, int index, ast* newVal);
	ast* ast_get_childAt(ast* val, int index);
	ast* ast_malloc();
	ast* ast_malloc_array(int length);
	ast* ast_new_root(ast* val);
	ast* ast_new_root_list(ast* forward, ast* tail);
	ast* ast_new_codeblock(ast* val);
	ast* ast_new_codeblock_empty();
	ast* ast_new_parameter(YYBString str);
	ast* ast_new_parameter_list(YYBString forward, ast* tail);
	ast* ast_new_unary(ast_tag t, ast* leaf);
	ast* ast_new_not(ast* leaf);
	ast* ast_new_minus(ast* leaf);
	ast* ast_new_binary(ast_tag t, ast* left, ast* right);
	ast* ast_new_or(ast* left, ast* right);
	ast* ast_new_oror(ast* left, ast* right);
	ast* ast_new_and(ast* left, ast* right);
	ast* ast_new_andand(ast* left, ast* right);
	ast* ast_new_biggest(ast* left, ast* right);
	ast* ast_new_e_biggest(ast* left, ast* right);
	ast* ast_new_smallest(ast* left, ast* right);
	ast* ast_new_e_smallest(ast* left, ast* right);
	ast* ast_new_equal(ast* left, ast* right);
	ast* ast_new_notequal(ast* left, ast* right);
	ast* ast_new_add(ast* left, ast* right);
	ast* ast_new_sub(ast* left, ast* right);
	ast* ast_new_mul(ast* left, ast* right);
	ast* ast_new_div(ast* left, ast* right);
	ast* ast_new_mod(ast* left, ast* right);
	ast* ast_new_assign_match(ast* left, assign_type t, ast* right);
	ast* ast_new_assign(ast* left, ast* right);
	ast* ast_new_add_assign(ast* left, ast* right);
	ast* ast_new_sub_assign(ast* left, ast* right);
	ast* ast_new_mul_assign(ast* left, ast* right);
	ast* ast_new_div_assign(ast* left, ast* right);
	ast* ast_new_mod_assign(ast* left, ast* right);
	ast* ast_new_argument_once(ast* val);
	ast* ast_new_argument_list(ast* forward, ast* tail);
	ast* ast_new_short(short value);
	ast* ast_new_int(int value);
	ast* ast_new_long(long value);
	ast* ast_new_float(float value);
	ast* ast_new_double(double value);
	ast* ast_new_bool(BBOOL value);
	ast* ast_new_true();
	ast* ast_new_false();
	ast* ast_new_null();
	ast* ast_new_this();
	ast* ast_new_super();
	ast* ast_new_field_access(ast* fact, YYBString name);
	ast* ast_new_array(ast* argument_list);
	ast* ast_new_array_empty_args();
	ast* ast_new_pre_increment(ast* val);
	ast* ast_new_pre_decrement(ast* val);
	ast* ast_new_post_increment(ast* val);
	ast* ast_new_post_decrement(ast* val);
	ast* ast_new_char(YYBChar value);
	ast* ast_new_string(YYBString value);
	ast* ast_new_ident(YYBString value);
	ast* ast_new_stmt(ast* val);
	ast* ast_new_if(ast* cond, ast* body);
	ast* ast_new_else(ast* body);
	ast* ast_new_if_else(ast* cond, ast* trueBody, ast* falseBody);
	ast* ast_new_if_elseif_list(ast* cond, ast* trueBody, ast* elseifList);
	ast* ast_new_if_elseif_list_else(ast* cond, ast* trueBody, ast* elseifList, ast* elseBody);
	ast* ast_new_elseif_list(ast* forward, ast* tail);
	ast* ast_new_elseif(ast* cond, ast* body);
	ast* ast_new_field_access(ast* val, YYBString field);
	ast* ast_new_variable(YYBString name);
	ast* ast_new_variable_decl(YYBString name, ast* val);
	ast* ast_new_invoke_byself(YYBString name, ast* val);
	ast* ast_new_invoke_byself_empty_args(YYBString name);
	ast* ast_new_invoke_bymessage(ast* invoker, YYBString name, ast* val);
	ast* ast_new_invoke_bymessage_empty_args(ast* invoker, YYBString name);
	ast* ast_new_for_stmt(ast* init, ast* cond, ast* update, ast* body);
	ast* ast_new_while_stmt(ast* cond, ast* body);
	ast* ast_new_throw_stmt(ast* val);
	ast* ast_new_try_catch_stmt(ast* tryBlock, YYBString captureName, ast* catchBlock);
	ast* ast_new_try_finally_stmt(ast* tryBlock, ast* finallyBlock);
	ast* ast_new_try_catch_finally_stmt(ast* tryBlock, YYBString captureName, ast* catchBlock, ast* finallyBlock);
	ast* ast_new_try(ast* tryBlock);
	ast* ast_new_catch(YYBString captureName, ast* catchBlock);
	ast* ast_new_finally(ast* finallyBlock);
	ast* ast_new_lambda(ast* parameter_list, ast* block);
	ast* ast_new_lambda_empty_args(ast* block);
	ast* ast_new_blank();
	ast* ast_new_break();
	ast* ast_new_continue();
	ast* ast_new_return(ast* val);
	ast* ast_new_return_empty();
	ast* ast_new_namespace(YYBString str);
	ast* ast_new_namespace_list(ast* forward, YYBString str);
	ast* ast_new_include(ast* nsp);
	ast* ast_new_alias(YYBString newname, ast* oldname);
	ast* ast_new_modifier(modifier_type mt);
	ast* ast_new_modifier_list(ast* forward, modifier_type tail);
	ast* ast_new_function(ast* mod, YYBString name, ast* args, ast* block);
	ast* ast_new_function_empty_args(ast* mod, YYBString name, ast* block);
	ast* ast_new_field(ast* modifier, YYBString name, ast* accessor, ast* defaultValue);
	ast* ast_new_field_accessor(ast* set, ast* get);
	ast* ast_new_field_setter(YYBString name);
	ast* ast_new_field_getter(YYBString name);
	ast* ast_new_member(ast* member);
	ast* ast_new_member_list(ast* forward, ast* member);
	ast* ast_new_class(YYBString name, ast* super, ast* member_list);
	ast* ast_new_superclass(YYBString super);
	ast* ast_new_enum(YYBString name, ast* enum_items);
	ast* ast_new_enum_item(YYBString name, ast* value);
	ast* ast_new_enum_item_list(ast* forward, ast* tail);
	ast* ast_new_stmt(ast* val);
	ast* ast_new_stmt_list(ast* forward, ast* tail);
	ast* ast_new_constructor_chain(constructor_chain_type cct, ast* argument_list);
	ast* ast_new_constructor(ast* modifier_list, ast* parameter_list, ast* chain, ast* block);
	ast* ast_new_dyn_field(ast* val, YYBString name, ast* dynFieldValue);
	ast* ast_new_dyn_method(ast* val, YYBString name, ast* dynMethodValue);
	//
	//ast_expand_XXX
	//リスト/タプルの入れ子構造をフラットなリストに展開します
	//
	list* ast_expand_generic(ast* node, ast_filter f, ast_tree t, ast_accept a);

	list* ast_expand_members(ast* classz);

	list* ast_expand_modifiers(ast* member);

	list* ast_expand_parameters(ast* funcDefine);

	list* ast_expand_arguments(ast* argument_list);

	list* ast_expand_namespaces(ast* namespace_list);

	list* ast_expand_stmts(ast* block);

	list* ast_expand_enumitems(ast* enum_item_list);

	//
	//ast_filterXXX
	//
	BBOOL ast_filter_class(ast* node);

	BBOOL ast_filter_member(ast* node);

	BBOOL ast_filter_func_define(ast* node);

	BBOOL ast_filter_argument(ast* node);

	BBOOL ast_filter_namespace(ast* node);

	BBOOL ast_filter_block(ast* node);

	BBOOL ast_filter_enum(ast* node);

	BBOOL ast_filter_true(ast* node);

	BBOOL ast_filter_false(ast* node);

	//
	//ast_tree_XXX
	//
	BBOOL ast_tree_member_list(ast* node);

	BBOOL ast_tree_modifier_list(ast* node);

	BBOOL ast_tree_paramter_list(ast* node);

	BBOOL ast_tree_argument_list(ast* node);

	BBOOL ast_tree_namespace_list(ast* node);

	BBOOL ast_tree_stmt_list(ast* node);

	BBOOL ast_tree_enum_item_list(ast* node);

	BBOOL ast_tree_true(ast* node);

	BBOOL ast_tree_false(ast* node);

	//
	//ast_accept_XXX
	//
	BBOOL ast_accept_member(ast* node);

	BBOOL ast_accept_modifier(ast* node);

	BBOOL ast_accept_parameter(ast* node);

	BBOOL ast_accept_argument(ast* node);

	BBOOL ast_accept_namespace(ast* node);

	BBOOL ast_accept_enum_item(ast* node);

	BBOOL ast_accept_stmt(ast* node);

	//
	//ast_extract_FROM_TO
	//リスト/タプルから指定の属性を取り出します.
	//
	YYBString ast_field_extract_name(ast* field);

	ast* ast_field_extract_accessor(ast* field);

	ast* ast_field_extract_default_value(ast* field);

	ast* ast_accessor_extract_setter(ast* accessor);

	ast* ast_accessor_extract_getter(ast* accessor);

	YYBString ast_setter_extract_name(ast* setter);

	YYBString ast_getter_extract_name(ast* getter);

	ast* ast_function_extract_modifier_list(ast* func_define);

	YYBString ast_function_extract_name(ast* func_define);

	ast* ast_function_extract_parameter_list(ast* func_define);

	ast* ast_function_extract_block(ast* func_define);

	YYBString ast_vardefine_extract_name(ast* var_define);

	ast* ast_vardefine_extract_fact(ast* var_define);

	YYBString ast_invoke_by_self_extract_name(ast* invokeBySelf);

	ast* ast_invoke_by_self_extract_argument_list(ast* invokeBySelf);

	YYBString ast_invoke_by_message_extract_name(ast* invokeByMessage);

	ast* ast_invoke_by_message_extract_argument_list(ast* invokeByMessage);

	ast* ast_invoke_by_message_extract_invoker(ast* invokeByMessage);

	ast* ast_inc_dec_extract_argument(ast* inc_dec);

	ast* ast_if_extract_cond(ast* if_stmt);

	ast* ast_if_extract_body(ast* if_stmt);

	ast* ast_if_else_extract_if(ast* if_else_stmt);

	ast* ast_if_else_extract_else(ast* if_else_stmt);

	ast* ast_else_extract_body(ast* else_stmt);

	ast* ast_if_elseif_list_extract_if(ast* if_elseif_stmt);

	ast* ast_if_elseif_list_extract_elseif_list(ast* if_elseif_stmt_list);

	ast* ast_elseif_extract_cond(ast* elseif_stmt);

	ast* ast_elseif_extract_body(ast* elseif_stmt);

	ast* ast_if_elseif_list_else_extract_if_elseif_list(ast* if_elseif_list_else);

	ast* ast_if_elseif_list_else_extract_elseif_list(ast* if_elseif_list_else);

	ast* ast_if_elseif_list_else_extract_else(ast* if_elseif_list_else);

	ast* ast_while_extract_cond(ast* while_stmt);

	ast* ast_while_extract_body(ast* while_stmt);

	ast* ast_for_extract_init(ast* for_stmt);

	ast* ast_for_extract_cond(ast* for_stmt);

	ast* ast_for_extract_update(ast* for_stmt);

	ast* ast_for_extract_body(ast* for_stmt);

	ast* ast_try_catch_extract_try(ast* try_catch_stmt);

	ast* ast_try_catch_extract_catch(ast* try_catch_stmt);

	ast* ast_try_extract_body(ast* try_stmt);

	YYBString ast_catch_extract_capturename(ast* catch_stmt);

	ast* ast_catch_extract_body(ast* catch_stmt);

	ast* ast_try_catch_finally_extract_try(ast* try_catch_finally);

	ast* ast_try_catch_finally_extract_catch_finally(ast* try_catch_finally);

	ast* ast_catch_finally_extract_catch(ast* catch_finally);

	ast* ast_catch_finally_extract_finally(ast* catch_finally);

//	ast* ast_catch_extract_body(ast* catch_stmt);

	ast* ast_finally_extract_body(ast* finally_stmt);

	ast* ast_try_finally_extract_try(ast* try_finally);

	ast* ast_try_finally_extract_finally(ast* try_finally);

	ast* ast_throw_extract_fact(ast* throw_stmt);

	ast* ast_return_extract_fact(ast* return_stmt);

	YYBString ast_class_extract_name(ast* classDecl);

	ast* ast_class_extract_superclass(ast* classDecl);

	YYBString ast_superclass_extract_name(ast* superclass);

	ast* ast_lambda_extract_parameter_list(ast* lambdaDecl);

	ast* ast_lambda_extract_block(ast* lambdaDecl);

	ast* ast_array_extract_argument_list(ast* array_init);

	ast* ast_field_access_extract_fact(ast* field_access);

	YYBString ast_field_access_extract_name(ast* field_access);

	YYBString ast_enum_extract_name(ast* enum_define);

	ast* ast_enum_extract_enum_item_list(ast* enum_item_list);

	YYBString ast_enum_item_extract_name(ast* enum_item);

	ast* ast_enum_item_extract_value(ast* enum_item);

	ast* ast_constructor_extract_modifier(ast* constructor);

	ast* ast_constructor_extract_parameter_list(ast* constructor);

	ast* ast_constructor_extract_constructor_chain(ast* constructor);

	ast* ast_constructor_extract_block(ast* constructor);

	constructor_chain_type ast_constructor_chain_extract_type(ast* constructor_chain);

	ast* ast_constructor_chain_extract_argument_list(ast* constructor_chain);

	/**
	 * ASTの直下のリストを解放します.
	 * @param val
	 */
	void ast_free(ast* val);

	/**
	 * ASTを再帰的に解放します.
	 * @param val
	 */
	void ast_delete(ast* val);

	/**
	 * ASTとASTの直下のリストを解放します.
	 * @param val
	 */
	void ast_single_delete(ast* val);

	/**
	 * ASTを再帰的にダンプします.
	 * @param val
	 */
	void ast_dump(ast* val);

	/**
	 * list の要素を ASTにキャストしてダンプします.
	 * @param val
	 */
	void ast_dump_all(list* val);

	/**
	 * 指定の要素が空なら true.
	 * @param val
	 */
	BBOOL ast_is_blank(ast* val);

	/**
	 * new を表す文字列を確保して返します.
	 * @return
	 */
	YYBString ast_new_newident();

	/**
	 * listに格納された要素を文字列へ変換して全て連結して返します.
	 * @param val
	 * @return
	 */
	string_buffer* ast_sum_string(list* val);

	/**
	 * listに格納された要素を文字列へ変換して全て c を挟むように連結して返します.
	 * @param val
	 * @param c
	 * @return
	 */
	string_buffer* ast_join_string(list* val, YYBChar c);

	/**
	 * 指定の要素をコンパイラに紐づけます.
	 * 紐づけられた要素はコンパイラが破棄されるときに一緒に破棄されます。
	 * @param val
	 * @return
	 */
	ast* ast_compile_entry(ast* val);

	YYBString ast_ident_wrap(YYBString str);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_AST_H
