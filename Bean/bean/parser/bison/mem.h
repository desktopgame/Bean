#pragma once
/**
 * @file mem.h
 * @brief �������Ǘ��̃f�o�b�O�p�֐��ł��B
 */
#ifndef BEAN_PARSER_BISON_MEMINTERFACE_H
#define BEAN_PARSER_BISON_MEMINTERFACE_H
#include <stdlib.h>

/**
 * malloc�̃��b�p�[�ł��B
 * @param size
 */
void* mem_malloc(size_t size);

/**
 * free�̃��b�p�[�ł��B
 * @param v
 */
void mem_free(void* v);
#endif // !BEAN_PARSER_BISON_MEMINTERFACE_H
