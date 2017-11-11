#pragma once
#ifndef BEAN_PARSER_BISONWRAPPER_H
#define BEAN_PARSER_BISONWRAPPER_H
#include <string>
#include "bison/ast.h"
#include "bison/compiler.h"
#include "../ast/ASTAliasStatement.h"
#include "../ast/ASTBranch.h"
#include "../ast/ASTCatchStatement.h"
#include "../ast/ASTConstructorChain.h"
#include "../ast/ASTDynFieldDeclaration.h"
#include "../ast/ASTDynMethodDeclaration.h"
#include "../ast/ASTFieldAccess.h"
#include "../ast/ASTIncludeStatement.h"
#include "../ast/ASTNode.h"
#include "../ast/ASTPointer.h"
#include "../ast/ASTThrow.h"
#include "../ast/ASTTryStatement.h"
#include "../ast/ASTVariable.h"
#include "../env/Modifier.h"
/**
 * Bisonのラッパーです.
 * Cで作成した構文木をC++の bean/ast 名前空間の構文木へ変換します。
 */
class BisonWrapper {
public:
	BisonWrapper(bool entryPoint);
	~BisonWrapper();
	/**
	 * 指定のファイルを解析して構文木を作成します.
	 * 失敗したなら nullptr を返します。
	 * @param filePath
	 */
	ASTNodeSPtr compile(const std::string filePath);
	/**
	 * 指定のソースを解析して構文木を作成します.
	 * 失敗したなら nullptr を返します。
	 * ファイルパスは読み込みに失敗したときに適切なエラーを出すために使用されます。
	 * @param filePath
	 * @param source
	 */
	ASTNodeSPtr compilestr(const std::string filePath, char* source);
private:
	ASTNodeSPtr compileImplC(std::function<void(compiler*)> preFunc, std::function<int()> compileFunc);

	void compileImpl(ast* tree, std::shared_ptr<ASTBranch> branch);
	void compileImplCase(ast* tree, std::shared_ptr<ASTBranch> branch);
	
	std::shared_ptr<ASTAliasStatement> toAlias(ast* tree);
	std::shared_ptr<ASTIncludeStatement> toInclude(ast* tree);
	std::string toNamespaceStr(ast* tree);
	std::shared_ptr<ASTClassDeclaration> toClass(ast* tree, std::shared_ptr<ASTBranch> branch);
	std::shared_ptr<ASTEnumDeclaration> toEnum(ast* tree);
	std::shared_ptr<ASTMethodDeclaration> toMethod(ast* method);
	std::shared_ptr<ASTMethodDeclaration> toConstructor(ast* method);
	std::shared_ptr<ASTConstructorChain> toChain(ast* chain);
	std::shared_ptr<ASTDynFieldDeclaration> toDynFieldDecl(ast* dyn_field);
	std::shared_ptr<ASTDynMethodDeclaration> toDynMethodDecl(ast* dyn_method);
	void readMethod(std::shared_ptr<ASTMethodDeclaration> methodDecl, ast* modifier_list, ast* parameter_list, ast* block);
	std::shared_ptr<ASTFieldDeclaration> toField(ast* field);
	std::shared_ptr<ASTBody> toBlock(ast* block);
	std::shared_ptr<ASTVariableDeclaration> toVarDecl(ast* vardecl);
	void readStmt(std::shared_ptr<ASTBranch> parent, ast* tree);
	//戻り値を持たないが
	//それ単体で存在出来る
	std::shared_ptr<ASTNode> toStatement(ast* stmt);

	std::shared_ptr<ASTIfStatement> toIfStmt(ast* stmt);

	std::shared_ptr<ASTElseStatement> toElseStmt(ast* stmt);

	std::shared_ptr<ASTIfStatement> toIfElseStmt(ast* stmt);

	std::shared_ptr<ASTIfStatement> toIfElseIfStmt(ast* stmt);

	std::shared_ptr<ASTNode> toIfElseIfElseStmt(ast* stmt);

	void readElseIfList(std::shared_ptr<ASTIfStatement> if_stmt, ast* elseif_list);

	std::shared_ptr<ASTNode> toWhileStmt(ast* while_stmt);

	std::shared_ptr<ASTNode> toForStmt(ast* for_stmt);

	std::shared_ptr<ASTTryStatement> toTryCatchStmt(ast* try_catch_stmt);

	std::shared_ptr<ASTTryStatement> toTryCatchFinally(ast* try_catch_finally_stmt);

	std::shared_ptr<ASTTryStatement> toTryFinally(ast* try_finally_stmt);

	std::shared_ptr<ASTTryStatement> toTryStmt(ast* try_stmt);

	std::shared_ptr<ASTCatchStatement> toCatchStmt(ast* catch_stmt);

	std::shared_ptr<ASTBody> toFinallyStmt(ast* finally_stmt);

	std::shared_ptr<ASTThrow> toThrowStmt(ast* throw_stmt);

	ASTNodeSPtr toBreakStmt(ast* break_stmt);

	ASTNodeSPtr toContinueStmt(ast* continue_stmt);

	ASTNodeSPtr toReturnStmt(ast* return_stmt);

	//eval
	//戻り値を持つ表現だが、
	//それ単体で存在出来る
	std::shared_ptr<ASTFactor> toExpression(ast* factor);

	//戻り値を持つ表現だが、
	//変数やフィールドなど代入先として利用可能
	std::shared_ptr<ASTPointer> toPointer(ast* factor);

