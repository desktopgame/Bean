#pragma once
#ifndef BEAN_ENV_NUMERIC_H
#define BEAN_ENV_NUMERIC_H
#include <memory>
#include <string>
#include "Object_.h"
#include "Reference.h"
using ClassSPtr = std::shared_ptr<Class>;
//TNumeric<T> の前方宣言
template<typename T>
class TNumeric;
//TNumericの別名
using PShort = TNumeric<short>;
using PInteger = TNumeric<int>;
using PLong = TNumeric<long>;
using PFloat = TNumeric<float>;
using PDouble = TNumeric<double>;
/**
 * 演算可能な数値型の基底クラスです.
 */
class Numeric : public Object_, public Reference {
public:
	Numeric(ClassSPtr classz);
	virtual ~Numeric();
	
	/**
	 * TNumeric<short>を生成して返します.
	 * @param val
	 * @return 
	 */
	static Numeric* newShort(short val);

	/**
	 * TNumeric<int>を生成して返します.
	 * @param val
	 * @return 
	 */
	static Numeric* newInteger(int val);

	/**
	 * TNumeric<long>を生成して返します.
	 * @param val
	 * @return 
	 */
	static Numeric* newLong(long val);

	/**
	 * TNumeric<float>を生成して返します.
	 * @param val
	 * @return 
	 */
	static Numeric* newFloat(float val);

	/**
	 * TNumeric<double>を生成して返します.
	 * @param val
	 * @return 
	 */
	static Numeric* newDouble(double val);

	/**
	 * Cの型で返します.
	 */
	virtual short getCShort() = 0;

	/**
	 * Cの型で返します.
	 * @return
	 */
	virtual int getCInt() = 0;

	/**
	* Cの型で返します.
	* @return
	*/
	virtual long getCLong() = 0;

	/**
	 * Cの型で返します.
	 * @return
	 */
	virtual float getCFloat() = 0;

	/**
	 * Cの型で返します.
	 * @return
	 */
	virtual double getCDouble() = 0;

	Numeric* asNumeric() override;

	// Object_ を介して継承されました
	virtual Object_ * clone() = 0;
	virtual Object_ * add(Object_ * right) = 0;
	virtual Object_ * sub(Object_ * right) = 0;
	virtual Object_ * mul(Object_ * right) = 0;
	virtual Object_ * div(Object_ * right) = 0;
	virtual Object_ * mod(Object_ * right) = 0;
	virtual Object_ * equals(Object_ * right) = 0;
	virtual Object_ * biggest(Object_ * right) = 0;
	virtual Object_ * e_biggest(Object_ * right) = 0;
	virtual Object_ * smallest(Object_ * right) = 0;
	virtual Object_ * e_smallest(Object_ * right) = 0;
	
	virtual Object_ * addShort(PShort * right) = 0;
	virtual Object_ * subShort(PShort * right) = 0;
	virtual Object_ * mulShort(PShort * right) = 0;
	virtual Object_ * divShort(PShort * right) = 0;
	virtual Object_ * modShort(PShort * right) = 0;
	virtual Object_ * equalsShort(PShort * right) = 0;
	virtual Object_ * biggestShort(PShort * right) = 0;
	virtual Object_ * e_biggestShort(PShort * right) = 0;
	virtual Object_ * smallestShort(PShort * right) = 0;
	virtual Object_ * e_smallestShort(PShort * right) = 0;

	virtual Object_* addInt(PInteger* right) = 0;
	virtual Object_* subInt(PInteger* right) = 0;
	virtual Object_* mulInt(PInteger* right) = 0;
	virtual Object_* divInt(PInteger* right) = 0;
	virtual Object_* modInt(PInteger* right) = 0;
	virtual Object_* equalsInt(PInteger* right) = 0;
	virtual Object_* biggestInt(PInteger* right) = 0;
	virtual Object_* e_biggestInt(PInteger* right) = 0;
	virtual Object_* smallestInt(PInteger* right) = 0;
	virtual Object_* e_smallestInt(PInteger* right) = 0;

	virtual Object_* addLong(PLong* right) = 0;
	virtual Object_* subLong(PLong* right) = 0;
	virtual Object_* mulLong(PLong* right) = 0;
	virtual Object_* divLong(PLong* right) = 0;
	virtual Object_* modLong(PLong* right) = 0;
	virtual Object_* equalsLong(PLong* right) = 0;
	virtual Object_* biggestLong(PLong* right) = 0;
	virtual Object_* e_biggestLong(PLong* right) = 0;
	virtual Object_* smallestLong(PLong* right) = 0;
	virtual Object_* e_smallestLong(PLong* right) = 0;

	virtual Object_* addFloat(PFloat* right) = 0;
	virtual Object_* subFloat(PFloat* right) = 0;
	virtual Object_* mulFloat(PFloat* right) = 0;
	virtual Object_* divFloat(PFloat* right) = 0;
	virtual Object_* modFloat(PFloat* right) = 0;
	virtual Object_* equalsFloat(PFloat* right) = 0;
	virtual Object_* biggestFloat(PFloat* right) = 0;
	virtual Object_* e_biggestFloat(PFloat* right) = 0;
	virtual Object_* smallestFloat(PFloat* right) = 0;
	virtual Object_* e_smallestFloat(PFloat* right) = 0;

	virtual Object_* addDouble(PDouble* right) = 0;
	virtual Object_* subDouble(PDouble* right) = 0;
	virtual Object_* mulDouble(PDouble* right) = 0;
	virtual Object_* divDouble(PDouble* right) = 0;
	virtual Object_* modDouble(PDouble* right) = 0;
	virtual Object_* equalsDouble(PDouble* right) = 0;
	virtual Object_* biggestDouble(PDouble* right) = 0;
	virtual Object_* e_biggestDouble(PDouble* right) = 0;
	virtual Object_* smallestDouble(PDouble* right) = 0;
	virtual Object_* e_smallestDouble(PDouble* right) = 0;

	virtual std::string toString() = 0;
	/**
	 * この値が0ならtrueを返します.
	 * @return
	 */
	virtual bool isZero() = 0;
	bool isPrimitive() override;
private:

};
#endif // !BEAN_ENV_NUMERIC_H

