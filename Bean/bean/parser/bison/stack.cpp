#include "stack.h"
#include <stdlib.h>

//public
stack * stack_new() {
	stack* ret = (stack*)malloc(sizeof(stack));
	ret->prev = NULL;
	ret->next = NULL;
	ret->value = NULL;
	return ret;
}

void stack_push(stack * val, stack_item item) {
//	if (val->value == NULL) {
//		val->value = item;
//	} else {
		if (val->next != NULL) {
			stack_push(val->next, item);
		} else {
			stack* a = (stack*)malloc(sizeof(stack));
			val->next = a;
			a->prev = val;
			a->next = NULL;
			a->value = item;
		}
//	}
}

stack_item stack_top(stack * val) {
	if (val->next != NULL) {
		if (val->next->prev == NULL) {
			return val->value;
		}
		return stack_top(val->next);
	}
	return val->value;
}

stack_item stack_pop(stack * val) {
	if (val->next != NULL) {
		return stack_pop(val->next);
	}
	if (val->prev != NULL) {
		val->prev->next = NULL;
	}
	val->prev = NULL;
	stack_item ret = val->value;
	val->value = NULL;
	free(val);
	return ret;
}

int stack_empty(stack* val) {
	if (val->next == NULL) {
		return true;
	}
	return false;
}

void stack_delete(stack * val) {
	while (!stack_empty(val)) {
		stack_pop(val);
	}
	free(val);
}
