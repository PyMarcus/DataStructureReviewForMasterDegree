#include <stdio.h>
#include "queue.h"


int main(void) {

    Queue* queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);

    enqueue(queue, 3);

    enqueue(queue, 4);

    printf("Size of queue is %d\n", size(queue));

    bool peek_status = false;
    bool dequeue_status = true;

    int peek_result = peek_queue(queue, &peek_status);
    if (peek_status) printf("Peeking from queue is %d\n", peek_result);

    while (dequeue_status) {
        int temp = dequeue(queue, &dequeue_status);
        printf("Dequeuing from queue is %d\n", temp);
    }

    destroy_queue(queue);

    return 0;
}
