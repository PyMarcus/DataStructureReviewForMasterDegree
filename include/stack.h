//
// Created by Marcus on 16/03/2026.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// stack has FIFO operations
typedef struct {
    int *collection;
    size_t size;
    size_t capacity;
}Stack;

Stack* create_stack(size_t capacity);
void destroy_stack(Stack* stack);
bool is_full(Stack* stack);
bool is_empty(Stack* stack);
bool pop(Stack* stack, int* value);
bool push(Stack* stack, int value);
bool peek(Stack* stack, int* value);

#endif //DATASTRUCTURE_STACK_H