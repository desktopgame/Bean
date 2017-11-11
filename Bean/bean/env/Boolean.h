#pragma once
#ifndef BEAN_ENV_BOOLEAN_H
#define BEAN_ENV_BOOLEAN_H
#include "Object_.h"
/**
 * �^�U�l�^.
 */
class Boolean : public Object_ {
public:
	/**
	 * Boolean�֕ϊ����܂�.
	 * @param v
	 * @return
	 */
	static Boolean* get(bool v);
	
	/**
	 * �ǂ��炩��true�̂Ƃ�true��Ԃ��܂�.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (Boolean* left, Boolean* right);

	/**
	 * �ǂ��炩��true�̂Ƃ�true��Ԃ��܂�.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (bool left, bool right);

	/**
	 * �ǂ����true�̂Ƃ�true��Ԃ��܂�.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* and(Boolean* left, Boolean* right);

	/**
	* �ǂ����true�̂Ƃ�true��Ԃ��܂�.
	* @param left
	* @param right
	* @return
	*/
	static Boolean* and(bool left, bool right);

	/**
	 * true��Ԃ��܂�.
	 * @return
	 */
	static Boolean* getTrue() {
		static Boolean inst = Boolean(true);
		return &inst;
	}

	/**
	 * false��Ԃ��܂�.
	 * @return
	 */
	static Boolean* getFalse() {
		static Boolean inst = Boolean(false);
		return &inst;
	}
	/**
	 * �w��̒l��bool�^�Ȃ�true
	 * @param o
	 * @return
	 */
	static bool isBool(Object_* o) {
		if (o == NULL || o == nullptr) return false;
		return o == getTrue() || o == getFalse();
	}

	/**
	 * true/false��Ԃ��܂�.
	 * @return
	 */
	bool of() {
		return a;
	}
	bool isSingleton() override;
	void dump() override;
	Boolean* asBoolean() override;
	// Object_ ����Čp������܂���
	Object_ * clone() override;
	Object_ * equals(Object_ * right) override;
protected:
	void lazyLoading() override;
private:
	Boolean(bool a);
	~Boolean();
	
	//Boolean(const Boolean&) = delete;
	//Boolean& operator=(const Boolean&) = delete;
	//Boolean(Boolean&&) = delete;
	//Boolean& operator=(Boolean&&) = delete;
private:
	bool a;
};
#endif // !BEAN_ENV_BOOLEAN_H

