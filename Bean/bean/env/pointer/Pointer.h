#pragma once
#ifndef BEAN_ENV_POINTER_POINTER_H
#define BEAN_ENV_POINTER_POINTER_H
#include <memory>
#include <string>
class Object_;
class Pointer;
using PointerSPtr = std::shared_ptr<Pointer>;
using PointerWPtr = std::weak_ptr<Pointer>;
/**
 * オブジェクトの格納先.
 */
class Pointer {
public:
	Pointer();
	virtual ~Pointer() = 0;
	/**
	 * 値へ委譲します.
	 */
	Object_* operator->();

	/**
	 * 値を上書きします.
	 * @param value
	 */
	virtual void setValue(Object_* obj) = 0;

	/**
	 * 値を返します.
	 * @return
	 */
	virtual Object_* getValue() = 0;

	/**
	 * 代入可能ならtrue.
	 * @return
	 */
	virtual bool isAssignable() = 0;

	/**
	 * この変数の所在を表します.
	 * @return
	 */
	virtual std::string getLocation() = 0;
private:
};
#endif // !BEAN_ENV_POINTER_POINTER_H
