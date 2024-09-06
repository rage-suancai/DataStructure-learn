#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct LNode {

    E element;
    struct LNode *next;

};
typedef struct LNode *Node;

struct Queue {
    Node front, rear;
};
typedef struct Queue *linked_queue;

_Bool is_empty(linked_queue queue) {
    return queue->rear == queue->front;
}

_Bool init_queue(linked_queue queue) {

    Node node = malloc(sizeof(struct LNode));

    if (node == NULL) return 0;

    node->next = NULL;
    queue->front = queue->rear = node;
    return 1;

}

_Bool offer_queue(linked_queue queue, E element) {

    Node node = malloc(sizeof(struct LNode));

    if (node == NULL) return 0;
    node->next = NULL;

    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;

}

E poll_queue(linked_queue queue) {

    Node node = queue->front->next;
    E element = node->element;

    queue->front->next = node->next;
    if (queue->front == node) queue->rear = queue->front;
    free(node);
    return element;

}

int size_queue(linked_queue queue) {

    int size = 0;
    Node node = queue->front->next;
    while (node != NULL) {
        ++size;
        node = node->next;
    }
    return size;

}

E *find_value(linked_queue queue, int index) {

    if (index < 0) return NULL;

    int currentIndex = 0;
    Node node = queue->front->next;
    while (node != NULL && currentIndex < index) {
        ++currentIndex;
        node = node->next;
    }

    if (node == NULL) return NULL;
    return &node->element;

}

int get_index(linked_queue queue, E element) {

    int index = 0;
    Node node = queue->front->next;
    while (node != NULL) {
        if (node->element == element) return index;
        ++index;
        node = node->next;
    }
    return -1;

}

_Bool delete_queue(linked_queue queue, int index) {

    if (index < 0) return 0;

    int currentIndex = 0;
    Node prev = queue->front;
    Node node = queue->front->next;
    while (node != NULL && currentIndex < index) {
        ++currentIndex;
        prev = node;
        node = node->next;
    }

    if (node == NULL) return 0;

    prev->next = node->next;
    if (queue->rear == node) queue->rear = prev;
    free(node);
    return 1;

}

void print_queue(linked_queue queue) {

    Node node = queue->front->next;
    while (1) {
        printf("%d ", node->element);
        if (node == queue->rear) break;
        else node = node->next;
    }

}

int main() {

    struct Queue queue;
    init_queue(&queue);
    for (int i = 0; i < 5; ++i) offer_queue(&queue, i*100); 

    /*print_queue(&queue);

    printf("%d ", size_queue(&queue));

    printf("%d ", *find_value(&queue, 3));

    printf("%d ", get_index(&queue, 300));

    delete_queue(&queue, 3);
    print_queue(&queue);*/

    while (!is_empty(&queue)) printf("%d ", poll_queue(&queue));

    return 0;

}
