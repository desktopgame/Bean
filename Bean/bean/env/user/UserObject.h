#pragma once
#ifndef BEAN_ENV_USER_USEROBJECT_H
#define BEAN_ENV_USER_USEROBJECT_H
#include "../Object_.h"
/**
 * ���[�U�ɂ���Ē�`���ꂽ�^�ł�.
 */
class UserObject : public Object_ {
public:
	UserObject(ClassSPtr classz);
	~UserObject();

	// Object_ ����Čp������܂���
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
	void dump() override;
	UserObject* asUserObject() override;
private:
	Object_* evalImpl(Object_* right, std::string name);
};
#endif // !BEAN_ENV_USER_USEROBJECT_H


