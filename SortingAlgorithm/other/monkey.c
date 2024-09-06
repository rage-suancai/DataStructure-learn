#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

}

bool check_order(int arr[], int size) {

    for (int i = 0; i < size-1; ++i) if (arr[i] > arr[i+1]) return false;
    return true;

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int counter = 0;
    while (1) {
        int a = rand()%size, b = rand()%size;
        swap(&arr[a], &arr[b]);
        if (check_order(arr, size)) break;
        ++counter;
    }

    printf("sorting completed at %d time", counter);

}
