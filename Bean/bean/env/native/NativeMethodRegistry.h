#pragma once
#ifndef BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
#define BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
#include <unordered_map>
#include "NativeMethodExecutor.h"
/**
 * C++で実行されるメソッドのレジストリです.
 */
class NativeMethodRegistry {
public:
	NativeMethodRegistry(const NativeMethodRegistry&) = delete;
	NativeMethodRegistry& operator=(const NativeMethodRegistry&) = delete;
	NativeMethodRegistry(NativeMethodRegistry&&) = delete;
	NativeMethodRegistry& operator=(NativeMethodRegistry&&) = delete;
	/**
	* 唯一のインスタンスを返します.
	* @return
	*/
	static NativeMethodRegistry* const getInstance() {
		static NativeMethodRegistry inst;
		return &inst;
	}

	/**
	 * 指定のメソッドをレジストリに紐づけます.
	 * @param name 名前空間.クラス名#(引数の数)
	 * @param nme
	 */
	void add(const std::string& name, NativeMethodExecutor* nme);

	/**
	 * 指定の名前のメソッドを返します.
	 * 含まれない場合は nullptr を返します。
	 * @param name 名前空間.クラス名#(引数の数)
	 * @return
	 */
	NativeMethodExecutor* const get(const std::string& name);

	/**
	 * 指定のメソッドが含まれるかどうかを返します.
	 * @param name 名前空間.クラス名#(引数の数)
	 * @return
	 */
	bool contains(const std::string& name);

	/**
	 * 指定のメソッドを削除します.
	 * @parma name 名前空間.クラス名#(引数の数)
	 */
	void remove(const std::string& name);
	
	/**
	 * 全てのメソッドを削除します.
	 */
	void clear();
private:
	NativeMethodRegistry() {
		this->map = std::unordered_map<std::string, NativeMethodExecutor*>();
	}
	~NativeMethodRegistry() {
		clear();
	}
	std::unordered_map<std::string, NativeMethodExecutor*> map;
};
#endif // !BEAN_ENV_NATIVE_NATIVEMETHODREGISTRY_H
