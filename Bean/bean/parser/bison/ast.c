#include "ast.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"
#include "mem.h"

//proto type
void p__ast_strcpy(ast* val, YYBString str);
void p__ast_dump(ast* val, int depth);
void p__ast_tag(ast* val);
void p__ast_indent(int depth);
compiler* p__ast_get_compiler();
void p__ast_delete(ast* val, int size);

//public
list* ast_garbage_list = NULL;
void ast_start_compile() {
	assert(ast_garbage_list == NULL);
	ast_garbage_list = list_new();
}

void ast_link_object(ast * elem) {
	assert(ast_garbage_list != NULL);
	list_add(ast_garbage_list, elem);
}

void ast_end_compile(BBOOL fail) {
	if (fail == BTRUE) {
		list_delete_with_item(ast_garbage_list, ast_single_delete);
	} else {
		list_delete(ast_garbage_list);
	}
	ast_garbage_list = NULL;
}

ast * ast_push(ast * val, ast* next) {
	list_add(val->children, next);
	return next;
}

ast * ast_get_first(ast* val) {
	return ast_get_childAt(val, 0);
}

ast * ast_get_left(ast* val) {
	return ast_get_childAt(val, 0);
}

ast * ast_get_right(ast* val) {
	return ast_get_childAt(val, 1);
}

ast * ast_set_childAt(ast * val, int index, ast* newVal) {
	//return list_getAt(val, index);
	return NULL;
}

ast * ast_get_childAt(ast* val, int index) {
	return list_getAt(val->children, index);
}

ast * ast_malloc() {
	ast* ret = (ast*)mem_malloc(sizeof(ast));
	ret->children = list_new();
	ret->u.string_value = NULL;
	ret->allocStr = BFALSE;
	ast_link_object(ret);
	return ret;
}

ast * ast_malloc_array(int length) {
	return (ast*)mem_malloc(sizeof(ast) * length);
}

