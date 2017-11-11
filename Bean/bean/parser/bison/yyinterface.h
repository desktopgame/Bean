/**
 * @file yyinterface.h
 * @brief Flex/Bison�̔������b�p�[�ł��B
 */
#pragma once
#ifndef BEAN_PARSER_BISON_YYINTERFACE_H
#define BEAN_PARSER_BISON_YYINTERFACE_H
#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * �f�o�b�O�p�̊֐��ł�.
	 * �w��̃t�@�C������͂��ăc���[���o�͂��܂��B
	 * �R���p�C���X�^�b�N�͌Ăяo���O���Ăяo����� 0 �ł�.
	 * @param filePath
	 */
	int debug_yyparse(const char* filePath);

	/**
	 * yyparse���Ăяo���Č��ʂ�Ԃ������̃��\�b�h�ł�.
	 * �t�@�C�����I�[�v���o���Ȃ������ꍇ�ɂ͉�͂����Ɏ��s���܂��B
	 * @parma filePath
	 */
	int compile_yyparse(const char* filePath);

	/**
	 * ���������͌����ĉ�͂��܂�.
	 */
	int compile_yyparsestr(char *source);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_YYINTERFACE_H
