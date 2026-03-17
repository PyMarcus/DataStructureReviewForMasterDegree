#include <stdio.h>
#include "stack.h"


int main(void) {
    Stack* stack = create_stack(6);
    printf("Stack created\n");

    printf("Stack is empty: %d\n",is_empty(stack));

    printf("stack is full: %d\n", is_full(stack));

    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);

    printf("Stack size: %llu\n", stack->size);
    int random_value = 0;
    peek(stack, &random_value);
    printf("Peek stack: %d\n", random_value);

    for (int i = 0; i < 6; i++) {
        if (is_empty(stack)) break;
        peek(stack, &random_value);
        printf("Peek stack: %d\n", random_value);

        pop(stack, &random_value);
        printf("Pop stack: %d\n", random_value);
    }

    destroy_stack(stack);
    printf("Stack destroyed\n");

    return 0;
}
