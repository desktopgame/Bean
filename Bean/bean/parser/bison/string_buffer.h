#pragma once
/**
 * @file string_buffer.h
 * @brief ������̃o�b�t�@�[�ł��B
 */
#ifndef BEAN_PRASER_BISON_STRING_BUFFER_H
#define BEAN_PRASER_BISON_STRING_BUFFER_H
#include "bool.h"
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * string_buffer�Ɋi�[���镶���̌^�ł��B
	 */
	typedef char buffer_t;

	/**
	 * ��q�̕����̔z��ł��B
	 */
	typedef char* buffer_ptr;

	/**
	 * ������̃R���e�i�ł��B
	 */
	typedef struct string_buffer {
		/**
		 * malloc�ɂ���ē��I�Ɋm�ۂ��ꂽ�����̔z��ł��B
		 * #apend, #append_str �ȊO�̕��@�ł����ύX����ꍇ�A
		 * length���Ăяo�����ŏC������K�v������܂��B
		 */
		buffer_ptr pointee;
		/**
		 * ���݂̃o�b�t�@�̕����̒�����\���܂��B
		 * �����̃[�������͂���Ɋ܂܂�܂���B
		 */
		int length;
	} string_buffer;
	/**
	 * �t�@�C���̉�͂��J�n�����Ƃ��� compiler ���Ăяo����܂��B
	 * �S�Ă̕������AST�ɕ�܂���邱�Ƃɂ��AAST�̍폜���Ɉꏏ�ɍ폜����܂����A
	 * Flex/Bison���G���[��񍐂���ꍇ�ɂ͈قȂ�܂��B
	 * ���̏ꍇ�ł͍쐬���ꂽ�����񂪃��������[�N���N�������߁A
	 * �܂��R���p�C���O�ɖ����I�ɂ��̃��\�b�h���Ăяo���܂��B
	 * (���l�ɁA�R���p�C����ɂ� end_compile ���Ăяo���܂��B)
	 * ���̃��\�b�h���Ă΂��ƁA����ȍ~�� clone �͑S�ăO���[�o���ȃ��X�g�֒ǉ�����܂��B
	 * end_compile�̌Ăяo���ł͂��̃��X�g���J�����܂����A
	 * end_compile�̈����œn�����R���p�C������(fail=true�Ȃ�G���[)
	 * �ɂ�菈�����قȂ�܂��B
	 * �������Ă���ꍇ�ɂ͏]���ʂ�AST����������폜���܂����A
	 * ���s���Ă���ꍇ�ɂ� end_compile �� u.string_value ���폜���܂��B
	 */
	void string_buffer_start_compile();
	/**
	 * �w��̕���������X�g�֕R�Â��܂��B
	 * end_compile�̌Ăяo�����ɍ폜����܂��B
	 * @parma val
	 */
	void string_buffer_link_object(buffer_ptr val);

	/**
	 * ���X�g�ɕR�Â���ꂽ�I�u�W�F�N�g���폜���܂�.
	 * @param fail ���s�Ȃ�true.
	 */
	void string_buffer_end_compile(BBOOL fail);

	/**
	 * �o�b�t�@���쐬���܂��B
	 * ���̃��\�b�h�ō쐬�����o�b�t�@�[�� delete �ō폜���Ă��������B
	 * @return
	 */
	string_buffer* string_buffer_new();

	/**
	 * �o�b�t�@�Ɉꕶ���t�������܂��B
	 * @parma val
	 * @param t
	 */
	void string_buffer_append(string_buffer* val, buffer_t t);

	/**
	 * p �̒��g���R�s�[���ăo�b�t�@�֘A�����܂��B
	 * @param val
	 * @param p
	 */
	void string_buffer_append_str(string_buffer* val, buffer_ptr p);

	/**
	 * src�𕡐����ĕԂ��܂��B
	 * ���̂Ƃ������͓��I�Ɋm�ۂ���܂����A���X�g�ɕR�Â�����̂�
	 * �Ăяo�����ō폜����K�v�͂���܂���B
	 * @param src
	 * @return
	 */
	buffer_ptr string_buffer_clone(buffer_ptr src);

	/**
	 * �����񂩂�w��͈̔͂�؂�o���܂�.
	 * �R���p�C�����ɐ؂�o�����������܂�Ȃ��ꍇ�ɂ� dynamic ���g�p���Ă��������B
	 * @param dst
	 * @param src
	 * @param offs
	 * @param len
	 */
	int string_buffer_substr(buffer_ptr dst, buffer_ptr src, int offs, int len);

	/**
	 * �����񂩂�w��͈̔͂�؂�o���܂�.
	 * @param src
	 * @param offs
	 * @param len
	 */
	buffer_ptr string_buffer_substr_dynamic(const buffer_ptr src, int offs, int len);

	/**
	 * val ���J�����܂��B
	 * @param val
	 */
	void string_buffer_delete(string_buffer* val);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PRASER_BISON_STRING_BUFFER_H
