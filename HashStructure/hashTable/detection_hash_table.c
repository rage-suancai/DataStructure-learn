#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct Element {

    int key;
    bool is_deleted;

} *E;

typedef struct hash_table {

    E *table;

} *hash_table;

int hash(int key) {
    return key % SIZE;
}

void init(hash_table hash_table) {

    hash_table->table = malloc(sizeof(E) * SIZE);

    if (hash_table->table == NULL) exit(1);

    for (int i = 0; i < SIZE; ++i) hash_table->table[i] = NULL;

}

bool insert(hash_table hash_table, E element) {

    if (element == NULL) return false;

    int hash_code = hash(element->key);
    int i = 0;
    int new_hash;

    do {
        new_hash = (hash_code + i*i) % SIZE;
        if (hash_table->table[new_hash] == NULL || hash_table->table[new_hash]->is_deleted) {
            if (hash_table->table[new_hash] && hash_table->table[new_hash]->is_deleted) free(hash_table->table[new_hash]);
            hash_table->table[new_hash] = element;
            return true;
        }
        ++i;
    } while (i < SIZE);

    return false;

}

E create(int key) {

    E e = malloc(sizeof(struct Element));

    if (e == NULL) return NULL;

    e->key = key;
    e->is_deleted = false;
    return e;

}

bool find(hash_table hash_table, int key) {

    int hash_code = hash(key);
    int i = 0;
    int new_hash; 

    do {
        new_hash = (hash_code + i*i) % SIZE;
        if (hash_table->table[new_hash] == NULL) return false;
        if (!hash_table->table[new_hash]->is_deleted && hash_table->table[new_hash]->key == key) return true;
        ++i;
    } while (i < SIZE);

    return false;

}

void delete_element(hash_table hash_table, int key) {

    int hash_code = hash(key);
    int i = 0;
    int new_hash;

    do {
        new_hash = (hash_code + i*i) % SIZE;
        if (hash_table->table[new_hash] == NULL) return;
        if (!hash_table->table[new_hash]->is_deleted && hash_table->table[new_hash]->key == key){
            hash_table->table[new_hash]->is_deleted = true;
            return;
        }
        ++i;
    } while (i < SIZE);

}

void free_table(hash_table hash_table) {

    for (int i = 0; i < SIZE; ++i) {
        if (hash_table->table[i] != NULL) free(hash_table->table[i]);
    }
    free(hash_table->table);

}

int main() {

    struct hash_table hash_table;
    init(&hash_table);
    for (int i = 0; i < SIZE; ++i) {
        E element = create(i*9);
        if (element == NULL) {
            free_table(&hash_table);
            return 1;
        }
        if (!insert(&hash_table, element)) {
            printf("Failed to insert %d\n", i*9);
            free(element);
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        if (hash_table.table[i] != NULL && !hash_table.table[i]->is_deleted) printf("Index %d: %d\n", i, hash_table.table[i]->key);
        else printf("Index %d: Empty\n", i);
    } 

    delete_element(&hash_table, 18);
    delete_element(&hash_table, 36);

    printf("\nAfter deletion:\n");

    for (int i = 0; i < SIZE; ++i) {
        if (hash_table.table[i] != NULL && !hash_table.table[i]->is_deleted) printf("Index %d: %d\n", i, hash_table.table[i]->key);
        else printf("Index %d: Empty\n", i);
    }

    printf("\nFind 18: %s\n", find(&hash_table, 18) ? "Found" : "Not Found");
    printf("Find 36: %s\n", find(&hash_table, 36) ? "Found" : "Not Found");
    printf("Find 9: %s\n", find(&hash_table, 9) ? "Found" : "Not Found");

    free_table(&hash_table);

    return 0;

}

