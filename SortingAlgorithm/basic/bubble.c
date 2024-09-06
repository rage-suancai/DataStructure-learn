#include <stdio.h>

void bubble_sort(int arr[], int size) {

    for (int i = 0; i < size-1; ++i) {
        int flag = 1;
        for (int j = 0; j < size-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                flag = 0;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if (flag) break;
    }

} 

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    bubble_sort(arr, size);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");

    return 0;

}

