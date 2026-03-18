//
// Created by Marcus on 17/03/2026.
//

#include <stdio.h>
#include "queue.h"


Queue* create_queue() {
    Queue* queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void destroy_queue(Queue* queue) {
    Node* currentNode = queue->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode;
        currentNode = currentNode->next;
        free(nextNode);
    }
    free(queue);
}

int size(Queue* queue) {
    return queue->size;
}

static  bool is_empty(Queue* queue) {
    return queue->size == 0;
}

int peek_queue(Queue* queue, bool *status) {
    if (is_empty(queue)) {
        *status = false;
        return 0;
    };
    *status = true;
    return queue->head->value;
}

void enqueue(Queue* queue, int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (is_empty(queue)) {
        queue->head = node;
        queue->tail = queue->head;
    }else {
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }
    queue->size++;
}

int dequeue(Queue* queue, bool *status) {
    if (is_empty(queue)) {
        *status = false;
        return 0;
    }
    Node* node = queue->head;
    int value = node->value;

    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    }else {
        queue->head = queue->head->next;
    }

    free(node);

    *status = true;
    queue->size--;


    return value;
}
