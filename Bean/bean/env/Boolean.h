#pragma once
#ifndef BEAN_ENV_BOOLEAN_H
#define BEAN_ENV_BOOLEAN_H
#include "Object_.h"
/**
 * ^‹U’lŒ^.
 */
class Boolean : public Object_ {
public:
	/**
	 * Boolean‚Ö•ÏŠ·‚µ‚Ü‚·.
	 * @param v
	 * @return
	 */
	static Boolean* get(bool v);
	
	/**
	 * ‚Ç‚¿‚ç‚©‚ªtrue‚Ì‚Æ‚«true‚ğ•Ô‚µ‚Ü‚·.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (Boolean* left, Boolean* right);

	/**
	 * ‚Ç‚¿‚ç‚©‚ªtrue‚Ì‚Æ‚«true‚ğ•Ô‚µ‚Ü‚·.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* or (bool left, bool right);

	/**
	 * ‚Ç‚¿‚ç‚àtrue‚Ì‚Æ‚«true‚ğ•Ô‚µ‚Ü‚·.
	 * @param left
	 * @param right
	 * @return
	 */
	static Boolean* and(Boolean* left, Boolean* right);

	/**
	* ‚Ç‚¿‚ç‚àtrue‚Ì‚Æ‚«true‚ğ•Ô‚µ‚Ü‚·.
	* @param left
	* @param right
	* @return
	*/
	static Boolean* and(bool left, bool right);

	/**
	 * true‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	static Boolean* getTrue() {
		static Boolean inst = Boolean(true);
		return &inst;
	}

	/**
	 * false‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	static Boolean* getFalse() {
		static Boolean inst = Boolean(false);
		return &inst;
	}
	/**
	 * w’è‚Ì’l‚ªboolŒ^‚È‚çtrue
	 * @param o
	 * @return
	 */
	static bool isBool(Object_* o) {
		if (o == NULL || o == nullptr) return false;
		return o == getTrue() || o == getFalse();
	}

	/**
	 * true/false‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	bool of() {
		return a;
	}
	bool isSingleton() override;
	void dump() override;
	Boolean* asBoolean() override;
	// Object_ ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
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

