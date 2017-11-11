#pragma once
/**
 * @file assign_type
 * @brief 代入演算子の種類。
 */
#ifndef BEAN_PARSER_BISON_ASSIGN_TYPE_H
#define BEAN_PARSER_BISON_ASSIGN_TYPE_H

typedef enum  assign_type {
	ao_Assign = 1,
	ao_Add,
	ao_Sub,
	ao_Mul,
	ao_Div,
	ao_Mod,
} assign_type;
#endif // !BEAN_PARSER_BISON_ASSIGN_TYPE_H
