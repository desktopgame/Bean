#pragma once
#ifndef BEAN_PARSER_BISON_QUEUE_H
#define BEAN_PARSER_BISON_QUEUE_H 
typedef void* queue_item;
typedef struct queue {
	queue_item value;
	int length;
} queue;
#endif