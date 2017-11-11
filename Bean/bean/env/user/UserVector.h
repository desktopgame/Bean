#pragma once
#ifndef BEAN_ENV_USER_USERVECTOR_H
#define BEAN_ENV_USER_USERVECTOR_H
#include <vector>
#include "../Object_.h"
/**
 * ベクタのラッパー.
 */
class UserVector : public Object_ {
public:
	UserVector();
	~UserVector();

	// Object_ を介して継承されました
	Object_ * clone() override;

	/**
	 * 末尾に要素を追加します.
	 * @param obj
	 */
	void vadd(Object_* obj);

	/**
	 * 指定位置の要素を置き換えます.
	 * @param index
	 * @param obj
	 */
	void set(int index, Object_* obj);

	/**
	 * 指定位置の要素を返します.
	 */
	Object_* get(int index);

	/**
	 * 指定位置に要素を挿入します.
	 * @param index
	 * @param obj
	 */
	void insert(int index, Object_* obj);

	/**
	 * 指定の関数でこのベクターをソートします.
	 * @param sortF
	 */
	void sort(std::function<bool(Object_*, Object_*)> sortF);

	/**
	 * 指定位置の要素を削除します.
	 * @param index
	 */
	void removeAt(int index);

	/**
	 * 指定の要素を削除します.
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * 先頭に要素を追加します.
	 * @param obj
	 */
	void push(Object_* obj);

	/**
	 * 先頭の要素を返します.
	 * @return
	 */
	Object_* top();

	/**
	 * 末尾の要素を返します.
	 * @return
	 */
	Object_* back();

	/**
	 * 先頭の要素を削除します.
	 */
	void pop();

	/**
	 * 要素数を返します.
	 * @return
	 */
	int size();
	std::vector<Object_*> getVirtualField() override;
protected:
	void lazyLoading() override;
private:
	std::vector<Object_*> objects;
};
#endif // !BEAN_ENV_USER_USERVECTOR_H
