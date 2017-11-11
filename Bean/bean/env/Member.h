#pragma once
#ifndef BEAN_ENV_MEMBER_H
#define BEAN_ENV_MEMBER_H
#include <memory>
#include <string>
#include "Modifier.h"
class Class;
using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
/**
 * フィールド、あるいはメソッドの基底クラスです.
 */
class Member {
public:
	Member(ClassSPtr const classz, Modifier modifier, const std::string& name);
	virtual ~Member() = 0;

	/**
	 * このメンバーの定義されているクラスを返します.
	 * @return
	 */
	ClassWPtr const getClass() const;

	/**
	 * 修飾子を返します.
	 * @return
	 */
	Modifier getModifier() const;

	/**
	 * このメンバーの名前を返します.
	 * @return
	 */
	std::string getName() const;

	/**
	 * このメンバーの所在を表す短い名前を返します.
	 * @return
	 */
	virtual std::string getLocation() = 0;
private:
	ClassWPtr classz;
	Modifier modifier;
	std::string name;
};
#endif // !BEAN_ENV_MEMBER_H


 
