#include "BisonWrapper.h"
#include "../Debug.h"
#include "bison/yyinterface.h"
#include "../ast/ASTAddAssignOperator.h"
#include "../ast/ASTAddOperator.h"
#include "../ast/ASTAndAndOperator.h"
#include "../ast/ASTAndOperator.h"
#include "../ast/ASTArrayInitializer.h"
#include "../ast/ASTAssignOperator.h"
#include "../ast/ASTBiggestOperator.h"
#include "../ast/ASTBoolean.h"
#include "../ast/ASTBranch.h"
#include "../ast/ASTBreakStatement.h"
#include "../ast/ASTCatchStatement.h"
#include "../ast/ASTCharacter.h"
#include "../ast/ASTClassDeclaration.h"
#include "../ast/ASTConstructorChain.h"
#include "../ast/ASTConstructorDeclaration.h"
#include "../ast/ASTContinueStatement.h"
#include "../ast/ASTDecrement.h"
#include "../ast/ASTDivAssignOperator.h"
#include "../ast/ASTDivOperator.h"
#include "../ast/ASTEBiggestOperator.h"
#include "../ast/ASTESmallestOperator.h"
#include "../ast/ASTElseIfStatement.h"
#include "../ast/ASTElseStatement.h"
#include "../ast/ASTEnumDeclaration.h"
#include "../ast/ASTEnumItemDeclaration.h"
#include "../ast/ASTEqualOperator.h"
#include "../ast/ASTErrorNode.h"
#include "../ast/ASTFieldDeclaration.h"
#include "../ast/ASTForStatement.h"
#include "../ast/ASTIfStatement.h"
#include "../ast/ASTIncrement.h"
#include "../ast/ASTLambdaDeclaration.h"
#include "../ast/ASTMethodDeclaration.h"
#include "../ast/ASTMethodInvocationByMessage.h"
#include "../ast/ASTMethodInvocationBySelf.h"
#include "../ast/ASTModAssignOperator.h"
#include "../ast/ASTModOperator.h"
#include "../ast/ASTMulAssignOperator.h"
#include "../ast/ASTMulOperator.h"
#include "../ast/ASTNegativeOperator.h"
#include "../ast/ASTNotEqualsOperator.h"
#include "../ast/ASTNotOperator.h"
#include "../ast/ASTNullFactor.h"
#include "../ast/ASTNumeric.h"
#include "../ast/ASTOrOperator.h"
#include "../ast/ASTOrOrOperator.h"
#include "../ast/ASTReturnStatement.h"
#include "../ast/ASTSmallestOperator.h"
#include "../ast/ASTString.h"
#include "../ast/ASTSubAssignOperator.h"
#include "../ast/ASTSubOperator.h"
#include "../ast/ASTSuperFactor.h"
#include "../ast/ASTThisFactor.h"
#include "../ast/ASTThrow.h"
#include "../ast/ASTTryStatement.h"
#include "../ast/ASTVariableDeclaration.h"
#include "../ast/ASTWhileStatement.h"
#include "../env/gc/GCLock.h"

//public method---
BisonWrapper::BisonWrapper(bool entryPoint) {
	this->entryPoint = entryPoint;
}

BisonWrapper::~BisonWrapper() {
}

ASTNodeSPtr BisonWrapper::compile(const std::string filePath) {
	return compileImplC(
		[filePath](compiler* com) {
			com->im = im_file;
			com->file_name = filePath.c_str();
		},
		[filePath]() {
			return compile_yyparse(filePath.c_str());
		}
	);
}

ASTNodeSPtr BisonWrapper::compilestr(const std::string filePath, char* source) {
	return compileImplC(
		[filePath, source](compiler* com) {
			com->im = im_str;
			com->file_name = filePath.c_str();
		},
		[source]() {
			return compile_yyparsestr(source);
		}
	);
}
//---public method


//private method---
ASTNodeSPtr BisonWrapper::compileImplC(std::function<void(compiler*)> preFunc, std::function<int()> compileFunc) {
	GCLock gcLock = GCLock();
	push_compiler();
	preFunc(get_compiler());
	//get_compiler()->file_name = filePath.c_str();
	if (compileFunc() == BFALSE) {
	//	ast_dump(get_compiler()->root);
		pop_compiler(BTRUE);
		return nullptr;
	}
	auto root = ASTBranch::make_shared();
	compileImpl(get_compiler()->root, root);
	pop_compiler(BFALSE);
	return root;
}

void BisonWrapper::compileImpl(ast * tree, std::shared_ptr<ASTBranch> branch) {
	int len = *tree->children->size;
	for (int i = 0; i < len; i++) {
		ast* child = ast_get_childAt(tree, i);
		compileImplCase(child, branch);
	}
}

