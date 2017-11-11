#include "list.h"
#include <assert.h>
#include <stdlib.h>
//protot type
list_item p__list_getAt(list* val, int offs, int index);
int p__list_size(list* val, int index);

//public method
list * list_new() {
	list* li = (list*)malloc(sizeof(list));
	li->prev = NULL;
	li->next = NULL;
	li->value = NULL;
	li->size = (int*)malloc(sizeof(int));
	*li->size = 0;
	return li;
}

void list_add(list * val, list_item item) {
	if (val->next == NULL) {
		val->next = (list*)malloc(sizeof(list));
		val->next->size = val->size;
		val->next->prev = val;
		val->next->next = NULL;
		val->next->value = item;
		(*val->size)++;
	} else {
		list_add(val->next, item);
	}
}

void list_add_all(list * dst, list * src) {
	for (int i = 0; i < *src->size; i++) {
		list_add(dst, list_getAt(src, i));
	}
}

list_item list_remove(list * val, int index) {
	int offset = -1;
	list* root = val;
	(*val->size)--;
	while (offset != index) {
		root = root->next;
		offset++;
	}
	//前の要素がある
	if (root->prev != NULL) {
		//次の要素がある
		if (root->next != NULL) {
			root->prev->next = root->next->next;
			root->next->prev = root->prev;
		//ない
		} else {
			root->prev->next = NULL;
		}
	//前の要素がない
	} else {
		//次の要素がある
		if (root->next != NULL) {
			root->next->prev = NULL;
		//ない
		} else {
			//配列外アクセス
			assert(false);
		}
	}
	list_item ret = root->value;
	free(root);
	return ret;
}

list_item list_getAt(list * val, int index) {
	int offs = 0;
	if (index == 0) {
		if (val->next == NULL) return NULL;
		return val->next->value;
	}
	return list_getAt(val->next, index - 1);
}

int list_empty(list * val) {
	if (val->next != NULL) {
		return false;
	}
	return true;
}

int list_size(list * val) {
	return *val->size;
//	return p__list_size(val, 0);
}

void list_delete_with_item(list * val, list_element_deleter deleter) {
	if (val->next != NULL) {
		list_delete_with_item(val->next, deleter);
		val->next == NULL;
	}
	if (val->value != NULL) {
		deleter(val->value);
		val->value = NULL;
	}
	if (val->prev == NULL) {
		free(val->size);
	}
	free(val);
}

void list_delete(list * val) {
	list_delete_with_item(val, list_deleter_non_delete);
}

void list_deleter_non_delete(list_item item) {
	/*
		空
		デリートは呼び出し側で行います
	*/
}

void list_deleter_free(list_item item) {
	free(item);
}

//private
list_item p__list_getAt(list* val, int offs, int index) {
	list* li = val->next;
	if (li == NULL) {
		return NULL;
	}
	list* temp = li;
	list* root = li;
	while (offs != 0) {
		temp = root;
		root = root->next;
	}
	return temp->value;
}

int p__list_size(list* val, int index) {
	if (val->next != NULL) {
		p__list_size(val->next, index + 1);
	}
	return index;
}