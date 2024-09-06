#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct list_node {

    E element;
    struct list_node *next;

};
typedef struct list_node *Node;

_Bool is_empty(Node head) {
    return head->next == NULL;
}

void init_stack(Node head) {
    head->next = NULL;
}

_Bool push_stack(Node head, E element) {

    Node node = malloc(sizeof(struct list_node));

    if (node == NULL) return 0;

    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;

}

E pop_stack(Node head) {

    Node top = head->next;
    head->next = head->next->next;
    E e = top->element;
    free(top);
    return e;

}

int size_stack(Node head) {

    if (head == NULL) return 0;

    int count = 0;
    Node current = head->next;
    while (current != NULL) {
        ++count;
        current = current->next;
    }
    return count;

}

E find_value(Node head, int index) {

    if (index < 0) return 0;

    Node current = head->next;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        ++i;
    }
    return current->element;

}

int get_index(Node head, E value) {

    Node current = head->next;
    int index = 0;
    while (current != NULL) {
        if (current->element == value) return index;
        current = current->next;
        ++index;
    }
    return -1;

}

_Bool delete_list() { // TODO

    

}

void print_stack(Node head) {

    head = head->next;
    while (head) {
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");

}

int main() {

    struct list_node head;
    init_stack(&head);
    for (int i = 0; i < 5; ++i) push_stack(&head, i*100);

    /*print_stack(&head);

    printf("%d ", size_stack(&head));

    printf("%d ", find_value(&head, 1));

    int index = get_index(&head, 100);
    printf("%d", index);*/

    while (!is_empty(&head)) printf("%d ", pop_stack(&head));

    return 0;

}
