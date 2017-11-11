#pragma once
#ifndef BEAN_ENV_USER_USERVECTOR_H
#define BEAN_ENV_USER_USERVECTOR_H
#include <vector>
#include "../Object_.h"
/**
 * �x�N�^�̃��b�p�[.
 */
class UserVector : public Object_ {
public:
	UserVector();
	~UserVector();

	// Object_ ����Čp������܂���
	Object_ * clone() override;

	/**
	 * �����ɗv�f��ǉ����܂�.
	 * @param obj
	 */
	void vadd(Object_* obj);

	/**
	 * �w��ʒu�̗v�f��u�������܂�.
	 * @param index
	 * @param obj
	 */
	void set(int index, Object_* obj);

	/**
	 * �w��ʒu�̗v�f��Ԃ��܂�.
	 */
	Object_* get(int index);

	/**
	 * �w��ʒu�ɗv�f��}�����܂�.
	 * @param index
	 * @param obj
	 */
	void insert(int index, Object_* obj);

	/**
	 * �w��̊֐��ł��̃x�N�^�[���\�[�g���܂�.
	 * @param sortF
	 */
	void sort(std::function<bool(Object_*, Object_*)> sortF);

	/**
	 * �w��ʒu�̗v�f���폜���܂�.
	 * @param index
	 */
	void removeAt(int index);

	/**
	 * �w��̗v�f���폜���܂�.
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * �擪�ɗv�f��ǉ����܂�.
	 * @param obj
	 */
	void push(Object_* obj);

	/**
	 * �擪�̗v�f��Ԃ��܂�.
	 * @return
	 */
	Object_* top();

	/**
	 * �����̗v�f��Ԃ��܂�.
	 * @return
	 */
	Object_* back();

	/**
	 * �擪�̗v�f���폜���܂�.
	 */
	void pop();

	/**
	 * �v�f����Ԃ��܂�.
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
