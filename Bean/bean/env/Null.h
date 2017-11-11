#pragma once
#ifndef BEAN_ENV_NULL_H
#define BEAN_ENV_NULL_H
#include "Object_.h"
/**
 * nullŒ^‚Å‚·.
 */
class Null : public Object_ {
public:
	Null(const Null&) = delete;
	Null& operator=(const Null&) = delete;
	Null(Null&&) = delete;
	Null& operator=(Null&&) = delete;
	/**
	 * —Bˆê‚ÌƒCƒ“ƒXƒ^ƒ“ƒX‚ğ•Ô‚µ‚Ü‚·.
	 * @return
	 */
	static Null* const getInstance() {
		static Null inst;
		return &inst;
	}
	// Object_ ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	Object_ * clone() override;
	Object_ * add(Object_ * right) override;
	Object_ * sub(Object_ * right) override;
	Object_ * mul(Object_ * right) override;
	Object_ * div(Object_ * right) override;
	Object_ * mod(Object_ * right) override;
	Object_ * equals(Object_ * right) override;
	void dump() override;
	bool isSingleton() override;
protected:
	void lazyLoading() override;
private:
	Null();
	~Null();
};
#endif // !BEAN_ENV_NULL_H


