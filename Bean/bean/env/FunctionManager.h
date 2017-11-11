#pragma once
#ifndef BEAN_ENV_FUNCTIONMANAGER_H
#define BEAN_ENV_FUNCTIONMANAGER_H
#include <vector>
class Function;
/**
 * トップレベルのクラスローダーで使用されます.
 */
class FunctionManager {
public:
	FunctionManager();
	~FunctionManager();
	/**
	 * トップレベルの関数を追加します.
	 * @param func
	 */
	void addFunction(Function* func);

	/**
	 * 指定のシグネチャの関数を返します.
	 * 見つからなかったらnullptrを返します.
	 * @param name
	 * @param argCount
	 */
	Function* const findFunction(std::string name, int argCount) const;

	/**
	 * 指定位置の関数を返します.
	 * @param index
	 */
	Function* const getFunctionAt(int index) const;

	/**
	 * 既に同じシグネチャの関数があるならtrueを返します.
	 * @param func
	 * @return
	 */
	bool contains(Function* func) const;

	/**
	 * 全ての関数の数を返します.
	 * @return
	 */
	int getFunctionCount();
private:
	std::vector<Function*> funcVec;
};
#endif // !BEAN_ENV_FUNCTIONMANAGER_H

