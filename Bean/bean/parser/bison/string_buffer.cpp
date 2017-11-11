#include "string_buffer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//public
list* string_garbage_list = NULL;
void string_buffer_start_compile() {
	assert(string_garbage_list == NULL);
	string_garbage_list = list_new();
}

void string_buffer_link_object(buffer_ptr val) {
	assert(string_garbage_list != NULL);
	list_add(string_garbage_list, val);
}

void string_buffer_end_compile(BBOOL fail) {
	assert(string_garbage_list != NULL);
	if (fail == BTRUE) {
		list_delete_with_item(string_garbage_list, list_deleter_free);
	} else {
		list_delete(string_garbage_list);
	}
	string_garbage_list = NULL;
}

string_buffer * string_buffer_new() {
	string_buffer* st_buff = (string_buffer*)malloc(sizeof(string_buffer));
	st_buff->length = 0;
	st_buff->pointee = NULL;
	return st_buff;
}

void string_buffer_append(string_buffer * val, buffer_t t) {
	if (val->length == 0) {
		val->pointee = (buffer_ptr)malloc(sizeof(buffer_t) + 1);
		val->pointee[0] = t;
		val->pointee[1] = '\0';
	} else {
		buffer_ptr loc = (buffer_ptr)(malloc((sizeof(buffer_t) * val->length + 1) + 1));
		memset(loc, '\0', (sizeof(buffer_t) * val->length + 1) + 1);
		memcpy(
			loc, val->pointee, val->length * sizeof(buffer_t)
		);
		free(val->pointee);
		loc[val->length] = t;
		val->pointee = loc;
	}
	val->length++;
}

void string_buffer_append_str(string_buffer * val, buffer_ptr p) {
	for (int i = 0; i < strlen(p); i++) {
		string_buffer_append(val, p[i]);
	}
}

buffer_ptr string_buffer_clone(buffer_ptr src) {
#ifdef _MSC_VER
	buffer_ptr ret = _strdup(src);
#else
	buffer_ptr ret = strdup(src);
#endif // _MSC_VER
	string_buffer_link_object(ret);
	return ret;
}

int string_buffer_substr(buffer_ptr dst, buffer_ptr src, int offs, int len) {
	//URL:
	if (offs < 0 || len < 0 || len > strlen(src)) {
		return -1;
	}
	for (src += offs; *src != '\0' && len > 0; len--) {
		*dst++ = *src++;
	}
	*dst = '\0';
	return 0;
}

buffer_ptr string_buffer_substr_dynamic(const buffer_ptr src, int offs, int len) {
	buffer_t* buff = (buffer_t*)malloc((sizeof(buffer_t) * len) + 1);
	for (int i = offs; i < (offs + len); i++) {
		buff[i - offs] = src[i];
	}
	buff[len] = '\0';
	return buff;
}

void string_buffer_delete(string_buffer * val) {
	if (val != NULL) {
		free(val->pointee);
		free(val);
	}
}
