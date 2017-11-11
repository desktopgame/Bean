#pragma once
#ifndef BEAN_ENV_TNUMERIC_H
#define BEAN_ENV_TNUMERIC_H
#include <functional>
#include "Numeric.h"
class String;
class Object_;
/**
 * 演算可能な数値型の総称型です.
 * このクラスはNumric.h以外からインクルードされないようにしてください。
 * このクラスの生成にはNumeric::newXXXを使用します。
 */
template<typename T>
class TNumeric : public Numeric {
public:

	TNumeric(T value);
	~TNumeric();
	short getCShort() override;
	int getCInt() override;
	long getCLong() override;
	float getCFloat() override;
	double getCDouble() override;
	// Numeric を介して継承されました
	Object_ * clone() override;
	Object_ * add(Object_ * right) override;
	Object_ * sub(Object_ * right) override;
	Object_ * mul(Object_ * right) override;
	Object_ * div(Object_ * right) override;
	Object_ * mod(Object_ * right) override;
	Object_ * equals(Object_ * right) override;
	Object_ * biggest(Object_ * right) override;
	Object_ * e_biggest(Object_ * right) override;
	Object_ * smallest(Object_ * right) override;
	Object_ * e_smallest(Object_ * right) override;
	void increment() override;
	void decrement() override;
	std::string toString() override;
	String* toString(Object_* o);
	bool isZero() override;
	void dump() override;

	Object_ * addShort(PShort * right);
	Object_ * subShort(PShort * right);
	Object_ * mulShort(PShort * right);
	Object_ * divShort(PShort * right);
	Object_ * modShort(PShort * right);
	Object_ * equalsShort(PShort * right);
	Object_ * biggestShort(PShort * right);
	Object_ * e_biggestShort(PShort * right);
	Object_ * smallestShort(PShort * right);
	Object_ * e_smallestShort(PShort * right);

	Object_ * addInt(PInteger * right);
	Object_ * subInt(PInteger * right);
	Object_ * mulInt(PInteger * right);
	Object_ * divInt(PInteger * right);
	Object_ * modInt(PInteger * right);
	Object_ * equalsInt(PInteger * right);
	Object_ * biggestInt(PInteger * right);
	Object_ * e_biggestInt(PInteger * right);
	Object_ * smallestInt(PInteger * right);
	Object_ * e_smallestInt(PInteger * right);

	Object_* addLong(PLong* right);
	Object_* subLong(PLong* right);
	Object_* mulLong(PLong* right);
	Object_* divLong(PLong* right);
	Object_* modLong(PLong* right);
	Object_* equalsLong(PLong* right);
	Object_* biggestLong(PLong* right);
	Object_* e_biggestLong(PLong* right);
	Object_* smallestLong(PLong* right);
	Object_* e_smallestLong(PLong* right);

	Object_ * addFloat(PFloat * right);
	Object_ * subFloat(PFloat * right);
	Object_ * mulFloat(PFloat * right);
	Object_ * divFloat(PFloat * right);
	Object_ * modFloat(PFloat * right);
	Object_ * equalsFloat(PFloat * right);
	Object_ * biggestFloat(PFloat * right);
	Object_ * e_biggestFloat(PFloat * right);
	Object_ * smallestFloat(PFloat * right);
	Object_ * e_smallestFloat(PFloat * right);

	Object_* addDouble(PDouble* right);
	Object_* subDouble(PDouble* right);
	Object_* mulDouble(PDouble* right);
	Object_* divDouble(PDouble* right);
	Object_* modDouble(PDouble* right);
	Object_* equalsDouble(PDouble* right);
	Object_* biggestDouble(PDouble* right);
	Object_* e_biggestDouble(PDouble* right);
	Object_* smallestDouble(PDouble* right);
	Object_* e_smallestDouble(PDouble* right);

	/**
	 * 値を返します.
	 * @return
	 */
	T getValue();
protected:
	void lazyLoading() override;
private:
	void typespec();
	Object_* cast(Object_* right, std::function<Object_*(Numeric*)> f);
	Object_* this_cast(Object_* right, std::function<Object_*(Numeric*, TNumeric<T>*)> f);
protected:
	T value;
};
#include "TNumericDefaults.h"
#include "TNumericDouble.h"
#include "TNumericFloat.h"
#include "TNumericImpl.h"
#include "TNumericInt.h"
#include "TNumericLong.h"
#include "TNumericShort.h"
#endif // !BEAN_ENV_TNUMERIC_H


