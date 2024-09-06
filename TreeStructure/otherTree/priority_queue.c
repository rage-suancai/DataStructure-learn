#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct max_heap {

    E *arr;
    int size;
    int capacity;

} *Heap;

_Bool init_heap(Heap heap) {

    heap->size = 0;
    heap->capacity = 10;
    heap->arr = malloc(sizeof(E) * heap->capacity);
    return heap->arr != NULL;

}

_Bool insert(Heap heap, E element) {

    if (heap->size == heap->capacity) return 0;

    int index = ++heap->size;
    while (index > 1 && element > heap->arr[index / 2]) {
      heap->arr[index] = heap->arr[index / 2];
      index /= 2;
    }

    heap->arr[index] = element;
    return 1;

}

E delete(Heap heap) {

    E max = heap->arr[1], e = heap->arr[heap->size--];

    int index = 1;
    while (index * 2 <= heap->size) {
      int child = index * 2;
      if (child < heap->size && heap->arr[child] < heap->arr[child + 1])
        child += 1;
      if (e >= heap->arr[child]) {
        break;
      } else {
        heap->arr[index] = heap->arr[child];
      }
      index = child;
    }

    heap->arr[index] = e;
    return max;

}

void print_heap(Heap heap) {

    for (int i = 1; i <= heap->size; ++i) printf("%d ", heap->arr[i]);

}

int main() {

    struct max_heap heap;
    init_heap(&heap);
    insert(&heap, 5);
    insert(&heap, 2);
    insert(&heap, 3);
    insert(&heap, 7);
    insert(&heap, 6);

    // print_heap(&heap);

    for (int i = 0; i < 5; ++i) printf("%d ", delete (&heap));

    return 0;

}
