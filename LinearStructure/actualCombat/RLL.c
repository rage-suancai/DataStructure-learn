#include <stdio.h>
#include <stdlib.h>

struct list_node {

    int val;
    struct list_node *next;

};

struct list_node *create_node(int val) {

    struct list_node *new_node = (struct list_node*)malloc(sizeof(struct list_node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;

}

struct list_node *create_linked_list(int *arr, int size) {

    if (size == 0) return NULL;

    struct list_node *head = create_node(arr[0]);
    struct list_node *current = head;
    for (int i = 1; i < size; ++i) {
        current->next = create_node(arr[i]);
        current = current->next;
    }
    return head;

}

struct list_node *rotate_right(struct list_node *head, int k) {

    if (!head || !head->next || k == 0) return head;

    struct list_node* current = head;
    int length = 1;

    while (current->next) {
        current = current->next;
        ++length;
    }

    k %= length;
    if (k == 0) return head;

    current->next = head;

    struct list_node* new_tail = head;
    for (int i = 1; i < length-k; ++i) new_tail = new_tail->next;

    head = new_tail->next;
    new_tail->next = NULL;

    return head;

}

void print_list(struct list_node *head) {

    struct list_node *current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

}

void free_list(struct list_node *current) {

    struct list_node *tmp;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }

}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    struct list_node *head = create_linked_list(arr, size);
    print_list(head);

    struct list_node *new_head = rotate_right(head, k);
    print_list(new_head);

    free_list(new_head);
    return 0;

}