ast * ast_new_root(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_YACC_ROOT;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_root_list(ast * forward, ast * tail) {
	ast* ret = ast_malloc();
	ret->tag = t_YACC_ROOOT_LIST;
	list_add(ret->children, forward);
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_codeblock(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_CodeBlock;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_codeblock_empty() {
	ast* ret = ast_malloc();
	ret->tag = t_CodeBlock;
	return ret;
}

ast * ast_new_parameter(YYBString str) {
	ast* ret = ast_malloc();
	ret->tag = t_Parameter;
	p__ast_strcpy(ret, str);
	return ret;
}

ast * ast_new_parameter_list(YYBString forward, ast* tail) {
	ast* ret = ast_malloc();
	ret->tag = t_ParameterList;
	list_add(ret->children, ast_new_parameter(forward));
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_unary(ast_tag t, ast* leaf) {
	ast* ret = ast_malloc();
	ret->tag = t;
	list_add(ret->children, leaf);
	return ret;
}

ast * ast_new_not(ast * leaf) {
	return ast_new_unary(t_Not, leaf);
}

ast * ast_new_minus(ast * leaf) {
	return ast_new_unary(t_Minus, leaf);
}

ast * ast_new_binary(ast_tag t, ast* left, ast* right) {
	ast* ret = ast_malloc();
	ret->tag = t;
	list_add(ret->children, left);
	list_add(ret->children, right);
	return ret;
}

ast * ast_new_or(ast * left, ast * right) {
	return ast_new_binary(t_Or, left, right);
}

ast * ast_new_oror(ast * left, ast * right) {
	return ast_new_binary(t_OrOr, left, right);
}

ast * ast_new_and(ast * left, ast * right) {
	return ast_new_binary(t_And, left, right);
}

ast * ast_new_andand(ast * left, ast * right) {
	return ast_new_binary(t_AndAnd, left, right);
}

ast * ast_new_biggest(ast * left, ast * right) {
	return ast_new_binary(t_Biggest, left, right);
}

ast * ast_new_e_biggest(ast * left, ast * right) {
	return ast_new_binary(t_EBiggest, left, right);
}

ast * ast_new_smallest(ast * left, ast * right) {
	return ast_new_binary(t_Smallest, left, right);
}

ast * ast_new_e_smallest(ast * left, ast * right) {
	return ast_new_binary(t_ESmallest, left, right);
}

ast * ast_new_equal(ast * left, ast * right) {
	return ast_new_binary(t_Equal, left, right);
}

ast * ast_new_notequal(ast * left, ast * right) {
	return ast_new_binary(t_NotEqual, left, right);
}

ast * ast_new_add(ast * left, ast * right) {
	return ast_new_binary(t_Add, left, right);
}

ast * ast_new_sub(ast * left, ast * right) {
	return ast_new_binary(t_Sub, left, right);
}

ast * ast_new_mul(ast * left, ast * right) {
	return ast_new_binary(t_Mul, left, right);
}

ast * ast_new_div(ast * left, ast * right) {
	return ast_new_binary(t_Div, left, right);
}

ast * ast_new_mod(ast * left, ast * right) {
	return ast_new_binary(t_Mod, left, right);
}

ast * ast_new_assign_match(ast * left, assign_type t, ast * right) {
	if (t == ao_Assign) {
		return ast_new_assign(left, right);
	} else if (t == ao_Add) {
		return ast_new_add_assign(left, right);
	} else if (t == ao_Sub) {
		return ast_new_sub_assign(left, right);
	} else if (t == ao_Mul) {
		return ast_new_mul_assign(left, right);
	} else if (t == ao_Div) {
		return ast_new_div_assign(left, right);
	} else if (t == ao_Mod) {
		return ast_new_mod_assign(left, right);
	}
	return NULL;
}

ast * ast_new_assign(ast * left, ast * right) {
	return ast_new_binary(t_Assign, left, right);
}

ast * ast_new_add_assign(ast * left, ast * right) {
	return ast_new_binary(t_Add_Assign, left, right);
}

ast * ast_new_sub_assign(ast * left, ast * right) {
	return ast_new_binary(t_Sub_Assign, left, right);
}

ast * ast_new_mul_assign(ast * left, ast * right) {
	return ast_new_binary(t_Mul_Assign, left, right);
}

ast * ast_new_div_assign(ast * left, ast * right) {
	return ast_new_binary(t_Div_Assign, left, right);
}

ast * ast_new_mod_assign(ast * left, ast * right) {
	return ast_new_binary(t_Mod_Assign, left, right);
}

ast * ast_new_argument_once(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_Argument;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_argument_list(ast * forward, ast * tail) {
	ast* ret = ast_malloc();
	ret->tag = t_ArgumentList;
	list_add(ret->children, forward);
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_short(short value) {
	ast* ret = ast_malloc();
	ret->tag = t_Short;
	ret->u.short_value = value;
	return ret;
}

ast * ast_new_int(int value) {
	ast* ret = ast_malloc();
	ret->tag = t_Int;
	ret->u.int_value = value;
	return ret;
}

ast * ast_new_long(long value) {
	ast* ret = ast_malloc();
	ret->tag = t_Long;
	ret->u.long_value = value;
	return ret;
}

ast * ast_new_float(float value) {
	ast* ret = ast_malloc();
	ret->tag = t_Float;
	ret->u.float_value = value;
	return ret;
}

ast * ast_new_double(double value) {
	ast* ret = ast_malloc();
	ret->tag = t_Double;
	ret->u.double_value = value;
	return ret;
}

ast * ast_new_bool(BBOOL value) {
	ast* ret = ast_malloc();
	ret->tag = value == BTRUE ? t_True : t_False;
	ret->u.bool_value = value;
	return ret;
}

ast * ast_new_true() {
	return ast_new_bool(BTRUE);
}

ast * ast_new_false() {
	return ast_new_bool(BFALSE);
}

ast * ast_new_null() {
	ast* ret = ast_malloc();
	ret->tag = t_Null;
	return ret;
}

ast * ast_new_this() {
	ast* ret = ast_malloc();
	ret->tag = t_This;
	return ret;
}

ast * ast_new_super() {
	ast* ret = ast_malloc();
	ret->tag = t_Super;
	return ret;
}

ast * ast_new_array(ast * argument_list) {
	ast* ret = ast_malloc();
	ret->tag = t_Array;
	list_add(ret->children, argument_list);
	return ret;
}

ast * ast_new_array_empty_args() {
	return ast_new_array(ast_new_blank());
}

ast * ast_new_pre_increment(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_PreIncrement;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_pre_decrement(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_PreDecrement;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_post_increment(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_PostIncrement;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_post_decrement(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_PostDecrement;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_char(YYBChar value) {
	ast* ret = ast_malloc();
	ret->tag = t_Character;
	ret->u.char_value = value;
	return ret;
}

ast * ast_new_string(YYBString value) {
	ast* ret = ast_malloc();
	ret->tag = t_String;
	p__ast_strcpy(ret, value);
	return ret;
}

ast * ast_new_ident(YYBString value) {
	ast* ret = ast_malloc();
	ret->tag = t_Ident;
	p__ast_strcpy(ret, value);
	return ret;
}

ast * ast_new_if(ast * cond, ast * body) {
	ast* ret = ast_malloc();
	ret->tag = t_If;
	list_add(ret->children, cond);
	list_add(ret->children, body);
	return ret;
}

ast * ast_new_else(ast * body) {
	ast* ret = ast_malloc();
	ret->tag = t_Else;
	list_add(ret->children, body);
	return ret;
}

ast * ast_new_if_else(ast * cond, ast * trueBody, ast * falseBody) {
	ast* ret = ast_malloc();
	ret->tag = t_IfElse;
	list_add(ret->children, ast_new_if(cond, trueBody));
	list_add(ret->children, ast_new_else(falseBody));
	return ret;
}

ast * ast_new_if_elseif_list(ast * cond, ast * trueBody, ast * elseifList) {
	ast* ret = ast_malloc();
	ret->tag = t_IfElseIfList;
	list_add(ret->children, ast_new_if(cond, trueBody));
	list_add(ret->children, elseifList);
	return ret;
}

ast * ast_new_if_elseif_list_else(ast * cond, ast * trueBody, ast * elseifList, ast * elseBody) {
	ast* ret = ast_malloc();
	ret->tag = t_IfElseIfListElse;
	list_add(ret->children, ast_new_if_elseif_list(cond, trueBody, elseifList));
	list_add(ret->children, ast_new_else(elseBody));
	return ret;
}

ast * ast_new_elseif_list(ast * forward, ast * tail) {
	ast* ret = ast_malloc();
	ret->tag = t_ElseIfList;
	list_add(ret->children, forward);
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_elseif(ast * cond, ast * body) {
	ast* ret = ast_malloc();
	ret->tag = t_ElseIf;
	list_add(ret->children, cond);
	list_add(ret->children, body);
	return ret;
}

ast * ast_new_field_access(ast * val, YYBString field) {
	ast* ret = ast_malloc();
	ret->tag = t_FieldAccess;
	p__ast_strcpy(ret, field);
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_variable(YYBString name) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, name);
	ret->tag = t_Variable;
	return ret;
}

ast * ast_new_variable_decl(YYBString name, ast* val) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, name);
	ret->tag = t_VariableDecl;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_invoke_byself(YYBString name, ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_InvokeBySelf;
	p__ast_strcpy(ret, name);
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_invoke_byself_empty_args(YYBString name) {
	ast* ret = ast_malloc();
	ret->tag = t_InvokeBySelf;
	p__ast_strcpy(ret, name);
	list_add(ret->children, ast_new_blank());
	return ret;
}

ast * ast_new_invoke_bymessage(ast * invoker, YYBString name, ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_InvokeByMessage;
	p__ast_strcpy(ret, name);
	list_add(ret->children, invoker);
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_invoke_bymessage_empty_args(ast * invoker, YYBString name) {
	ast* ret = ast_malloc();
	ret->tag = t_InvokeByMessage;
	p__ast_strcpy(ret, name);
	list_add(ret->children, invoker);
	list_add(ret->children, ast_new_blank());
	return ret;
}

ast * ast_new_for_stmt(ast * init, ast * cond, ast * update, ast * body) {
	ast* ret = ast_malloc();
	ret->tag = t_For;
	list_add(ret->children, init);
	list_add(ret->children, cond);
	list_add(ret->children, update);
	list_add(ret->children, body);
	return ret;
}

ast * ast_new_while_stmt(ast * cond, ast * body) {
	ast* ret = ast_malloc();
	ret->tag = t_While;
	list_add(ret->children, cond);
	list_add(ret->children, body);
	return ret;
}

ast * ast_new_throw_stmt(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_Throw;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_try_catch_stmt(ast * tryBlock, YYBString captureName, ast * catchBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_TryCatch;
	list_add(ret->children, ast_new_try(tryBlock));
	list_add(ret->children, ast_new_catch(captureName, catchBlock));
	return ret;
}

ast * ast_new_try_finally_stmt(ast * tryBlock, ast * finallyBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_TryFinally;
	list_add(ret->children, ast_new_try(tryBlock));
	list_add(ret->children, ast_new_finally(finallyBlock));
	return ret;
}

ast * ast_new_try_catch_finally_stmt(ast * tryBlock, YYBString captureName, ast * catchBlock, ast * finallyBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_TryCatchFinally;
	list_add(ret->children, ast_new_try(tryBlock));

	ast* cf = ast_malloc();
	cf->tag = t_CatchFinally;
	list_add(cf->children, ast_new_catch(captureName, catchBlock));
	list_add(cf->children, ast_new_finally(finallyBlock));

	list_add(ret->children, cf);
	return ret;
}

ast * ast_new_try(ast * tryBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_Try;
	list_add(ret->children, tryBlock);
	return ret;
}

ast * ast_new_catch(YYBString captureName, ast * catchBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_Catch;
	p__ast_strcpy(ret, captureName);
	list_add(ret->children, catchBlock);
	return ret;
}

ast * ast_new_finally(ast * finallyBlock) {
	ast* ret = ast_malloc();
	ret->tag = t_Finally;
	list_add(ret->children, finallyBlock);
	return ret;
}

ast * ast_new_lambda(ast * parameter_list, ast * block) {
	ast* ret = ast_malloc();
	ret->tag = t_Lambda;
	list_add(ret->children, parameter_list);
	list_add(ret->children, block);
	return ret;
}

ast * ast_new_lambda_empty_args(ast * block) {
	return ast_new_lambda(ast_new_blank(), block);
}

ast * ast_new_blank() {
	ast* ret = ast_malloc();
	ret->tag = t_Blank;
	return ret;
}

ast * ast_new_break() {
	ast* ret = ast_malloc();
	ret->tag = t_Break;
	return ret;
}

ast * ast_new_continue() {
	ast* ret = ast_malloc();
	ret->tag = t_Continue;
	return ret;
}

ast * ast_new_return(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_Return;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_return_empty() {
	ast* ret = ast_malloc();
	ret->tag = t_Return;
	list_add(ret->children, ast_new_blank());
	return ret;
}

ast * ast_new_namespace(YYBString str) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, str);
	ret->tag = t_Namespace;
	return ret;
}

ast * ast_new_namespace_list(ast * forward, YYBString str) {
	ast* ret = ast_malloc();
//	p__ast_strcpy(ret, str);
	ret->tag = t_NamespaceList;
	list_add(ret->children, forward);
	list_add(ret->children, ast_new_namespace(str));
	return ret;
}

ast * ast_new_include(ast * nsp) {
	ast* ret = ast_malloc();
	ret->tag = t_Include;
	list_add(ret->children, nsp);
	return ret;
}

ast * ast_new_alias(YYBString newname, ast * oldname) {
	ast* ret = ast_malloc();
	ret->tag = t_Alias;
	p__ast_strcpy(ret, newname);
	list_add(ret->children, oldname);
	return ret;
}

ast * ast_new_modifier(modifier_type mt) {
	ast* ret = ast_malloc();
	switch (mt) {
		case mt_default:
			ret->tag = t_Modifier_Blank;
			break;
		case mt_public:
			ret->tag = t_Public;
			break;
		case mt_private:
			ret->tag = t_Private;
			break;
		case mt_protected:
			ret->tag = t_Protected;
			break;
		case mt_static:
			ret->tag = t_Static;
			break;
		case mt_final:
			ret->tag = t_Final;
			break;
		case mt_native:
			ret->tag = t_Native;
			break;

		default:
			break;
	}
	return ret;
}

ast * ast_new_modifier_list(ast * forward, modifier_type tail) {
	ast* ret = ast_malloc();
	ret->tag = t_ModifierList;
	list_add(ret->children, forward);
	list_add(ret->children, ast_new_modifier(tail));
	return ret;
}

ast * ast_new_function(ast * mod, YYBString name, ast * args, ast * block) {
	ast* ret = ast_malloc();
	ret->tag = t_Function;
	p__ast_strcpy(ret, name);
	list_add(ret->children, mod);
	list_add(ret->children, args);
	list_add(ret->children, block);
	return ret;
}

ast * ast_new_function_empty_args(ast * mod, YYBString name, ast * block) {
	ast* ret = ast_malloc();
	ret->tag = t_Function;
	p__ast_strcpy(ret, name);
	list_add(ret->children, mod);
	list_add(ret->children, ast_new_blank());
	list_add(ret->children, block);
	return ret;
}

ast * ast_new_field(ast* modifier, YYBString name, ast* accessor, ast* defaultValue) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, name);
	ret->tag = t_Field;
	list_add(ret->children, modifier);
	list_add(ret->children, accessor);
	list_add(ret->children, defaultValue);
	return ret;
}

ast * ast_new_field_accessor(ast * set, ast * get) {
	ast* ret = ast_malloc();
	ret->tag = t_FieldAccessor;
	list_add(ret->children, set);
	list_add(ret->children, get);
	return ret;
}

ast * ast_new_field_setter(YYBString name) {
	ast* ret = ast_malloc();
	ret->tag = t_FieldSetter;
	p__ast_strcpy(ret, name);
	return ret;
}

ast * ast_new_field_getter(YYBString name) {
	ast* ret = ast_malloc();
	ret->tag = t_FieldGetter;
	p__ast_strcpy(ret, name);
	return ret;
}

ast * ast_new_member(ast * member) {
	return member;
}

ast * ast_new_member_list(ast * forward, ast * member) {
	ast* ret = ast_malloc();
	ret->tag = t_MemberList;
	list_add(ret->children, forward);
	list_add(ret->children, member);
	return ret;
}

ast * ast_new_class(YYBString name, ast* super, ast * member_list) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, name);
	ret->tag = t_Class;
	list_add(ret->children, super);
	list_add(ret->children, member_list);
	return ret;
}

ast * ast_new_superclass(YYBString super) {
	ast* ret = ast_malloc();
	p__ast_strcpy(ret, super);
	ret->tag = t_SuperClass;
	return ret;
}

ast * ast_new_enum(YYBString name, ast * enum_items) {
	ast* ret = ast_malloc();
	ret->tag = t_Enum;
	p__ast_strcpy(ret, name);
	list_add(ret->children, enum_items);
	return ret;
}

ast * ast_new_enum_item(YYBString name, ast* value) {
	ast* ret = ast_malloc();
	ret->tag = t_EnumItem;
	p__ast_strcpy(ret, name);
	list_add(ret->children, value);
	return ret;
}

ast * ast_new_enum_item_list(ast* forward, ast* tail) {
	ast* ret = ast_malloc();
	ret->tag = t_EnumItem_List;
	list_add(ret->children, forward);
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_stmt(ast * val) {
	ast* ret = ast_malloc();
	ret->tag = t_Stmt;
	list_add(ret->children, val);
	return ret;
}

ast * ast_new_stmt_list(ast * forward, ast * tail) {
	ast* ret = ast_malloc();
	ret->tag = t_StmtList;
	list_add(ret->children, forward);
	list_add(ret->children, tail);
	return ret;
}

ast * ast_new_constructor_chain(constructor_chain_type cct, ast * argument_list) {
	ast* ret = ast_malloc();
	ret->tag = cct == cct_this ? t_ConstructorChainThis : t_ConstructorChainSuper;
	list_add(ret->children, argument_list);
	return ret;
}

ast * ast_new_constructor(ast * modifier_list, ast * parameter_list, ast * chain, ast * block) {
	ast* ret = ast_malloc();
	ret->tag = t_Constructor;
	list_add(ret->children, modifier_list);
	list_add(ret->children, parameter_list);
	list_add(ret->children, chain);
	list_add(ret->children, block);
	return ret;
}

ast * ast_new_dyn_field(ast * val, YYBString name, ast * dynFieldValue) {
	ast* ret = ast_malloc();
	ret->tag = t_Def_Dyn_Field;
	p__ast_strcpy(ret, name);
//	ret->u.string_value = name;
	list_add(ret->children, val);
	list_add(ret->children, dynFieldValue);
	return ret;
}

ast * ast_new_dyn_method(ast * val, YYBString name, ast * dynMethodValue) {
	ast* ret = ast_malloc();
	ret->tag = t_Def_Dyn_Method;
	p__ast_strcpy(ret, name);
//	ret->u.string_value = name;
	list_add(ret->children, val);
	list_add(ret->children, dynMethodValue);
	return ret;
}

//
//expand
//
list * ast_expand_generic(ast* node, ast_filter f, ast_tree t, ast_accept a) {
	int b = f(node) == BTRUE;
	assert(b);
	ast* root = node;
	list* li = list_new();
	int len = list_size(root->children);
	for (int i = 0; i < len; i++) {
		ast* child = ast_get_childAt(root, i);
		if (t(child) == BTRUE) {
			list* tree = ast_expand_generic(child, f, t, a);
			list_add_all(li, tree);
			list_delete(tree);
		} else if (a(child) == BTRUE) {
			list_add(li, child);
		}
	}
	return li;
}

list * ast_expand_members(ast * classz) {
	return ast_expand_generic(
		classz,
		ast_filter_class,
		ast_tree_member_list,
		ast_accept_member
	);
}

list * ast_expand_modifiers(ast * member) {
	return ast_expand_generic(
		member,
		ast_filter_member,
		ast_tree_modifier_list,
		ast_accept_modifier
	);
}

list * ast_expand_parameters(ast * funcDefine) {
	return ast_expand_generic(
		funcDefine,
		ast_filter_func_define,
		ast_tree_paramter_list,
		ast_accept_parameter
	);
}

list * ast_expand_arguments(ast * argument_list) {
	return ast_expand_generic(
		argument_list,
		ast_filter_argument,
		ast_tree_argument_list,
		ast_accept_argument
	);
}

list * ast_expand_namespaces(ast * namespace_list) {
	return ast_expand_generic(
		namespace_list,
		ast_filter_namespace,
		ast_tree_namespace_list,
		ast_accept_namespace
	);
}

list * ast_expand_stmts(ast * block) {
	return ast_expand_generic(
		block,
		ast_filter_block,
		ast_tree_stmt_list,
		ast_accept_stmt
	);
}

list * ast_expand_enumitems(ast * enum_item_list) {
	return ast_expand_generic(
		enum_item_list,
		ast_filter_enum,
		ast_tree_enum_item_list,
		ast_accept_enum_item
	);
}

//
//filter
//
BBOOL ast_filter_class(ast * node) {
	return node->tag == t_Class ||
		   node->tag == t_MemberList;
}

BBOOL ast_filter_member(ast * node) {
	return node->tag == t_Field ||
		   node->tag == t_Function ||
		   node->tag == t_ModifierList;
}

BBOOL ast_filter_func_define(ast * node) {
	return node->tag == t_Lambda ||
		   node->tag == t_Parameter ||
		   node->tag == t_Function ||
		   node->tag == t_ParameterList;
}

BBOOL ast_filter_argument(ast * node) {
	return node->tag == t_Argument ||
		   node->tag == t_ArgumentList;
}

BBOOL ast_filter_namespace(ast * node) {
	return node->tag == t_Include ||
		   node->tag == t_Alias ||
		   node->tag == t_NamespaceList;
}

BBOOL ast_filter_block(ast * node) {
	return node->tag == t_CodeBlock ||
		node->tag == t_Stmt ||
		node->tag == t_StmtList;
}

BBOOL ast_filter_enum(ast * node) {
	return node->tag == t_Enum ||
		   node->tag == t_EnumItem_List;
}

BBOOL ast_filter_true(ast * node) {
	return BTRUE;
}

BBOOL ast_filter_false(ast * node) {
	return BFALSE;
}

//
//tree
//
BBOOL ast_tree_member_list(ast * node) {
	return node->tag == t_MemberList;
}

BBOOL ast_tree_modifier_list(ast * node) {
	return node->tag == t_ModifierList;
}

BBOOL ast_tree_paramter_list(ast * node) {
	return node->tag == t_Function ||
		   node->tag == t_ParameterList;
}

BBOOL ast_tree_argument_list(ast * node) {
	return node->tag == t_Argument ||
		   node->tag == t_ArgumentList;
}

BBOOL ast_tree_namespace_list(ast * node) {
	return node->tag == t_Include ||
		node->tag == t_NamespaceList;
}

BBOOL ast_tree_stmt_list(ast * node) {
	return node->tag == t_Stmt ||
		node->tag == t_StmtList;
}

BBOOL ast_tree_enum_item_list(ast * node) {
	return node->tag == t_Enum ||
		   node->tag == t_EnumItem_List;
}

BBOOL ast_tree_true(ast * node) {
	return BTRUE;
}

BBOOL ast_tree_false(ast * node) {
	return BFALSE;
}

//
//accept
//
BBOOL ast_accept_member(ast * node) {
	return node->tag == t_Constructor ||
		   node->tag == t_Field ||
		   node->tag == t_Function;
}

BBOOL ast_accept_modifier(ast * node) {
	return	node->tag == t_Public ||
			node->tag == t_Private ||
			node->tag == t_Protected ||
			node->tag == t_Final ||
			node->tag == t_Native ||
			node->tag == t_Static;
}

BBOOL ast_accept_parameter(ast * node) {
	return node->tag == t_Parameter;
}

BBOOL ast_accept_argument(ast * node) {
	return BTRUE;
}

BBOOL ast_accept_namespace(ast * node) {
	return node->tag == t_Namespace;
}

BBOOL ast_accept_enum_item(ast * node) {
	return node->tag == t_EnumItem;
}

BBOOL ast_accept_stmt(ast * node) {
	return node->tag != t_Stmt;
}

//
//extract
//
YYBString ast_field_extract_name(ast * field) {
	assert(field->tag == t_Field);
	return field->u.string_value;
}

ast * ast_field_extract_accessor(ast * field) {
	assert(field->tag == t_Field);
	return list_getAt(field->children, 1);
}

ast * ast_field_extract_default_value(ast * field) {
	assert(field->tag == t_Field);
	return list_getAt(field->children, 2);
}

ast * ast_accessor_extract_setter(ast * accessor) {
	assert(accessor->tag == t_FieldAccessor);
	return list_getAt(accessor->children, 0);
}

ast * ast_accessor_extract_getter(ast * accessor) {
	assert(accessor->tag == t_FieldAccessor);
	return list_getAt(accessor->children, 1);
}

YYBString ast_setter_extract_name(ast * setter) {
	assert(setter->tag == t_FieldSetter);
	return setter->u.string_value;
}

YYBString ast_getter_extract_name(ast * getter) {
	assert(getter->tag == t_FieldGetter);
	return getter->u.string_value;
}

ast * ast_function_extract_modifier_list(ast * func_define) {
	assert(func_define->tag == t_Function);
	return list_getAt(func_define->children, 0);
}

YYBString ast_function_extract_name(ast* func_define) {
	assert(func_define->tag == t_Function);
	return func_define->u.string_value;
}

ast * ast_function_extract_parameter_list(ast * func_define) {
	assert(func_define->tag == t_Function);
	return list_getAt(func_define->children, 1);
}

ast * ast_function_extract_block(ast * func_define) {
	assert(func_define->tag == t_Function);
	return list_getAt(func_define->children, 2);
}

YYBString ast_vardefine_extract_name(ast * var_define) {
	assert(var_define->tag == t_VariableDecl);
	return var_define->u.string_value;
}

ast * ast_vardefine_extract_fact(ast * var_define) {
	assert(var_define->tag == t_VariableDecl);
	return list_getAt(var_define->children, 0);
}

YYBString ast_invoke_by_self_extract_name(ast * invokeBySelf) {
	assert(invokeBySelf->tag == t_InvokeBySelf);
	return invokeBySelf->u.string_value;
}

ast * ast_invoke_by_self_extract_argument_list(ast * invokeBySelf) {
	assert(invokeBySelf->tag == t_InvokeBySelf);
	return list_getAt(invokeBySelf->children, 0);
}

YYBString ast_invoke_by_message_extract_name(ast * invokeByMessage) {
	assert(invokeByMessage->tag == t_InvokeByMessage);
	return invokeByMessage->u.string_value;
}

ast * ast_invoke_by_message_extract_argument_list(ast * invokeByMessage) {
	assert(invokeByMessage->tag == t_InvokeByMessage);
	return list_getAt(invokeByMessage->children, 1);
}

ast * ast_invoke_by_message_extract_invoker(ast * invokeByMessage) {
	assert(invokeByMessage->tag == t_InvokeByMessage);
	return list_getAt(invokeByMessage->children, 0);
}

ast * ast_inc_dec_extract_argument(ast * inc_dec) {
	assert(inc_dec->tag == t_PreIncrement ||
		   inc_dec->tag == t_PreDecrement ||
		   inc_dec->tag == t_PostIncrement ||
		   inc_dec->tag == t_PostDecrement
	);
	return list_getAt(inc_dec->children, 0);
}

ast * ast_if_extract_cond(ast * if_stmt) {
	assert(if_stmt->tag ==  t_If);
	return list_getAt(if_stmt->children, 0);
}

ast * ast_if_extract_body(ast * if_stmt) {
	assert(if_stmt->tag == t_If);
	return list_getAt(if_stmt->children, 1);
}

ast * ast_if_else_extract_if(ast * if_else_stmt) {
	assert(if_else_stmt->tag == t_IfElse);
	return list_getAt(if_else_stmt->children, 0);
}

ast * ast_if_else_extract_else(ast * if_else_stmt) {
	assert(if_else_stmt->tag == t_IfElse);
	return list_getAt(if_else_stmt->children, 1);
}

ast * ast_else_extract_body(ast * else_stmt) {
	assert(else_stmt->tag == t_Else);
	return list_getAt(else_stmt->children, 0);
}

ast * ast_if_elseif_list_extract_if(ast * if_elseif_stmt) {
	assert(if_elseif_stmt->tag == t_IfElseIfList);
	return list_getAt(if_elseif_stmt->children, 0);
}

ast * ast_if_elseif_list_extract_elseif_list(ast * if_elseif_stmt_list) {
	assert(if_elseif_stmt_list->tag == t_IfElseIfList);
	return list_getAt(if_elseif_stmt_list->children, 1);
}

ast * ast_elseif_extract_cond(ast * elseif_stmt) {
	assert(elseif_stmt->tag == t_ElseIf);
	return list_getAt(elseif_stmt->children, 0);
}

ast * ast_elseif_extract_body(ast * elseif_stmt) {
	assert(elseif_stmt->tag == t_ElseIf);
	return list_getAt(elseif_stmt->children, 1);
}

ast * ast_if_elseif_list_else_extract_if_elseif_list(ast * if_elseif_list_else) {
	assert(if_elseif_list_else->tag == t_IfElseIfListElse);
	return list_getAt(if_elseif_list_else->children, 0);
}

ast * ast_if_elseif_list_else_extract_elseif_list(ast * if_elseif_list_else) {
	assert(if_elseif_list_else->tag == t_IfElseIfListElse);
	return list_getAt(if_elseif_list_else->children, 1);
}

ast * ast_if_elseif_list_else_extract_else(ast * if_elseif_list_else) {
	assert(if_elseif_list_else->tag == t_IfElseIfListElse);
	return list_getAt(if_elseif_list_else->children, 2);
}

ast * ast_while_extract_cond(ast * while_stmt) {
	assert(while_stmt->tag == t_While);
	return list_getAt(while_stmt->children, 0);
}

ast * ast_while_extract_body(ast * while_stmt) {
	assert(while_stmt->tag == t_While);
	return list_getAt(while_stmt->children, 1);
}

ast * ast_for_extract_init(ast * for_stmt) {
	assert(for_stmt->tag == t_For);
	return list_getAt(for_stmt->children, 0);
}

ast * ast_for_extract_cond(ast * for_stmt) {
	assert(for_stmt->tag == t_For);
	return list_getAt(for_stmt->children, 1);
}

ast * ast_for_extract_update(ast * for_stmt) {
	assert(for_stmt->tag == t_For);
	return list_getAt(for_stmt->children, 2);
}

ast * ast_for_extract_body(ast * for_stmt) {
	assert(for_stmt->tag == t_For);
	return list_getAt(for_stmt->children, 3);
}

ast * ast_try_catch_extract_try(ast * try_catch_stmt) {
	assert(try_catch_stmt->tag == t_TryCatch);
	return list_getAt(try_catch_stmt->children, 0);
}

ast * ast_try_catch_extract_catch(ast * try_catch_stmt) {
	assert(try_catch_stmt->tag == t_TryCatch);
	return list_getAt(try_catch_stmt->children, 1);
}

ast * ast_try_extract_body(ast * try_stmt) {
	assert(try_stmt->tag == t_Try);
	return list_getAt(try_stmt->children, 0);
}

YYBString ast_catch_extract_capturename(ast * catch_stmt) {
	assert(catch_stmt->tag == t_Catch);
	return catch_stmt->u.string_value;
}

ast * ast_catch_extract_body(ast * catch_stmt) {
	assert(catch_stmt->tag == t_Catch);
	return list_getAt(catch_stmt->children, 0);
}

ast * ast_try_catch_finally_extract_try(ast * try_catch_finally) {
	assert(try_catch_finally->tag == t_TryCatchFinally);
	return list_getAt(try_catch_finally->children, 0);
}

ast * ast_try_catch_finally_extract_catch_finally(ast * try_catch_finally) {
	assert(try_catch_finally->tag == t_TryCatchFinally);
	return list_getAt(try_catch_finally->children, 1);
}

ast * ast_catch_finally_extract_catch(ast * catch_finally) {
	assert(catch_finally->tag == t_CatchFinally);
	return list_getAt(catch_finally->children, 0);
}

ast * ast_catch_finally_extract_finally(ast * catch_finally) {
	assert(catch_finally->tag == t_CatchFinally);
	return list_getAt(catch_finally->children, 1);
}

ast * ast_finally_extract_body(ast * finally_stmt) {
	assert(finally_stmt->tag == t_Finally);
	return list_getAt(finally_stmt->children, 0);
}

ast * ast_try_finally_extract_try(ast * try_finally) {
	assert(try_finally->tag == t_TryFinally);
	return list_getAt(try_finally->children, 0);
}

ast * ast_try_finally_extract_finally(ast * try_finally) {
	assert(try_finally->tag == t_TryFinally);
	return list_getAt(try_finally->children, 1);
}

ast * ast_throw_extract_fact(ast * throw_stmt) {
	assert(throw_stmt->tag == t_Throw);
	return list_getAt(throw_stmt->children, 0);
}

ast * ast_return_extract_fact(ast * return_stmt) {
	assert(return_stmt->tag == t_Return);
	return list_getAt(return_stmt->children, 0);
}

YYBString ast_class_extract_name(ast * classDecl) {
	assert(classDecl->tag == t_Class);
	return classDecl->u.string_value;
}

ast * ast_class_extract_superclass(ast * classDecl) {
	assert(classDecl->tag == t_Class);
	return list_getAt(classDecl->children, 0);
}

YYBString ast_superclass_extract_name(ast * superclass) {
	assert(superclass->tag == t_SuperClass);
	return superclass->u.string_value;
}

ast * ast_lambda_extract_parameter_list(ast * lambdaDecl) {
	assert(lambdaDecl->tag == t_Lambda);
	return list_getAt(lambdaDecl->children, 0);
}

ast * ast_lambda_extract_block(ast * lambdaDecl) {
	assert(lambdaDecl->tag == t_Lambda);
	return list_getAt(lambdaDecl->children, 1);
}

ast * ast_array_extract_argument_list(ast * array_init) {
	assert(array_init->tag == t_Array);
	return list_getAt(array_init->children, 0);
}

ast * ast_field_access_extract_fact(ast * field_access) {
	assert(field_access->tag == t_FieldAccess);
	return list_getAt(field_access->children, 0);
}

YYBString ast_field_access_extract_name(ast * field_access) {
	assert(field_access->tag == t_FieldAccess);
	return field_access->u.string_value;
}

YYBString ast_enum_extract_name(ast * enum_define) {
	assert(enum_define->tag == t_Enum);
	return enum_define->u.string_value;
}

ast * ast_enum_extract_enum_item_list(ast * enum_item_list) {
	assert(enum_item_list->tag == t_Enum);
	return list_getAt(enum_item_list->children, 0);
}

YYBString ast_enum_item_extract_name(ast * enum_item) {
	assert(enum_item->tag == t_EnumItem);
	return enum_item->u.string_value;
}

ast * ast_enum_item_extract_value(ast * enum_item) {
	assert(enum_item->tag == t_EnumItem);
	return list_getAt(enum_item->children, 0);
}

ast * ast_constructor_extract_modifier(ast * constructor) {
	assert(constructor->tag == t_Constructor);
	return list_getAt(constructor->children, 0);
}

ast * ast_constructor_extract_parameter_list(ast * constructor) {
	assert(constructor->tag == t_Constructor);
	return list_getAt(constructor->children, 1);
}

ast * ast_constructor_extract_constructor_chain(ast * constructor) {
	assert(constructor->tag == t_Constructor);
	return list_getAt(constructor->children, 2);
}

ast * ast_constructor_extract_block(ast * constructor) {
	assert(constructor->tag == t_Constructor);
	return list_getAt(constructor->children, 3);
}

constructor_chain_type ast_constructor_chain_extract_type(ast * constructor_chain) {
	assert(constructor_chain->tag == t_ConstructorChainThis ||
		   constructor_chain->tag == t_ConstructorChainSuper);
	if (constructor_chain->tag == t_ConstructorChainThis) {
		return cct_this;
	} else return cct_super;
}

ast * ast_constructor_chain_extract_argument_list(ast * constructor_chain) {
	assert(constructor_chain->tag == t_ConstructorChainThis ||
		   constructor_chain->tag == t_ConstructorChainSuper);
	return list_getAt(constructor_chain->children, 0);
}

void ast_free(ast * val) {
	list_delete(val->children);
}

void ast_delete(ast* val) {
	int size = list_size(val->children);
	if (val->allocStr == BTRUE) {
		YYBString a = val->u.string_value;
		val->u.string_value = NULL;
		free(a);
	}
	p__ast_delete(val, size);
}

void ast_single_delete(ast * val) {
	list_delete(val->children);
	free(val);
}

void ast_dump(ast * val) {
	p__ast_dump(val, 0);
	//fflush(stdout);
}

void ast_dump_all(list * val) {
	for (int i = 0; i < *val->size; i++) {
		ast_dump(list_getAt(val, i));
	}
}

BBOOL ast_is_blank(ast * val) {
	return val == NULL ||
		   val->tag == t_Blank;
}

YYBString ast_new_newident() {
	return string_buffer_clone("new");
}

string_buffer* ast_sum_string(list * val) {
	return ast_join_string(val, NULL);
}

string_buffer * ast_join_string(list * val, YYBChar c) {
	string_buffer* sb = string_buffer_new();
	for (int i = 0; i < list_size(val); i++) {
		string_buffer_append_str(sb, ((ast*)list_getAt(val, i))->u.string_value);
		if (c != NULL &&
			i < list_size(val) - 1) {
			string_buffer_append(sb, c);
		}
	}
	return sb;
}

ast * ast_compile_entry(ast * val) {
	//ast_push(get_compiler()->root, val);
	list_add(get_compiler()->root->children, val);
	return val;
}

YYBString ast_ident_wrap(YYBString str) {
	return str;
}


//private method
void p__ast_strcpy(ast* val, YYBString str) {
	val->u.string_value = str;
	val->allocStr = BTRUE;
	//val->u.string_value = string_buffer_clone(str);
}

void p__ast_dump(ast* val, int depth) {
	p__ast_indent(depth);
	p__ast_tag(val);
	int size = *val->children->size;
	for (int i = 0; i <size; i++) {
		ast* child = ast_get_childAt(val, i);
		p__ast_dump(child, depth + 1);
	}
}

void p__ast_tag(ast* val) {
	switch (val->tag) {
		case t_Root:
			printf("root");
			break;

		case t_Add:
			printf("add");
			break;
		case t_Sub:
			printf("sub");
			break;
		case t_Mul:
			printf("mul");
			break;
		case t_Div:
			printf("div");
			break;
		case t_Mod:
			printf("mod");
			break;

		case t_Add_Assign:
			printf("add assign");
			break;
		case t_Sub_Assign:
			printf("sub assign");
			break;
		case t_Mul_Assign:
			printf("mul assign");
			break;
		case t_Div_Assign:
			printf("div assign");
			break;
		case t_Mod_Assign:
			printf("mod assign");
			break;

		case t_Not:
			printf("not");
			break;
		case t_Minus:
			printf("minus");
			break;

		case t_Equal:
			printf("equal");
			break;

		case t_Biggest:
			printf("biggest");
			break;
		case t_EBiggest:
			printf("ebiggest");
			break;
		case t_Smallest:
			printf("smallest");
			break;
		case t_ESmallest:
			printf("esmallest");
			break;

		case t_Assign:
			printf("assign");
			break;
		case t_Class:
			printf("class");
			break;
		case t_MemberList:
			printf("member list");
			break;
		case t_Field:
			printf("field");
			break;
		case t_Function:
			printf("function");
			break;
		case t_Break:
			printf("break");
			break;
		case t_Return:
			printf("return");
			break;
		case t_Continue:
			printf("continue");
			break;
		case t_Try:
			printf("try");
			break;
		case t_TryCatch:
			printf("try catch");
			break;
		case t_TryFinally:
			printf("try finally");
			break;
		case t_TryCatchFinally:
			printf("try catch finally");
			break;
		case t_CatchFinally:
			printf("catch finally");
			break;
		case t_Throw:
			printf("throw");
			break;
		case t_Catch:
			printf("catch");
			break;
		case t_Finally:
			printf("finally");
			break;
		case t_Int:
			printf("int");
			break;
		case t_Float:
			printf("float");
			break;
		case t_True:
			printf("true");
			break;
		case t_False:
			printf("false");
			break;
		case t_Character:
			printf("character ");
			printf("%c", val->u.char_value);
			break;
		case t_String:
			printf("string ");
			printf("%s", val->u.string_value);
			break;
		case t_Variable:
			printf("variable");
			break;
		case t_VariableDecl:
			printf("variable decl");
			break;
		case t_FieldAccess:
			printf("field access");
			break;


		case t_Namespace:
			printf("namespace ");
			printf("%s", val->u.string_value);
			break;
		case t_NamespaceList:
			printf("namespace list");
			break;

		case t_If:
			printf("if");
			break;
		case t_Else:
			printf("else");
			break;

		case t_IfElse:
			printf("if else");
			break;

		case t_ElseIf:
			printf("else if");
			break;

		case t_ElseIfList:
			printf("else if list");
			break;

		case t_IfElseIfList:
			printf("if else if list");
			break;

		case t_IfElseIfListElse:
			printf("if else if list else");
			break;

		case t_CodeBlock:
			printf("code block");
			break;

		case t_Include:
			printf("include");
			break;

		case t_InvokeBySelf:
			printf("invoke byself");
			break;
		case t_InvokeByMessage:
			printf("invoke bymessage");
			break;

		case t_PreIncrement:
			printf("pre inc");
			break;

		case t_PreDecrement:
			printf("pre dec");
			break;

		case t_PostIncrement:
			printf("post inc");
			break;

		case t_PostDecrement:
			printf("post dec");
			break;

		case t_For:
			printf("for");
			break;
		case t_While:
			printf("while");
			break;
		case t_Blank:
			printf("blank");
			break;

		case t_Stmt:
			printf("stmt");
			break;
		case t_StmtList:
			printf("stmt list");
			break;

		case t_Parameter:
			printf("parameter ");
			printf("%s", val->u.string_value);
			break;
		case t_ParameterList:
			printf("parameter list");
			break;
		case t_Argument:
			printf("argument");
			break;
		case t_ArgumentList:
			printf("argument list");
			break;

		case t_ModifierList:
			printf("modifier list");
			break;
		case t_Public:
			printf("public");
			break;
		case t_Private:
			printf("private");
			break;
		case t_Protected:
			printf("protected");
			break;
		case t_Static:
			printf("static");
			break;
		case t_Final:
			printf("final");
			break;


		default:
			
			printf("not supported");
			break;
	}
	printf(".\n");
}

void p__ast_indent(int depth) {
	for (int i = 0; i < depth; i++) {
		printf("    ");
	}
}

compiler* p__ast_get_compiler(void) {
	return get_compiler();
}

void p__ast_delete(ast* val, int size) {
	if (val == NULL) {
		return;
	}
	for (int i = size - 1; i >= 0; i--) {
		ast* a = list_remove(val->children, i);
		ast_delete(a);
	}
	ast_single_delete(val);
}
