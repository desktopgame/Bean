#pragma once
/**
 * @file modifier_type.h
 * @brief �A�N�Z�X�C���q��\�����ʎq�B
 */
#ifndef BEAN_PARSER_BISON_MODIFIER_H
#define BEAN_PARSER_BISON_MODIFIER_H
typedef enum modifier_type {
	mt_default,
	mt_public,
	mt_private,
	mt_protected,
	mt_static,
	mt_final,
	mt_native,
} modifier_type;
#endif // !BEAN_PARSER_BISON_MODIFIER_H
