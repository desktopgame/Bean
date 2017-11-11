#pragma once
#ifndef BEAN_ENV_USER_USERARRAY_H
#define BEAN_ENV_USER_USERARRAY_H
#include <vector>
//#include <array>
#include <functional>
#include "../Object_.h"
class Object_;
/**
 * 配列のラッパー.
 */
class UserArray : public Object_ {
public:
	UserArray();
	~UserArray();

	/**
	 * ベクトルをひとつづつオブジェクトへ変換して配列で返します.
	 * @param v
	 * @param f
	 */
	template<typename T>
	static UserArray* fromVector(std::vector<T> v, std::function<Object_*(T)> f);

	/**
	 * この配列のためのメモリ空間を確保します.
	 * @param length
	 */
	void alloc(int length);

	/**
	 * 指定位置の要素を置き換えます.
	 * @param index
	 * @param ref
	 */
	void set(int index, Object_* ref);

	/**
	 * 指定位置の要素を返します.
	 * @param index
	 * @return
	 */
	Object_* const get(int index) const;
	
	/**
	 * 要素数を返します.
	 * @return
	 */
	int getLength();

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
	std::vector<Object_*> getVirtualField() override;
	UserArray* asUserArray() override;
protected:
private:
	std::vector<Object_*> elems;
//	std::array<Object_*> elems;
	int length;
};
#endif // !BEAN_ENV_USER_USERARRAY_H

template<typename T>
inline UserArray * UserArray::fromVector(std::vector<T> v, std::function<Object_*(T)> f) {
	UserArray* arr = new UserArray();
	arr->alloc(v.size());
	for (int i = 0; i < v.size(); i++) {
		arr->set(i, f(v.at(i)));
	}
	return arr;
}
