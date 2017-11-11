#pragma once
#ifndef BEAN_VISITOR_EXCEPTIONHANDLE_H
#define BEAN_VISITOR_EXCEPTIONHANDLE_H
#include <vector>
class Thread;
class Object_;
/**
 * ��O��ߑ�����C���^�[�t�F�C�X.
 */
class ExceptionHandle {
public:
	ExceptionHandle();
	virtual ~ExceptionHandle();
	/**
	 * ��O���ߑ������ƌĂяo����܂�.
	 * ���̃r�W�^�[���ȍ~�̏������X�L�b�v����悤�Ƀt���O��ON�ɂ��܂�.
	 */
	virtual void onException(Thread* t, Object_* e) = 0;

	/**
	 * ��O���L���b�`�����ƁA
	 * ������L���b�`�������[���K�w�̃n���h������Ăяo����܂��B
	 */
	virtual void onCatch() = 0;

	/**
	 * ��O�����o�͂��܂�.
	 * @param t
	 * @param e
	 */
	virtual void printException(Thread* t, Object_* e);
protected:
	/**
	 * ���̃n���h���̎q�v�f�ɂ���ɒʒm���󂯂�n���h�����K�v�Ȃ�ǉ����܂�.
	 * @param handle
	 */
	void addHandle(ExceptionHandle* handle);

	/**
	 * �w��̃n���h����ʒm���珜�O���܂�.
	 * @parma handle
	 */
	void removeHandle(ExceptionHandle* handle);

	/** 
	 * �ǉ����ꂽ�n���h���֒ʒm���s���܂�.
	 * @param t
	 * @param e
	 */
	void fire(Thread* t, Object_* e);
	std::vector<ExceptionHandle*> children;
};
#endif // !BEAN_VISITOR_EXCEPTIONHANDLE_H