void BisonWrapper::compileImplCase(ast * tree, std::shared_ptr<ASTBranch> branch) {
	switch (tree->tag) {
		case t_Alias:
			branch->add(toAlias(tree));
			break;
		case t_Include:
			branch->add(toInclude(tree));
			break;
		case t_Class:
			branch->add(toClass(tree, branch));
			break;
		case t_Enum:
			branch->add(toEnum(tree));
			break;
		case t_Stmt:
		case t_StmtList:
			//エントリポイント以外では
			//ルートにステートメントが存在出来ない。
			if (entryPoint) {
				readStmt(branch, tree);
			} else branch->add(ASTErrorNode::make_shared("エントリポイント以外の場所でルートにステートメントは配置出来ません。"));
			break;
		case t_Function:
			//エントリポイント以外では
			//ルートに関数定義が存在出来ない。
			if (this->entryPoint) {
				return branch->add(toMethod(tree));
			} else branch->add(ASTErrorNode::make_shared("エントリポイント以外の場所でルートに関数は配置出来ません。"));
			break;
		default:
			if (entryPoint) {
				branch->add(toStatement(tree));
			} else branch->add(ASTErrorNode::make_shared("エントリポイント以外の場所でルートにステートメントは配置出来ません。"));
			break;
	}
}

std::shared_ptr<ASTAliasStatement> BisonWrapper::toAlias(ast * tree) {
	auto ret = ASTAliasStatement::make_shared();
	auto oldName = toNamespaceStr(tree);
	auto newName = tree->u.string_value;
	ret->setOldName(ASTName::make_shared(oldName));
	ret->setNewName(ASTName::make_shared(newName));
	return ret;
}

std::shared_ptr<ASTIncludeStatement> BisonWrapper::toInclude(ast * tree) {
	//インクルードパスを設定
	auto str = toNamespaceStr(tree);
	auto ret = ASTIncludeStatement::make_shared();
	ret->setPath(ASTName::make_shared(str));
	return ret;
}

std::string BisonWrapper::toNamespaceStr(ast * tree) {
	list* li = ast_expand_namespaces(tree);
	string_buffer* sb = ast_join_string(li, '.');
	std::string str = std::string(sb->pointee);
	list_delete(li);
	string_buffer_delete(sb);
	return str;
}

std::shared_ptr<ASTClassDeclaration> BisonWrapper::toClass(ast * tree, std::shared_ptr<ASTBranch> branch) {
	auto classDecl = ASTClassDeclaration::make_shared();
	//クラス名を設定
	auto className = ast_class_extract_name(tree);
	classDecl->setName(ASTName::make_shared(className));
	//親クラス名を設定
	auto superclass = ast_class_extract_superclass(tree);
	if (!ast_is_blank(superclass)) {
		auto superclassName = ast_superclass_extract_name(superclass);
		classDecl->setSuperClass(ASTName::make_shared(superclassName));
	}
	//メンバを設定
	ast* members_blank = ast_get_childAt(tree, 1);
	if (ast_is_blank(members_blank)) {
		return classDecl;
	}
	list* members = ast_expand_members(tree);
	for (int i = 0; i < list_size(members); i++) {
		ast* member = (ast*)list_getAt(members, i);
		if (member->tag == t_Field) {
			classDecl->addField(toField(member));
		} else if (member->tag == t_Function) {
			classDecl->addMethod(toMethod(member));
		} else if (member->tag == t_Constructor) {
			classDecl->addMethod(toConstructor(member));
		}
	}
	list_delete(members);
	return classDecl;
}

std::shared_ptr<ASTEnumDeclaration> BisonWrapper::toEnum(ast * tree) {
	auto ret = ASTEnumDeclaration::make_shared();
	auto enum_name = ast_enum_extract_name(tree);
	auto enum_items = ast_enum_extract_enum_item_list(tree);
	ret->setName(ASTName::make_shared(enum_name));
	if (!ast_is_blank(enum_items)) {
		//アイテムが一つしかない
		if (enum_items->tag == t_EnumItem) {
			auto name = ast_enum_item_extract_name(enum_items);
			auto enumItemDecl = ASTEnumItemDeclaration::make_shared();
			enumItemDecl->setName(ASTName::make_shared(enum_items->u.string_value));
			enumItemDecl->setValue(toFactor(ast_enum_item_extract_value(enum_items)));
			ret->addEnumItem(enumItemDecl);
		} else {
			list* li = ast_expand_enumitems(enum_items);
			for (int i = 0; i < list_size(li); i++) {
				ast* elem = (ast*)list_getAt(li, i);
				auto name = ast_enum_item_extract_name(elem);
			//	auto copy = (char*)malloc(sizeof(char) * strlen(name) + 1);
			//	strcpy(copy, name);
			//	std::string copyStr = copy;
				auto enumItemDecl = ASTEnumItemDeclaration::make_shared();
				enumItemDecl->setName(ASTName::make_shared(name));
				enumItemDecl->setValue(toFactor(ast_enum_item_extract_value(elem)));
				ret->addEnumItem(enumItemDecl);
			}
			list_delete(li);
		}
	}
	return ret;
}

