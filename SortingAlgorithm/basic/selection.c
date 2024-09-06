#include <stdio.h>

void swap(int* a, int* b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void select_sort(int arr[], int size) {

    /*for (int i = 0; i < size-1; ++i) {
        int min = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[min] > arr[j]) min = j;
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }*/

    int left = 0, right = size-1;
    while (left < right) {
        int min = left, max = right;
        for (int i = left; i <= right; ++i) {
            if (arr[i] < arr[min]) min = i;
            if (arr[i] > arr[max]) max = i;
        }
        swap(&arr[max], &arr[right]);
        if (min == right) min = max;
        swap(&arr[min], &arr[left]);

        ++left;
        --right;
    }

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    select_sort(arr, size);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");

    return 0; 

}


