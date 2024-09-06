#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct List {

    E *array;
    int capacity;
    int size;

};
typedef struct List *array_list;

_Bool init_list(array_list list) {

    list->array = malloc(sizeof(int) * 10);

    if (list->array == NULL) return 0;

    list->capacity = 10;
    list->size = 0;
    return 1;

}

_Bool insert_list(array_list list, E element, int index) {

    if (index < 1 || index > list->size+1) return 0;

    if (list->size == list->capacity) {
        int new_capacity = list->capacity + (list->capacity >> 1);
        E *new_array = realloc(list->array, sizeof(E) * new_capacity);
        if (new_array == NULL) return 0;
        list->array = new_array;
        list->capacity = new_capacity;
    }

    for (int i = list->size; i > index-1; --i) list->array[i] = list->array[i-1];
    list->array[index-1] = element;
    list->size++;
    return 0;

}

int size_table(array_list list) {
    return list->size;
}

E *find_value(array_list list, int index) {

    if (index < 1 || index > list->size) return NULL;
    return &list->array[index-1];

}

int get_index(array_list list, E element) {

    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i+1;
    }
    return -1;

}

_Bool delete_list(array_list list, int index) {

    if (index < 1 || index > list->size) return 0;

    for (int i = index-1; i < list->size-1; ++i) list->array[i] = list->array[i+1];
    list->size--;
    return 1;

}

void print_list(array_list list) {

    for (int i = 0; i < list->size; ++i) printf("%d ", list->array[i]);
    printf("\n");

}

int main() {

    struct List list;

    /*if (init_list(&list)) {
        insert_list(&list, 666, 1);
        print_list(&list);
        insert_list(&list, 777, 1);
        print_list(&list);
        insert_list(&list, 888, 2);
        print_list(&list);
    } else {
        printf("Sequence table initialization failure can not start the program!");
    }

    for (int i = 0; i < 10; ++i) insertList(&list, i, i);
    deleteList(&list, 5);
    printList(&list);

    if (init_list(&list)) {
        insert_list(&list, 10, 1);
        insert_list(&list, 20, 2);
        insert_list(&list, 30, 3);
        printf("%d", size_table(&list));
    }
    
    if (init_list(&list)) {
        insert_list(&list, 10, 1);
        insert_list(&list, 20, 2);
        insert_list(&list, 30, 3);
        E *element = find_value(&list, 1);
        printf("%d", *element);
    }*/

    if (init_list(&list)) {
        insert_list(&list, 10, 1);
        insert_list(&list, 20, 2);
        insert_list(&list, 30, 3);
        int index = get_index(&list, 20);
        printf("%d", index);
    }

    return 0;

}
