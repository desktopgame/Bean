#pragma once
/**
 * @file stack.h
 * @brief �X�^�b�N�B
 */
#ifndef BEAN_PARSER_BISON_STACK_H
#define BEAN_PARSER_BISON_STACK_H
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * �X�^�b�N�Ɋi�[����f�[�^�^�ł��B
	 * �ėp�R���e�i�Ƃ��邽�߂� void* ���g�p���܂��B
	 */
	typedef void* stack_item;
	/**
	 * �X�^�b�N�Ƃ��ċ@�\����\���̂ł�.
	 */
	typedef struct stack {
		stack_item value;
		struct stack* prev;
		struct stack* next;
	} stack;

	/**
	 * �X�^�b�N���쐬���܂��B
	 * ���̃��\�b�h�ō쐬�����X�^�b�N�� delete �ō폜���Ă��������B
	 * @return
	 */
	stack* stack_new();

	/**
	 * �X�^�b�N�̖����֗v�f��ǉ����܂��B
	 * @param val
	 * @param item
	 */
	void stack_push(stack* val, stack_item item);

	/**
	 * �X�^�b�N�̖����̗v�f��Ԃ��܂��B
	 * @param val
	 * @return
	 */
	stack_item stack_top(stack* val);

	/**
	 * �X�^�b�N�̖����̗v�f���̂ĂĕԂ��܂��B
	 * @param val
	 * @return
	 */
	stack_item stack_pop(stack* val);

	/**
	 * �X�^�b�N����ł��邩�ǂ�����Ԃ��܂��B
	 * @param val
	 * @return
	 */
	int stack_empty(stack* val);

	/**
	 * �X�^�b�N���폜���܂��B
	 * ���g�͍폜����܂���B
	 * @param val
	 */
	void stack_delete(stack* val);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_STACK_H
