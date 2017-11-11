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
 * ��O�Ɋւ��郆�[�e�B���e�B�N���X.
 */
class Exception {
public:
	/**
	 * �V���ȗ�O���쐬���܂�.
	 * @param className
	 * @param args
	 */
	static Object_* new_e(const std::string& className, std::vector<Object_*> args);

	/**
	 * �V���ȗ�O���쐬���܂�.
	 * @param className
	 * @param msg
	 */
	static Object_* new_e_simple(const std::string& className, const std::string& msg);

	/**
	 * �w��̗�O���X���[���܂�.
	 * @param ref
	 */
	static void throw_e(Object_* ref);

	/**
	 * �w��̖��O�̗�O���w��̈����ŃX���[���܂�.
	 * @param className
	 * @param args
	 */
	static void throw_e(std::string className, std::vector<Object_*> args);

	/**
	 * �w��̖��O�̗�O�� () �ŋN�����܂�.
	 * @param className
	 */
	static void throw_e_zero_args(std::string className);

	/**
	 * �w��̖��O�̗�O�� (null, msg) �ŋN�����܂��B
	 * @param className
	 * @param msg
	 */
	static void throw_e_simple(std::string className, std::string msg);
	
	/**
	 * �w��̖��O�̗�O�� (null, e.what()) �ŋN�����܂��B
	 * @param className
	 * @param msg
	 */
	static void throw_e_wrap(std::string className, std::exception e);


	/**
	 * �l�͈̔͂��������ĕs���Ȃ��O���X���[���܂�.
	 * @param v
	 * @return �X���[������true.
	 */
	static bool checkIndexNegative(Numeric* v);

	/**
	 * �l�͈̔͂��������ĕs���Ȃ��O���X���[���܂�.
	 * @param v
	 * @param min
	 * @param max
	 * @return �X���[������true.
	 */
	static bool checkIndexRange(Numeric* v, int min, int max);

	/**
	 * �F�͈̔͂��������ĕs���Ȃ��O���X���[���܂�.
	 * @param r
	 * @param b
	 * @param b
	 * @return �X���[������true.
	 */
	static bool checkColor(Numeric* r, Numeric* g, Numeric* b);

	/**
	 * �F�͈̔͂��������ĕs���Ȃ��O���X���[���܂�.
	 * @param r
	 * @param b
	 * @param b
	 * @param a
	 * @return �X���[������true.
	 */
	static bool checkColor(Numeric* r, Numeric* g, Numeric* b, Numeric* a);
private:
	Exception();
	~Exception();
};
#endif // !BEAN_ENV_EXCEPTION_H
