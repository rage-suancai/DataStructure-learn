#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct list_node {

    E element;
    struct list_node *next;

};
typedef struct list_node *Node;

void init_list(Node node) {
    node->next = node;
}

_Bool insert_list(Node head, E element, int index) {

    if (index < 0) return 0;

    Node current = head;
    while (--index > 0) {
        current = current->next;
        if (current == head) return 0;
    }

    Node node = malloc(sizeof (struct list_node));

    if (node == NULL) return 0;
    
    node->element = element;
    node->next = current->next;
    current->next = node;
    return 1;

}

int size_list(Node head) {

    if (head == NULL) return 0;

    int count = 0;
    Node current = head;
    do {
        ++count;
        current = current->next;
    } while (current != head);
    return count;
    
}

E *find_value(Node head, int index) {

    if (index < 0) return NULL;

    Node current = head;
    do {
        if (index == 0) return &current->element;
        current = current->next;
        --index;
    } while (current != head);
    return NULL;

}

int get_index(Node head, E element) {

    Node current = head;
    int index = 0;
    do {
        if (current->element == element) return index;
        current = current->next;
        ++index;
    } while (current != head);
    return -1;

}

_Bool delete_list(Node head, int index) {

    if (index < 0) return 0;

    Node current = head;
    while (--index > 0) {
        current = current->next;
        if (current->next == head) return 0;
    }

    Node tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return 1;

}

void print_list(Node head) {

    Node current = head->next;
    do {
        printf("%d ", current->element);
        current = current->next;
    } while (current != head);

}

int main() {

    struct list_node head;
    init_list(&head);
    for (int i = 1; i < 5; ++i) insert_list(&head, i*100, i);

    /*print_list(&head);

    printf("%d", size_list(&head));

    printf("%d", *find_value(&head, 3));

    printf("%d ", get_index(&head, 300));*/
   
    delete_list(&head, 3);
    print_list(&head);
    
    return 0;

}
