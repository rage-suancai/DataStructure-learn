#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;
typedef struct min_heap {

    E* arr;
    int size;
    int capacity;

} *heap;
 
void swap(E* a, E* b) {

    E tmp = *a;
    *a = *b;
    *b = tmp;

}

bool init_heap(heap heap) {

    heap->size = 0;
    heap->capacity = 10;
    heap->arr = malloc(sizeof(E) * (heap->capacity+1));
    return heap->arr != NULL;

}

bool insert(heap heap, E element) {

    if (heap->size == heap->capacity) return false;

    int index = ++heap->size;
    while (index > 1 && element < heap->arr[index/2]) {
        heap->arr[index] = heap->arr[index/2];
        index /= 2;
    }
    heap->arr[index] = element;
    return true;

}

E delete_min(heap heap) {

    if (heap->size == 0) return 0;

    E min = heap->arr[1];
    E last = heap->arr[heap->size--];
    int index = 1;
    while (index*2 <= heap->size) {
        int child = index*2;
        if (child < heap->size && heap->arr[child+1] < heap->arr[child]) ++child;
        if (last <= heap->arr[child]) break;
        heap->arr[index] = heap->arr[child];
        index = child;
    }
    heap->arr[index] = last;
    return min;

}

void make_heap(int* arr, int start, int end) {

    int root = start;
    while (root*2+1 <= end) {
        int child = root*2+1;
        if (child+1 <= end && arr[child] < arr[child+1]) ++child;
        if (arr[root] < arr[child]) {
            swap(&arr[root], &arr[child]);
            root = child;
        } else {
            return;
        }
    }
 
}

void heap_sort(int arr[], int size) {

    for (int i = size/2-1; i >= 0; --i) make_heap(arr, i, size-1);

    for (int i = size-1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        make_heap(arr, 0, i-1);
    }

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct min_heap heap;
    init_heap(&heap);

    /*for (int i = 0; i < size; ++i) insert(&heap, arr[i]);
    for (int i = 0; i < size; ++i) arr[i] = delete_min(&heap);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);*/

    for (int i = 0; i < size; ++i) insert(&heap, arr[i]);
    heap_sort(arr, size);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);

    return 0;

}