std::shared_ptr<ASTMethodDeclaration> BisonWrapper::toMethod(ast * method) {
	auto methodDecl = ASTMethodDeclaration::make_shared();
	//名前を設定
	YYBString name = ast_function_extract_name(method);
	methodDecl->setName(ASTName::make_shared(name));
	readMethod(methodDecl,
		ast_function_extract_modifier_list(method),
		ast_function_extract_parameter_list(method),
		ast_function_extract_block(method)
	);
	return methodDecl;
}

std::shared_ptr<ASTMethodDeclaration> BisonWrapper::toConstructor(ast * method) {
	auto ret = ASTConstructorDeclaration::make_shared();
	readMethod(ret,
		ast_constructor_extract_modifier(method),
		ast_constructor_extract_parameter_list(method),
		ast_constructor_extract_block(method)
	);
	ret->setChain(toChain(ast_constructor_extract_constructor_chain(method)));
	ret->setName(ASTName::make_shared("new"));
	return ret;
}

std::shared_ptr<ASTConstructorChain> BisonWrapper::toChain(ast * chain) {
	if (ast_is_blank(chain)) {
		return nullptr;
	}
	auto ret = ASTConstructorChain::make_shared();
	//連鎖方法の設定
	auto type = ast_constructor_chain_extract_type(chain);
	if (type == cct_this) {
		ret->setChainType(ConstructorChainType::cct_This);
	} else ret->setChainType(ConstructorChainType::cct_Super);
	//実引数の設定
	auto argument_list = ast_constructor_chain_extract_argument_list(chain);
	if (!ast_is_blank(argument_list)) {
		for (std::shared_ptr<ASTFactor> fact : asArgumentList(argument_list)) {
			ret->addArgument(fact);
		}
	}
	return ret;
}

std::shared_ptr<ASTDynFieldDeclaration> BisonWrapper::toDynFieldDecl(ast * dyn_field) {
	//FIXME:対応するextractメソッドがない
	auto ret = ASTDynFieldDeclaration::make_shared();
	ret->setName(ASTName::make_shared(dyn_field->u.string_value));
	ret->setInvoker(toFactor(ast_get_left(dyn_field)));
	ret->setValue(toFactor(ast_get_right(dyn_field)));
	return ret;
}

std::shared_ptr<ASTDynMethodDeclaration> BisonWrapper::toDynMethodDecl(ast * dyn_method) {
	//FIXME:対応するextractメソッドがない
	auto ret = ASTDynMethodDeclaration::make_shared();
	ret->setName(ASTName::make_shared(dyn_method->u.string_value));
	ret->setInvoker(toFactor(ast_get_left(dyn_method)));
	auto lmbd = toLambdaVal(ast_get_right(dyn_method));
	lmbd->setDynamicMethod(true);
	ret->setLambda(lmbd);
	return ret;
}

void BisonWrapper::readMethod(std::shared_ptr<ASTMethodDeclaration> methodDecl, ast * modifier_list, ast * parameter_list, ast * block) {
	Debug::break_if(modifier_list == NULL);
	//アクセス修飾子を設定
	list* mods;
	if (modifier_list->tag == t_ModifierList) {
		mods = ast_expand_modifiers(modifier_list);
	} else {
		mods = list_new();
		list_add(mods, modifier_list);
	}
	Modifier mod = toModifier(mods);
	methodDecl->setModifier(ASTModifier::make_shared(mod));
	//引数列を設定
	if (!ast_is_blank(parameter_list)) {
		if (parameter_list->tag == t_Parameter) {
			methodDecl->addParameter(ASTParameter::make_shared(ASTName::make_shared(parameter_list->u.string_value)));
		} else {
			list* args = ast_expand_parameters(parameter_list);
			for (int i = 0; i < list_size(args); i++) {
				ast* nameAST = (ast*)list_getAt(args, i);
				methodDecl->addParameter(ASTParameter::make_shared(ASTName::make_shared(nameAST->u.string_value)));
			}
			list_delete(args);
		}
	}
	//本文を設定
	ast* bodyAST = block;
	if (!mod.isNative()) {
		methodDecl->setBody(toBlock(bodyAST));
	} else {
		methodDecl->setBody(ASTBody::make_shared());
	}
	methodDecl->setSimple(ast_is_blank(bodyAST));
	list_delete(mods);
}

