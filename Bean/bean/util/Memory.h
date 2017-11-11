#pragma once
#ifndef BEAN_UTIL_MEMORY_H
#define BEAN_UTIL_MEMORY_H
#include <memory>
class Object_;
/**
 * メモリやアドレスに関するユーティリティ.
 */
class Memory {
public:
	/**
	 * 指定のオブジェクトのアドレスを返します.
	 * @param p
	 */
	static int getAddres(void* p);

	/**
	 * 指定のオブジェクトのアドレスを表示します.
	 * @param p
	 */
	static void printAddres(void* p);

	/**
	 * 指定の型を表す null を返します.
	 * @return
	 */
	template<typename T>
	static T* getNull();

	/**
	 * 指定の型を表す null を返します.
	 * @return
	 */
	template<typename T>
	static std::shared_ptr<T> getSharedNull();

	/** 
	 * 指定のポインタが null ならtrue.
	 * @param obj
	 * @return
	 */
	static bool isObjNull(Object_* obj);

	/**
	 * 指定のポインタが null ならtrue.
	 * @param ptr
	 * @return
	 */
	template<typename T>
	static bool isNull(T* ptr);

	/**
	 * 指定のポインタが null ならtrue.
	 * @param ptr
	 * @return
	 */
	template<typename T>
	static bool isSharedNull(std::shared_ptr<T> ptr);
private:
	Memory();
	~Memory();
};
#include "MemoryImpl.h"
#endif // !BEAN_UTIL_MEMORY_H