	//戻り値を持つ表現だが、
	//関数の引数列や代入先などコンテキストに依存する
	std::shared_ptr<ASTFactor> toFactor(ast* factor);

	std::shared_ptr<ASTFactor> toShortVal(ast* factor);
	std::shared_ptr<ASTFactor> toIntVal(ast* factor);
	std::shared_ptr<ASTFactor> toLongVal(ast* factor);
	std::shared_ptr<ASTFactor> toFloatVal(ast* factor);
	std::shared_ptr<ASTFactor> toDoubleVal(ast* factor);
	std::shared_ptr<ASTFactor> toCharVal(ast* factor);
	std::shared_ptr<ASTFactor> toStrVal(ast* factor);
	std::shared_ptr<ASTVariable> toVariableVal(ast* factor);
	std::shared_ptr<ASTLambdaDeclaration> toLambdaVal(ast* factor);
	std::shared_ptr<ASTFactor> toArrayVal(ast* factor);
	std::shared_ptr<ASTFactor> toTrueVal(ast* factor);
	std::shared_ptr<ASTFactor> toFalseVal(ast* factor);
	std::shared_ptr<ASTFactor> toNullVal(ast* factor);
	std::shared_ptr<ASTFactor> toThisVal(ast* factor);
	std::shared_ptr<ASTFactor> toSuperVal(ast* factor);
	std::shared_ptr<ASTFieldAccess> toFieldAccessVal(ast* factor);

	std::shared_ptr<ASTFactor> toInvokeBySelfVal(ast* factor);
	std::shared_ptr<ASTFactor> toInvokeByMessageVal(ast* factor);
	void readArguments(std::shared_ptr<ASTMethodInvocation> inv, ast* argument_list);
	std::vector<std::shared_ptr<ASTFactor>> asArgumentList(ast* argument_list);

	std::shared_ptr<ASTFactor> toNotVal(ast* factor);
	std::shared_ptr<ASTFactor> toMinusVal(ast* factor);

	template<typename T>
	std::shared_ptr<T> toUnaryOperator(ast* factor) {
		auto ret = T::make_shared();
		ret->setCondition(toFactor(ast_get_first(factor)));
		return ret;
	}

	std::shared_ptr<ASTFactor> toAddVal(ast* factor);
	std::shared_ptr<ASTFactor> toSubVal(ast* factor);
	std::shared_ptr<ASTFactor> toMulVal(ast* factor);
	std::shared_ptr<ASTFactor> toDivVal(ast* factor);
	std::shared_ptr<ASTFactor> toModVal(ast* factor);

	std::shared_ptr<ASTFactor> toEqVal(ast* factor);
	std::shared_ptr<ASTFactor> toNotEqVal(ast* factor);
	std::shared_ptr<ASTFactor> toBiggestVal(ast* factor);
	std::shared_ptr<ASTFactor> toEBiggestVal(ast* factor);
	std::shared_ptr<ASTFactor> toSmallestVal(ast* factor);
	std::shared_ptr<ASTFactor> toESmallestVal(ast* factor);

	std::shared_ptr<ASTFactor> toOrVal(ast* factor);
	std::shared_ptr<ASTFactor> toOrOrVal(ast* factor);
	std::shared_ptr<ASTFactor> toAndVal(ast* factor);
	std::shared_ptr<ASTFactor> toAndAndVal(ast* factor);

	template<typename T>
	std::shared_ptr<T> toBinaryOperator(ast* factor) {
		auto ret = T::make_shared();
		ret->setLeft(toFactor(ast_get_left(factor)));
		ret->setRight(toFactor(ast_get_right(factor)));
		return ret;
	}

	std::shared_ptr<ASTFactor> toAssignVal(ast* factor);
	std::shared_ptr<ASTFactor> toAddAssignVal(ast* factor);
	std::shared_ptr<ASTFactor> toSubAssignVal(ast* factor);
	std::shared_ptr<ASTFactor> toMulAssignVal(ast* factor);
	std::shared_ptr<ASTFactor> toDivAssignVal(ast* factor);
	std::shared_ptr<ASTFactor> toModAssignVal(ast* factor);

	template<typename T>
	std::shared_ptr<T> toAssignOperator(ast* factor) {
		auto ret = T::make_shared();
		ret->setPointer(toPointer(ast_get_left(factor)));
		ret->setFactor(toFactor(ast_get_right(factor)));
		return ret;
	}

	std::shared_ptr<ASTFactor> toPreIncVal(ast* factor);
	std::shared_ptr<ASTFactor> toPreDecVal(ast* factor);
	std::shared_ptr<ASTFactor> toPostIncVal(ast* factor);
	std::shared_ptr<ASTFactor> toPostDecVal(ast* factor);

	template<typename T>
	std::shared_ptr<T> toPreUnaryOperator(ast* factor) {
		auto ret = T::make_shared();
		ret->setPrefix(true);
		ret->setArgument(toFactor(ast_inc_dec_extract_argument(factor)));
		return ret;
	}

	template<typename T>
	std::shared_ptr<T> toPostUnaryOperator(ast* factor) {
		auto ret = T::make_shared();
		ret->setSuffix(true);
		ret->setArgument(toFactor(ast_inc_dec_extract_argument(factor)));
		return ret;
	}

	Modifier toModifier(list* modifiers);
	int tagToModifier(ast_tag tag);
private:
	bool entryPoint;
};
#endif // !BEAN_PARSER_BISONWRAPPER_H
