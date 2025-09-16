#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef double stack_data;
#define STACK_DATA_FMT "%lf"

struct stack;
typedef struct stack stack;

stack* stack_create(void);
void stack_destroy(stack* stack);

bool stack_is_empty(stack* p_stack);
bool stack_push(stack* p_stack, stack_data value);
void stack_pop(stack* p_stack);
stack_data stack_peek(stack* p_stack);

void stack_print(stack* p_stack);

#endif // STACK_H

