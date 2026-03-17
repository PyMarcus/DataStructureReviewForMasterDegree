//
// Created by Marcus on 16/03/2026.
//stack
#include "stack.h"

Stack* create_stack(size_t capacity) {
    if (capacity <= 0) {
        printf("Capacity must be greater than 0");
        return NULL;
    }

    // create a stack in the heap memory.
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL) return NULL;

    stack->collection = (int*)malloc(sizeof(int) * capacity);
    if (stack->collection == NULL) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack* stack) {
    free(stack->collection);
    free(stack);
}

bool is_full(Stack* stack) {
    return stack->size >= stack->capacity;
}

bool is_empty(Stack* stack) {
    return stack->size == 0;
}

bool pop(Stack* stack, int* value) {
    if (is_empty(stack)) return false;

    *value = stack->collection[stack->size - 1];
    stack->collection[stack->size - 1] = 0;
    stack->size--;

    return true;
}

bool push(Stack* stack, int value) {
    if (is_full(stack)) return false;

    stack->collection[stack->size] = value;
    stack->size++;

    return true;
}

bool peek(Stack* stack, int* value) {
    if (is_empty(stack)) return false;

    *value = stack->collection[stack->size - 1];

    return true;
}