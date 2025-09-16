#include <stddef.h>

#include "stack.h"

int main(void) {
	stack* p_stack = stack_create();

	stack_print(p_stack);

	stack_push(p_stack, 1.0);
	stack_print(p_stack);

	stack_push(p_stack, 2.0);
	stack_print(p_stack);

	stack_push(p_stack, 3.0);
	stack_print(p_stack);

	stack_pop(p_stack);
	stack_print(p_stack);

	stack_push(p_stack, 4.0);
	stack_print(p_stack);

	while (!stack_is_empty(p_stack)) {
		stack_pop(p_stack);
		stack_print(p_stack);
	}

	stack_destroy(p_stack);

	return 0;
}

