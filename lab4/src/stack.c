#include "stack.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stack_node {
	stack_data value;
	struct stack_node* p_next;
} stack_node;

typedef struct stack {
	stack_node* p_top;
} stack;

stack* stack_create(void) {
	stack* new_stack = malloc(sizeof(stack));

	if (new_stack == NULL) {
		return NULL;
	}
	
	new_stack->p_top = NULL;

	return new_stack;
}

void stack_destroy(stack* stack) {
	free(stack);
}

stack_node* stack_create_node(stack_data value) {
	stack_node* new_node = malloc(sizeof(stack_node));

	if (new_node == NULL) {
		return NULL;
	}

	new_node->value = value;
	new_node->p_next = NULL;
	
	return new_node;
}

bool stack_is_empty(stack* p_stack) {
	return p_stack->p_top == NULL;
}

bool stack_push(stack* p_stack, stack_data value) {
	stack_node* new_node = stack_create_node(value);

	if (new_node == NULL) {
		return false;
	}

	new_node->p_next = p_stack->p_top;
	p_stack->p_top = new_node;

	return true;
}

void stack_pop(stack* p_stack) {
	stack_node* p_cur_head = p_stack->p_top;
	stack_node* p_new_head = p_cur_head->p_next;

	free(p_cur_head);
	p_stack->p_top = p_new_head;
}

stack_data stack_peek(stack* p_stack) {
	return p_stack->p_top->value;
}

void stack_print(stack* p_stack) {
	stack_node* p_cur = p_stack->p_top;

	while (p_cur != NULL) {
		printf(STACK_DATA_FMT ", ", p_cur->value);

		p_cur = p_cur->p_next;
	}

	puts("");
}

