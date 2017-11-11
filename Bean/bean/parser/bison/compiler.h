#pragma once
/**
 * @file compiler.h
 * @brief Bison�̏o�͐�B
 */
#ifndef BEAN_PARSER_BISON_COMPILER_H
#define BEAN_PARSER_BISON_COMPILER_H
#include "ast.h"
#include "stack.h"
#include "string_buffer.h"
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * Yacc/Flex �� ���̓��[�h.
	 */
	typedef enum input_mode {
		im_file,
		im_str
	} input_mode;
	/**
	 * Bison/Flex�̎��s������ێ�����\����.
	 * yyparse����Ă΂��e�A�N�V�����͂��̍\���̂� root �փm�[�h��ۑ����܂��B
	 */
	typedef struct compiler {
		string_buffer* string_literal;
		int row;
		int col;
		YYBString error_line;
		YYBString file_name;
		input_mode im;
		/**
		 * �t�B�[���h�ȊO�̏ꏊ��
		 * set get�����ꂽ�ꍇ�� IDENT �Ƃ��ĉ��߂��܂��B
		 */
		BBOOL parsing_field_now;
		ast* root;
	} compiler;
	static stack* compiler_stack;
/**
 * @param RET_TYPE	�߂�l�̌^
 * @param S_CH		�}�b�`���镶��(������)
 * @param L_CH		�}�b�`���镶��(�啶��)
 * @param FUNC_NAME	�ϊ��֐�(char*)
 */
#define CONVERT_FUNC_IMPL(RET_TYPE, S_CH, L_CH, FUNC_NAME)	buffer_ptr range = yytext;					\
															buffer_t last = range[strlen(range) - 1];	\
															RET_TYPE ret = 0;							\
															if (last == S_CH || last == L_CH) {			\
																int len = strlen(yytext);				\
																char* buff = string_buffer_substr_dynamic(yytext, 0, len - 1);	\
																ret = (RET_TYPE)FUNC_NAME(buff);								\
																compiler_conv_feedback(buff);									\
																free(buff);														\
															} else {															\
																compiler_conv_feedback(range);									\
																ret = (RET_TYPE)FUNC_NAME(range);								\
															}																	\
															return ret
	/**
	 * �R���p�C���X�^�b�N���쐬���܂��B
	 * �v���O�����̐擪�ň�x�����Ăяo���܂��B
	 */
	void init_compiler_stack();

	/**
	 * �R���p�C���X�^�b�N�֐V���ȃR���p�C�����v�b�V�����܂��B
	 * yyparse�̒��O�ŌĂяo���܂��B
	 */
	void push_compiler();

	/**
	 * �R���p�C���X�^�b�N�̖�����Ԃ��܂��B
	 * @return
	 */
	compiler* get_compiler();

	/**
	 * �R���p�C���X�^�b�N�����|�b�v���܂��B
	 * ����fail�� AST/������ �̔j���̂��߂Ɏg�p����܂��B
	 * @param fail Flex/Bison���G���[�I�������Ȃ�true
	 */
	void pop_compiler(BBOOL fail);

	/**
	 * �R���p�C���X�^�b�N���폜���܂��B
	 * �v���O�����̍Ō�ň�x�����Ăяo���܂��B
	 */
	void destroy_compiler_stack();


	/**
	 * ���݂̃R���p�C���ŕ�����o�b�t�@���N���A���܂��B
	 * �����񃊃e���� " �𔭌�����ƌĂяo����܂��B
	 */
	void compiler_cur_clear_string_buffer();

	/**
	 * ���݂̃R���p�C���̕�����o�b�t�@�ֈꕶ���ǉ����܂��B
	 * @param ch
	 */
	void compiler_cur_append_string_buffer(YYBChar ch);

	/**
	 * ���݂̃R���p�C���̕�����o�b�t�@��AST�֊Ҍ����܂��B
	 * @return
	 */
	ast* compiler_cur_reduce_string_buffer();

	/**
	 * ���݂̃R���p�C���Ńt�B�[���h��͒��t���O��ON�ɂ��܂��B
	 */
	void compiler_cur_parsing_field_start();

	/**
	 * ���݂̃R���p�C���Ńt�B�[���h��͒��t���O��OFF�ɂ��܂��B
	 */
	void compiler_cur_parsing_field_end();

	/**
	 * ���݂̃R���p�C���̃t�B�[���h��͒��t���O��Ԃ��܂��B
	 * @return
	 */
	BBOOL compiler_cur_parsing_field();

	/**
	 * ���݂̃R���p�C���ŗ�ʒu����i�߂܂��B
	 * �G���[���b�Z�[�W�̂��߂Ɏg�p����܂��B
	 */
	void compiler_cur_nextcolumn();

	/**
	 * ���݂̃R���p�C���ōs�ʒu����i�߂܂��B
	 * �G���[���b�Z�[�W�̂��߂Ɏg�p����܂��B
	 */
	void compiler_cur_nextline();

	/**
	 * ���݂̃R���p�C���ŃG���[�����������s�̕�������L�^���܂��B
	 * @param str
	 */
	void compiler_cur_set_errorline(YYBString str);


	/**
	 * �w��̃R���p�C���ŕ�����o�b�t�@���N���A���܂��B
	 * �����񃊃e���� " �𔭌�����ƌĂяo����܂��B
	 * @param com
	 */
	void compiler_clear_string_buffer(compiler* com);

	/**
	 * �w��̃R���p�C���̕�����o�b�t�@�ֈꕶ���ǉ����܂��B
	 * @param com
	 * @param ch
	 */
	void compiler_append_string_buffer(compiler* com, YYBChar ch);

	/**
	 * �w��̃R���p�C���̕�����o�b�t�@��AST�֊Ҍ����܂��B
	 * @param com
	 * @return
	 */
	ast* compiler_reduce_string_buffer(compiler* com);

	/**
	 * �w��̃R���p�C���Ńt�B�[���h��͒��t���O��ON�ɂ��܂��B
	 * @param com
	 */
	void compiler_parsing_field_start(compiler* com);

	/**
	 * �w��̃R���p�C���Ńt�B�[���h��͒��t���O��OFF�ɂ��܂��B
	 * @param com
	 */
	void compiler_parsing_field_end(compiler* com);

	/**
	 * �w��̃R���p�C���ŗ�ʒu����i�߂܂��B
	 * �G���[���b�Z�[�W�̂��߂Ɏg�p����܂��B
	 * @param com
	 */
	void compiler_nextcolumn(compiler* com);

	/**
	 * �w��̃R���p�C���ōs�ʒu����i�߂܂��B
	 * �G���[���b�Z�[�W�̂��߂Ɏg�p����܂��B
	 * @param com
	 */
	void compiler_nextline(compiler* com);

	/**
	 * �w��̃R���p�C���ŃG���[�����������s�̕�������L�^���܂��B
	 * @param com
	 * @param str
	 */
	void compiler_set_errorline(compiler* com, YYBString str);

	
	/**
	 * ������� short �^�֕ϊ����܂��B
	 * �����ɂ� s �������� S ��z�u�o���܂��B
	 * @param yytext
	 * @return
	 */
	short compiler_char_to_short(char* yytext);

	/**
	 * ������� int �^�֕ϊ����܂��B
	 * �����ɂ� i �������� I ��z�u�o���܂��B
	 * @param yytext
	 * @return
	 */
	int compiler_char_to_int(char* yytext);


	/**
	 * ������� long �^�֕ϊ����܂��B
	 * �����ɂ� l �������� L ��z�u�o���܂��B
	 * @param yytext
	 * @return
	 */
	long compiler_char_to_long(char* yytext);


	/**
	 * ������� float �^�֕ϊ����܂��B
	 * �����ɂ� f �������� F ��z�u�o���܂��B
	 * @param yytext
	 * @return
	 */
	float compiler_char_to_float(char* yytext);

	/**
	 * ������� double �^�֕ϊ����܂��B
	 * �����ɂ� d �������� D ��z�u�o���܂��B
	 * @param yytext
	 * @return
	 */
	double compiler_char_to_double(char* yytext);


	/**
	 * �Ăяo���Ă������N����܂���B
	 * @param text
	 */
	void compiler_conv_feedback(char* text);

	/**
	 * ������� int �^�֕ϊ����܂��B
	 * @param yytext
	 * @return
	 */
	int compiler_char_to_int_nonoise(char* yytext);

	/**
	 * ������� double �^�֕ϊ����܂��B
	 * @param yytext
	 * @return
	 */
	double compiler_char_to_double_nonoise(char* yytext);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_COMPILER_H
