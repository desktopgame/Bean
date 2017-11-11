#pragma once
#ifndef BEAN_ENV_NEWMETHOD_H
#define BEAN_ENV_NEWMETHOD_H
#include "Method.h"
class Constructor_;
/**
 * �R���X�g���N�^�� Class.new �ŌĂԂ��߂̃��b�p�ł�.
 */
class NewMethod : public Method {
public:
	NewMethod(Constructor_* cons);
	~NewMethod();
	Object_* const execute(Object_* invoker, std::vector<Object_*> args, bool currentClassLoader) override;
private:
	Constructor_* cons;
};

#endif // !BEAN_ENV_NEWMETHOD_H

