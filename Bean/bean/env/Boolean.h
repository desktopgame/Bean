#pragma once
#ifndef BEAN_ENV_BOOLEAN_H
#define BEAN_ENV_BOOLEAN_H
#include "Object_.h"
/**
 * 真偽値型.
 */
class Boolean : public Object_ {
public:
	/**
	 * Booleanへ変換します.
	 * @param v
	 * @return
	 */
	static Boolean* get(bool v);
	
	/**
	 * どちらかがtrueのときtrueを返します.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (Boolean* left, Boolean* right);

	/**
	 * どちらかがtrueのときtrueを返します.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (bool left, bool right);

	/**
	 * どちらもtrueのときtrueを返します.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* and(Boolean* left, Boolean* right);

	/**
	* どちらもtrueのときtrueを返します.
	* @param left
	* @param right
	* @return
	*/
	static Boolean* and(bool left, bool right);

	/**
	 * trueを返します.
	 * @return
	 */
	static Boolean* getTrue() {
		static Boolean inst = Boolean(true);
		return &inst;
	}

	/**
	 * falseを返します.
	 * @return
	 */
	static Boolean* getFalse() {
		static Boolean inst = Boolean(false);
		return &inst;
	}
	/**
	 * 指定の値がbool型ならtrue
	 * @param o
	 * @return
	 */
	static bool isBool(Object_* o) {
		if (o == NULL || o == nullptr) return false;
		return o == getTrue() || o == getFalse();
	}

	/**
	 * true/falseを返します.
	 * @return
	 */
	bool of() {
		return a;
	}
	bool isSingleton() override;
	void dump() override;
	Boolean* asBoolean() override;
	// Object_ を介して継承されました
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

