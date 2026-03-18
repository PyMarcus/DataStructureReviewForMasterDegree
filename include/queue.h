//
// Created by Marcus on 17/03/2026.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#pragma once


#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    size_t size;
} Queue;

Queue* create_queue();
void destroy_queue(Queue* queue);
int size(Queue* queue);
int peek_queue(Queue* queue, bool *status);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue, bool *status);


#endif //DATASTRUCTURE_QUEUE_H