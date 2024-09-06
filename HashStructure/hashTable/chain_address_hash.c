#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct list_node {

    int key;
    struct list_node* next;

} *list_node;

typedef struct hash_table {

    struct list_node* table;

} *hash_table;

int hash(int key) {
    return key % SIZE;
}

void init(hash_table hash_table) {

    hash_table->table = malloc(sizeof(struct list_node) * SIZE);

    for (int i = 0; i < SIZE; ++i) {
        hash_table->table[i].key = -1;
        hash_table->table[i].next = NULL;
    }

}

list_node create_node(int key) {

    list_node node = malloc(sizeof(struct list_node));

    node->key = key;
    node->next = NULL;
    return node;

}

void insert(hash_table hash_table, int key) {

    int hash_code = hash(key);

    list_node head = hash_table->table + hash_code;
    while (head->next) head = head->next;
    head->next = create_node(key);

}

bool find(hash_table hash_table, int key) {

    int hash_code = hash(key);
    list_node head = hash_table->table + hash_code;
    while (head->next && head->key != key) head = head->next;
    return head->key == key;

}

int main() {

    struct hash_table table;
    init(&table);

    insert(&table, 10);
    insert(&table, 19);
    insert(&table, 20);

    printf("%d\n", find(&table, 20));
    printf("%d\n", find(&table, 17));
    printf("%d\n", find(&table, 19));
    
    return 0;

}

