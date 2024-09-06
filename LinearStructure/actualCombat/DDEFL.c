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

struct list_node *delete_duplicates(struct list_node *head) {

    if (head == NULL || head->next == NULL) return head;

    struct list_node *current = head;
    while (current != NULL && current->next != NULL) {
      if (current->val == current->next->val) {
        struct list_node *tmp = current->next;
        current->next = current->next->next;
        free(tmp);
      } else {
        current = current->next;
      }
    }
    return head;

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

int main() {
    
    struct list_node *head = create_node(1);
    head->next = create_node(1);
    head->next->next = create_node(2);

    print_list(head);

    head = delete_duplicates(head);
    print_list(head);
    
    free_list(head);
    return 0;

}

