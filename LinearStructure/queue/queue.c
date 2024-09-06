#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct Queue {

    E *array;
    int capacity;
    int front, rear;

};
typedef struct Queue *array_queue;

_Bool is_empty(array_queue queue) {
    return queue->rear == queue->front;
}

_Bool init_queue(array_queue queue) {

    queue->array = malloc(sizeof(E) * 10);

    if (queue->array == NULL) return 0;

    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;

}

_Bool offer_queue(array_queue queue, E element) {

    if ((queue->rear+1) % queue->capacity == queue->front) return 0;

    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 1;

}

E poll_queue(array_queue queue) {

    queue->front = (queue->front+1) % queue->capacity;
    return queue->array[queue->front];

}

int size_queue(array_queue queue) {
    
    if (queue == NULL) return 0;

    if (queue->rear >= queue->front) return queue->rear - queue->front;
    else return queue->capacity - (queue->front - queue->rear);

}

E *find_value(array_queue queue, int index) {

    if (index < 0 || index >= size_queue(queue)) return NULL;

    int actual_index = (queue->front+1 + index) % queue->capacity;
    return &queue->array[actual_index];

}

int get_index(array_queue queue, E element) {

    for (int i = 0; i < size_queue(queue); ++i) {
        int actual_index = (queue->front+1 + i) % queue->capacity;
        if (queue->array[actual_index] == element) return i;
    }
    return -1;

}

_Bool delete_list(array_queue queue, int index) {

    int size = size_queue(queue);

    if (index < 0 || index >= size) return 0;

    for (int i = index; i < size-1; ++i) {
        int actual_index = (queue->front+1 + i) % queue->capacity;
        int next_index = (queue->front+1 + i + 1) % queue->capacity;
        queue->array[actual_index] = queue->array[next_index];
    }

    queue->rear = (queue->rear-1 + queue->capacity) % queue->capacity;
    return 1;

}

void print_queue(array_queue queue) {

    int i = queue->front;
    do {
        i = (i+1) % queue->capacity;
        printf("%d ", queue->array[i]);
    } while (i != queue->rear);

}

int main() {

    struct Queue queue;
    init_queue(&queue);
    for (int i = 0; i < 5; ++i) offer_queue(&queue, i*100);

    /*print_queue(&queue);

    printf("%d ", size_queue(&queue));

    printf("%d ", get_index(&queue, 300));

    printf("%d ", *find_value(&queue, 3));

    delete_list(&queue, 2);
    print_queue(&queue);*/

    while (!is_empty(&queue)) printf("%d ", poll_queue(&queue));

    return 0;

}