std::shared_ptr<ASTFieldDeclaration> BisonWrapper::toField(ast * field) {
	auto fieldDecl = ASTFieldDeclaration::make_shared();
	//名前を設定
	YYBString name = ast_field_extract_name(field);
	fieldDecl->setName(ASTName::make_shared(name));
	//アクセス修飾子を設定
	list* mods = ast_expand_modifiers(field);
	Modifier mod = toModifier(mods);
	fieldDecl->setModifier(ASTModifier::make_shared(mod));
	//アクセサが存在する
	ast* accessorNode = ast_field_extract_accessor(field);
	if (!ast_is_blank(accessorNode)) {
		//セッターが存在する
		ast* setterNode = ast_accessor_extract_setter(accessorNode);
		if (!ast_is_blank(setterNode)) {
			fieldDecl->setSetMethodName(ASTName::make_shared(ast_setter_extract_name(setterNode)));
		}
		//ゲッターが存在する
		ast* getterNode = ast_accessor_extract_getter(accessorNode);
		if (!ast_is_blank(getterNode)) {
			fieldDecl->setGetMethodName(ASTName::make_shared(ast_getter_extract_name(getterNode)));
		}
	}
	//デフォルト値が存在する
	ast* defValNode = ast_field_extract_default_value(field);
	if (!ast_is_blank(defValNode)) {
		fieldDecl->setDefaultValue(toFactor(defValNode));
	}
	list_delete(mods);
	return fieldDecl;
}

std::shared_ptr<ASTBody> BisonWrapper::toBlock(ast * block) {
	auto ret = ASTBody::make_shared();
	readStmt(ret, block);
	return ret;
}

std::shared_ptr<ASTVariableDeclaration> BisonWrapper::toVarDecl(ast * vardecl) {	
	auto ret = ASTVariableDeclaration::make_shared();
	auto name = ast_vardefine_extract_name(vardecl);
	auto fact = ast_vardefine_extract_fact(vardecl);
	ret->setName(ASTName::make_shared(name));
	ret->setFactor(toFactor(fact));
	//Debug::break_if(this->entryPoint);
	return ret;
}

void BisonWrapper::readStmt(std::shared_ptr<ASTBranch> parent, ast* tree) {
	if (ast_is_blank(tree)) {
		return;
	}
	list* li = ast_expand_stmts(tree);
	int len = list_size(li);
	//	ast_dump(block);
	//	ast_dump_all(li);
	for (int i = 0; i < len; i++) {
		ast* elem = (ast*)list_getAt(li, i);
		parent->add(toStatement(elem));
	}
	list_delete(li);
}

std::shared_ptr<ASTNode> BisonWrapper::toStatement(ast * stmt) {
	auto ret = toExpression(stmt);
	if (ret != nullptr) {
		return ret;
	}
	switch (stmt->tag) {
		case t_VariableDecl: return toVarDecl(stmt);
		case t_If: return toIfStmt(stmt);
		case t_IfElse: return toIfElseStmt(stmt);
		case t_IfElseIfList: return toIfElseIfStmt(stmt);
		case t_IfElseIfListElse: return toIfElseIfElseStmt(stmt);
		case t_While: return toWhileStmt(stmt);
		case t_For: return toForStmt(stmt);
		case t_TryCatch: return toTryCatchStmt(stmt);
		case t_TryCatchFinally: return toTryCatchFinally(stmt);
		case t_TryFinally: return toTryFinally(stmt);
		case t_Throw: return toThrowStmt(stmt);
		case t_Break: return toBreakStmt(stmt);
		case t_Continue: return toContinueStmt(stmt);
		case t_Return: return toReturnStmt(stmt);
		case t_Stmt:
		case t_StmtList:
			Debug::break_if(true);
			break;
		case t_Def_Dyn_Field:
			return toDynFieldDecl(stmt);
		case t_Def_Dyn_Method:
			return toDynMethodDecl(stmt);
		case t_Function:
			if (this->entryPoint) {
				return toMethod(stmt);
			}
			break;
		default: return nullptr;
	}
}

std::shared_ptr<ASTIfStatement> BisonWrapper::toIfStmt(ast * stmt) {
	auto ret = ASTIfStatement::make_shared();
	ast* cond = ast_if_extract_cond(stmt);
	ret->setFactor(toFactor(cond));
	ret->setBody(toBlock(ast_if_extract_body(stmt)));
	return ret;
}

std::shared_ptr<ASTElseStatement> BisonWrapper::toElseStmt(ast * stmt) {
	auto ret = ASTElseStatement::make_shared();
	auto elseBody = ast_else_extract_body(stmt);
	ret->setBody(toBlock(elseBody));
	return ret;
}

