#pragma once
/**
 * @file mem.h
 * @brief メモリ管理のデバッグ用関数です。
 */
#ifndef BEAN_PARSER_BISON_MEMINTERFACE_H
#define BEAN_PARSER_BISON_MEMINTERFACE_H
#include <stdlib.h>

/**
 * mallocのラッパーです。
 * @param size
 */
void* mem_malloc(size_t size);

/**
 * freeのラッパーです。
 * @param v
 */
void mem_free(void* v);
#endif // !BEAN_PARSER_BISON_MEMINTERFACE_H
