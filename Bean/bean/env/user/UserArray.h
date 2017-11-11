#pragma once
#ifndef BEAN_ENV_USER_USERARRAY_H
#define BEAN_ENV_USER_USERARRAY_H
#include <vector>
//#include <array>
#include <functional>
#include "../Object_.h"
class Object_;
/**
 * �z��̃��b�p�[.
 */
class UserArray : public Object_ {
public:
	UserArray();
	~UserArray();

	/**
	 * �x�N�g�����ЂƂÂI�u�W�F�N�g�֕ϊ����Ĕz��ŕԂ��܂�.
	 * @param v
	 * @param f
	 */
	template<typename T>
	static UserArray* fromVector(std::vector<T> v, std::function<Object_*(T)> f);

	/**
	 * ���̔z��̂��߂̃�������Ԃ��m�ۂ��܂�.
	 * @param length
	 */
	void alloc(int length);

	/**
	 * �w��ʒu�̗v�f��u�������܂�.
	 * @param index
	 * @param ref
	 */
	void set(int index, Object_* ref);

	/**
	 * �w��ʒu�̗v�f��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	Object_* const get(int index) const;
	
	/**
	 * �v�f����Ԃ��܂�.
	 * @return
	 */
	int getLength();

	// Object_ ����Čp������܂���
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