std::shared_ptr<ASTIfStatement> BisonWrapper::toIfElseStmt(ast * stmt) {
	auto ret = toIfStmt(ast_if_else_extract_if(stmt));
	ret->setElse(toElseStmt(ast_if_else_extract_else(stmt)));
	return ret;
}

std::shared_ptr<ASTIfStatement> BisonWrapper::toIfElseIfStmt(ast * stmt) {
	auto ret = toIfStmt(ast_if_elseif_list_extract_if(stmt));
	readElseIfList(ret, ast_if_elseif_list_extract_elseif_list(stmt));
	return ret;
}

std::shared_ptr<ASTNode> BisonWrapper::toIfElseIfElseStmt(ast * stmt) {
	//ast_dump(stmt);
	//NOTE:要修正(extractメソッドを用意していない)
	auto if_elseif_list = ast_if_elseif_list_else_extract_if_elseif_list(stmt);
	auto ifStmt = toIfStmt(ast_get_first(if_elseif_list));
	auto elseifList = ast_get_right(if_elseif_list);
	readElseIfList(ifStmt, elseifList);
	ifStmt->setElse(toElseStmt(ast_get_right(stmt)));
	return ifStmt;
}

void BisonWrapper::readElseIfList(std::shared_ptr<ASTIfStatement> if_stmt, ast * elseif_list) {
	if (elseif_list->tag == t_ElseIf) {
		auto elseIf = ASTElseIfStatement::make_shared();
		elseIf->setFactor(toFactor(ast_elseif_extract_cond(elseif_list)));
		elseIf->setBody(toBlock(ast_elseif_extract_body(elseif_list)));
		if_stmt->addElseIf(elseIf);
		return;
	}
	int len = list_size(elseif_list->children);
	for (int i = 0; i < len; i++) {
		auto elseIfAST = (ast*)list_getAt(elseif_list->children, i);
		auto elseIf = ASTElseIfStatement::make_shared();
		elseIf->setFactor(toFactor(ast_elseif_extract_cond(elseIfAST)));
		elseIf->setBody(toBlock(ast_elseif_extract_body(elseIfAST)));
		if_stmt->addElseIf(elseIf);
	}
}

std::shared_ptr<ASTNode> BisonWrapper::toWhileStmt(ast * while_stmt) {
	auto ret = ASTWhileStatement::make_shared();
	ret->setFactor(toFactor(ast_while_extract_cond(while_stmt)));
	ret->setBody(toBlock(ast_while_extract_body(while_stmt)));
	return ret;
}

std::shared_ptr<ASTNode> BisonWrapper::toForStmt(ast * for_stmt) {
	auto ret = ASTForStatement::make_shared();
	//初期化式
	auto init = ast_for_extract_init(for_stmt);
	if (!ast_is_blank(init)) {
		ret->setInitialize(toStatement(init));
	} else ret->setInitialize(ASTBranch::make_shared());
	//条件式
	auto cond = ast_for_extract_cond(for_stmt);
	if (!ast_is_blank(cond)) {
		ret->setFactor(toFactor(cond));
	} else ret->setFactor(ASTBoolean::make_shared(true));
	//更新式
	auto update = ast_for_extract_update(for_stmt);
	if (!ast_is_blank(update)) {
		ret->setUpdate(toStatement(update));
	} else ret->setUpdate(ASTBranch::make_shared());
	//ブロック
	ret->setBody(toBlock(ast_for_extract_body(for_stmt)));
	return ret;
}

std::shared_ptr<ASTTryStatement> BisonWrapper::toTryCatchStmt(ast * try_catch_stmt) {
	auto ret = toTryStmt(ast_try_catch_extract_try(try_catch_stmt));
	ret->setCatchStatement(toCatchStmt(ast_try_catch_extract_catch(try_catch_stmt)));
	return ret;
}

std::shared_ptr<ASTTryStatement> BisonWrapper::toTryCatchFinally(ast * try_catch_finally_stmt) {
	auto ret = toTryStmt(ast_try_catch_finally_extract_try(try_catch_finally_stmt));
	auto cf = ast_try_catch_finally_extract_catch_finally(try_catch_finally_stmt);
	ret->setCatchStatement(toCatchStmt(ast_catch_finally_extract_catch(cf)));
	ret->setFinally(toFinallyStmt(ast_catch_finally_extract_finally(cf)));
	return ret;
}

std::shared_ptr<ASTTryStatement> BisonWrapper::toTryFinally(ast * try_finally_stmt) {
	auto ret = toTryStmt(ast_try_finally_extract_try(try_finally_stmt));
	ret->setFinally(toFinallyStmt(ast_try_finally_extract_finally(try_finally_stmt)));
	return ret;
}

