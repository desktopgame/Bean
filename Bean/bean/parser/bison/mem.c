#include "mem.h"

//public
void* mem_malloc(size_t s) {
	void* ret = malloc(s);
	return ret;
}

void mem_free(void* v) {
	free(v);
}