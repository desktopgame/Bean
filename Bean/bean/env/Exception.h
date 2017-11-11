#pragma once
#ifndef BEAN_ENV_EXCEPTION_H
#define BEAN_ENV_EXCEPTION_H
#include <stdexcept>
#include <vector>
class ClassLoader;
class Class;
class Method;
class Numeric;
class Object_;
/**
 * 例外に関するユーティリティクラス.
 */
class Exception {
public:
	/**
	 * 新たな例外を作成します.
	 * @param className
	 * @param args
	 */
	static Object_* new_e(const std::string& className, std::vector<Object_*> args);

	/**
	 * 新たな例外を作成します.
	 * @param className
	 * @param msg
	 */
	static Object_* new_e_simple(const std::string& className, const std::string& msg);

	/**
	 * 指定の例外をスローします.
	 * @param ref
	 */
	static void throw_e(Object_* ref);

	/**
	 * 指定の名前の例外を指定の引数でスローします.
	 * @param className
	 * @param args
	 */
	static void throw_e(std::string className, std::vector<Object_*> args);

	/**
	 * 指定の名前の例外を () で起動します.
	 * @param className
	 */
	static void throw_e_zero_args(std::string className);

	/**
	 * 指定の名前の例外を (null, msg) で起動します。
	 * @param className
	 * @param msg
	 */
	static void throw_e_simple(std::string className, std::string msg);
	
	/**
	 * 指定の名前の例外を (null, e.what()) で起動します。
	 * @param className
	 * @param msg
	 */
	static void throw_e_wrap(std::string className, std::exception e);


	/**
	 * 値の範囲を検査して不正なら例外をスローします.
	 * @param v
	 * @return スローしたらtrue.
	 */
	static bool checkIndexNegative(Numeric* v);

	/**
	 * 値の範囲を検査して不正なら例外をスローします.
	 * @param v
	 * @param min
	 * @param max
	 * @return スローしたらtrue.
	 */
	static bool checkIndexRange(Numeric* v, int min, int max);

	/**
	 * 色の範囲を検査して不正なら例外をスローします.
	 * @param r
	 * @param b
	 * @param b
	 * @return スローしたらtrue.
	 */
	static bool checkColor(Numeric* r, Numeric* g, Numeric* b);

	/**
	 * 色の範囲を検査して不正なら例外をスローします.
	 * @param r
	 * @param b
	 * @param b
	 * @param a
	 * @return スローしたらtrue.
	 */
	static bool checkColor(Numeric* r, Numeric* g, Numeric* b, Numeric* a);
private:
	Exception();
	~Exception();
};
#endif // !BEAN_ENV_EXCEPTION_H