std::shared_ptr<ASTTryStatement> BisonWrapper::toTryStmt(ast * try_stmt) {
	auto body = ast_try_extract_body(try_stmt);
	auto ret = ASTTryStatement::make_shared();
	ret->setBody(toBlock(body));
	return ret;
}

std::shared_ptr<ASTCatchStatement> BisonWrapper::toCatchStmt(ast * catch_stmt) {
	auto ret = ASTCatchStatement::make_shared();
	ret->setCaptureExceptionName(ASTName::make_shared(ast_catch_extract_capturename(catch_stmt)));
	ret->setBody(toBlock(ast_catch_extract_body(catch_stmt)));
	return ret;
}

std::shared_ptr<ASTBody> BisonWrapper::toFinallyStmt(ast * finally_stmt) {
	ast* f = ast_finally_extract_body(finally_stmt);
	return toBlock(f);
}

std::shared_ptr<ASTThrow> BisonWrapper::toThrowStmt(ast * throw_stmt) {
	auto ret = ASTThrow::make_shared();
	ret->setFactor(toFactor(ast_throw_extract_fact(throw_stmt)));
	return ret;
}

ASTNodeSPtr BisonWrapper::toBreakStmt(ast * break_stmt) {
	auto ret = ASTBreakStatement::make_shared();
	return ret;
}

ASTNodeSPtr BisonWrapper::toContinueStmt(ast * continue_stmt) {
	auto ret = ASTContinueStatement::make_shared();
	return ret;
}

ASTNodeSPtr BisonWrapper::toReturnStmt(ast * return_stmt) {
	auto ret = ASTReturnStatement::make_shared();
	auto fact = ast_return_extract_fact(return_stmt);
	if (!ast_is_blank(fact)) {
		ret->setFactor(toFactor(fact));
	}
	return ret;
}

std::shared_ptr<ASTFactor> BisonWrapper::toExpression(ast * factor) {
	switch (factor->tag) {
		case t_Assign: return (toAssignVal(factor));
		case t_Add_Assign: return (toAddAssignVal(factor));
		case t_Sub_Assign: return (toSubAssignVal(factor));
		case t_Mul_Assign: return (toMulAssignVal(factor));
		case t_Div_Assign: return (toDivAssignVal(factor));
		case t_Mod_Assign: return (toModAssignVal(factor));
		case t_InvokeBySelf: return (toInvokeBySelfVal(factor));
		case t_InvokeByMessage: return (toInvokeByMessageVal(factor));
		case t_PreIncrement: return toPreIncVal(factor);
		case t_PreDecrement: return toPreDecVal(factor);
		case t_PostIncrement: return toPostIncVal(factor);
		case t_PostDecrement: return toPostDecVal(factor);
		default: return nullptr;
	}
}

std::shared_ptr<ASTPointer> BisonWrapper::toPointer(ast * factor) {
	switch (factor->tag) {
		case t_Variable: return toVariableVal(factor);
		case t_FieldAccess: return toFieldAccessVal(factor);
		default: return nullptr;
	}
}

std::shared_ptr<ASTFactor> BisonWrapper::toFactor(ast * factor) {
	auto ret = toExpression(factor);
	if (ret != nullptr) {
		return ret;
	}
	ret = toPointer(factor);
	if (ret != nullptr) {
		return ret;
	}
	switch (factor->tag) {
		//primary
		case t_Short: return toShortVal(factor);
		case t_Int: return toIntVal(factor);
		case t_Long: return toLongVal(factor);
		case t_Float: return toFloatVal(factor);
		case t_Double: return toDoubleVal(factor);
		case t_Character: return toCharVal(factor);
		case t_String: return toStrVal(factor);
		case t_True: return toTrueVal(factor);
		case t_False: return toFalseVal(factor);
		case t_Null: return toNullVal(factor);
		//unary
		case t_Not: return toNotVal(factor);
		case t_Minus: return toMinusVal(factor);
		//binary
		case t_Add: return toAddVal(factor);
		case t_Sub: return toSubVal(factor);
		case t_Mul: return toMulVal(factor);
		case t_Div: return toDivVal(factor);
		case t_Mod: return toModVal(factor);

		case t_Equal: return toEqVal(factor);
		case t_NotEqual: return toNotEqVal(factor);
		case t_Biggest: return toBiggestVal(factor);
		case t_EBiggest: return toEBiggestVal(factor);
		case t_Smallest: return toSmallestVal(factor);
		case t_ESmallest: return toESmallestVal(factor);

		case t_Or: return toOrVal(factor);
		case t_OrOr: return toOrOrVal(factor);
		case t_And: return toAndVal(factor);
		case t_AndAnd: return toAndAndVal(factor);
		case t_Lambda: return toLambdaVal(factor);
		case t_Array: return toArrayVal(factor);
		case t_This: return toThisVal(factor);
		case t_Super: return toSuperVal(factor);
		default: return nullptr;
	}
}

