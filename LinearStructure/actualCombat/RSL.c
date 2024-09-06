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

struct list_node *reverse_list(struct list_node *head) {

    struct list_node *prev = NULL;
    struct list_node *curr = head;
    struct list_node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

void print_list(struct list_node *head) {

    struct list_node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

}

void free_list(struct list_node *head) {

    struct list_node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

}

int main () {

    struct list_node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);
    print_list(head);

    head = reverse_list(head);
    print_list(head);
     
    free_list(head);
    return 0;

}

