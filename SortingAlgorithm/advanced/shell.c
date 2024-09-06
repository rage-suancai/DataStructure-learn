#include <stdio.h>

void shell_sort(int arr[], int size) {

    int delta = size/2;
    while (delta >= 1) {
        for (int i = delta; i < size; ++i) {
            int j = i, tmp = arr[i];
            while (j >= delta && arr[j-delta] > tmp) {
                arr[j] = arr[j-delta];
                j -= delta;
            }
            arr[j] = tmp;
        }
        delta /= 2;
    }

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    shell_sort(arr, size);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

}