std::shared_ptr<ASTFactor> BisonWrapper::toShortVal(ast * factor) {
	return ASTNumeric::make_shared(factor->u.short_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toIntVal(ast * factor) {
	return ASTNumeric::make_shared(factor->u.int_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toLongVal(ast * factor) {
	return ASTNumeric::make_shared(factor->u.long_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toFloatVal(ast * factor) {
	return ASTNumeric::make_shared(factor->u.float_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toDoubleVal(ast * factor) {
	return ASTNumeric::make_shared(factor->u.double_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toCharVal(ast * factor) {
	return ASTCharacter::make_shared(factor->u.char_value);
}

std::shared_ptr<ASTFactor> BisonWrapper::toStrVal(ast * factor) {
	auto str = std::string(factor->u.string_value);
	return ASTString::make_shared(str);
}

std::shared_ptr<ASTVariable> BisonWrapper::toVariableVal(ast * factor) {
	return ASTVariable::make_shared(ASTName::make_shared(factor->u.string_value));
}

std::shared_ptr<ASTLambdaDeclaration> BisonWrapper::toLambdaVal(ast * factor) {
	auto ret = ASTLambdaDeclaration::make_shared();
	//本文を設定
	ret->setBody(toBlock(ast_lambda_extract_block(factor)));
	auto argsNode = ast_lambda_extract_parameter_list(factor);
	//引数列を設定
	if (!ast_is_blank(argsNode)) {
		if (argsNode->tag == t_Parameter) {
			ret->addParameter(ASTParameter::make_shared(ASTName::make_shared(argsNode->u.string_value)));
		} else {
			list* args = ast_expand_parameters(argsNode);
			for (int i = 0; i < list_size(args); i++) {
				ast* nameAST = (ast*)list_getAt(args, i);
				ret->addParameter(ASTParameter::make_shared(ASTName::make_shared(nameAST->u.string_value)));
			}
			list_delete(args);
		}
	}
	return ret;
}

std::shared_ptr<ASTFactor> BisonWrapper::toArrayVal(ast * factor) {
	auto arrInit = ASTArrayInitializer::make_shared();
	auto argument_list = ast_array_extract_argument_list(factor);
	if (ast_is_blank(argument_list)) {
		return arrInit;
	}
	list* args = ast_expand_arguments(argument_list);
	for (int i = 0; i < list_size(args); i++) {
		arrInit->addFactor(toFactor((ast*)list_getAt(args, i)));
	}
	list_delete(args);
	return arrInit;
}

std::shared_ptr<ASTFactor> BisonWrapper::toTrueVal(ast * factor) {
	return ASTBoolean::make_shared(true);
}

std::shared_ptr<ASTFactor> BisonWrapper::toFalseVal(ast * factor) {
	return ASTBoolean::make_shared(false);
}

std::shared_ptr<ASTFactor> BisonWrapper::toNullVal(ast * factor) {
	return ASTNullFactor::make_shared();
}

std::shared_ptr<ASTFactor> BisonWrapper::toThisVal(ast * factor) {
	return ASTThisFactor::make_shared();
}

std::shared_ptr<ASTFactor> BisonWrapper::toSuperVal(ast * factor) {
	return ASTSuperFactor::make_shared();
}

std::shared_ptr<ASTFieldAccess> BisonWrapper::toFieldAccessVal(ast * factor) {
	auto ret = ASTFieldAccess::make_shared();
	auto fact = toFactor(ast_field_access_extract_fact(factor));
	auto name = ast_field_access_extract_name(factor);
	ret->setParent(fact);
	ret->setName(ASTName::make_shared(name));
	return ret;
}

std::shared_ptr<ASTFactor> BisonWrapper::toInvokeBySelfVal(ast * factor) {
	auto ret = ASTMethodInvocationBySelf::make_shared();
	ret->setName(ASTName::make_shared(ast_invoke_by_self_extract_name(factor)));
	readArguments(ret, ast_invoke_by_self_extract_argument_list(factor));
	return ret;
}

std::shared_ptr<ASTFactor> BisonWrapper::toInvokeByMessageVal(ast * factor) {
	auto ret = ASTMethodInvocationByMessage::make_shared();
	auto invoker = ast_invoke_by_message_extract_invoker(factor);
	ret->setInvoker(toFactor(invoker));
	auto name = ast_invoke_by_message_extract_name(factor);
	ret->setName(ASTName::make_shared(name));
	readArguments(ret, ast_invoke_by_message_extract_argument_list(factor));
	return ret;
}

void BisonWrapper::readArguments(std::shared_ptr<ASTMethodInvocation> inv, ast* argument_list) {
	for (std::shared_ptr<ASTFactor> fact : asArgumentList(argument_list)) {
		inv->addArgument(fact);
	}
}

std::vector<std::shared_ptr<ASTFactor>> BisonWrapper::asArgumentList(ast * argument_list) {
	auto ret = std::vector<std::shared_ptr<ASTFactor>>();
	if (ast_is_blank(argument_list)) {
		return ret;
	}
	if (argument_list->tag == t_Argument) {
		auto node = ast_get_first(argument_list);
		auto fact = toFactor(node);
		ret.push_back(fact);
	//	inv->addArgument(fact);
	} else {
		list* li = ast_expand_arguments(argument_list);
		int len = list_size(li);
		for (int i = 0; i < len; i++) {
			auto astc = (ast*)list_getAt(li, i);
			auto arg = toFactor(astc);
			ret.push_back(arg);
		//	inv->addArgument(arg);
		}
		list_delete(li);
	}
	return ret;
}

std::shared_ptr<ASTFactor> BisonWrapper::toNotVal(ast * factor) {
	return toUnaryOperator<ASTNotOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toMinusVal(ast * factor) {
	return toUnaryOperator<ASTNegativeOperator>(factor);
}

//
//binary operator
//
std::shared_ptr<ASTFactor> BisonWrapper::toAddVal(ast * factor) {
	return toBinaryOperator<ASTAddOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toSubVal(ast * factor) {
	return toBinaryOperator<ASTSubOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toMulVal(ast * factor) {
	return toBinaryOperator<ASTMulOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toDivVal(ast * factor) {
	return toBinaryOperator<ASTDivOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toModVal(ast * factor) {
	return toBinaryOperator<ASTModOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toEqVal(ast * factor) {
	return toBinaryOperator<ASTEqualOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toNotEqVal(ast * factor) {
	return toBinaryOperator<ASTNotEqualsOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toBiggestVal(ast * factor) {
	return toBinaryOperator<ASTBiggestOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toEBiggestVal(ast * factor) {
	return toBinaryOperator<ASTEBiggestOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toSmallestVal(ast * factor) {
	return toBinaryOperator<ASTSmallestOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toESmallestVal(ast * factor) {
	return toBinaryOperator<ASTESmallestOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toOrVal(ast * factor) {
	return toBinaryOperator<ASTOrOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toOrOrVal(ast * factor) {
	return toBinaryOperator<ASTOrOrOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toAndVal(ast * factor) {
	return toBinaryOperator<ASTAndOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toAndAndVal(ast * factor) {
	return toBinaryOperator<ASTAndAndOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toAssignVal(ast * factor) {
	return toAssignOperator<ASTAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toAddAssignVal(ast * factor) {
	return toAssignOperator<ASTAddAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toSubAssignVal(ast * factor) {
	return toAssignOperator<ASTSubAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toMulAssignVal(ast * factor) {
	return toAssignOperator<ASTMulAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toDivAssignVal(ast * factor) {
	return toAssignOperator<ASTDivAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toModAssignVal(ast * factor) {
	return toAssignOperator<ASTModAssignOperator>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toPreIncVal(ast * factor) {
	return toPreUnaryOperator<ASTIncrement>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toPreDecVal(ast * factor) {
	return toPreUnaryOperator<ASTDecrement>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toPostIncVal(ast * factor) {
	return toPostUnaryOperator<ASTIncrement>(factor);
}

std::shared_ptr<ASTFactor> BisonWrapper::toPostDecVal(ast * factor) {
	return toPostUnaryOperator<ASTDecrement>(factor);
}

Modifier BisonWrapper::toModifier(list * modifiers) {
	int flags = 0;
	for (int i = 0; i < list_size(modifiers); i++) {
		int flag = tagToModifier(((ast*)list_getAt(modifiers, i))->tag);
		if (i == 0) {
			flags = flag;
		} else flags |= flag;
	}
	return Modifier(flags);
}

int BisonWrapper::tagToModifier(ast_tag tag) {
	switch (tag) {
		case t_Public: return Modifier::PUBLIC;
		case t_Private: return Modifier::PRIVATE;
		case t_Protected: return Modifier::PROTECTED;
		case t_Static: return Modifier::STATIC;
		case t_Final: return Modifier::FINAL;
		case t_Native: return Modifier::NATIVE;
		case t_Modifier_Blank: return Modifier::BLANK;
	}
	return 0;
}
//---private method
