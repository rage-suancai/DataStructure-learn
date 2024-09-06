#include <stdio.h>

int binary_search(int arr[], int left, int right, int target) {

    int mid;
    while (left <= right) {
        mid = (left+right) / 2;
        if (target == arr[mid]) return mid+1;
        else if (target < arr[mid]) right = mid-1;
        else left = mid+1;
    }
    return left;

}

void insert_sort(int arr[], int size) {

    /*for (int i = 1; i < size; ++i) {
        int j = i, tmp = arr[i];
        while (j > 0 && arr[j-1] > tmp) {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = tmp;
    }*/

    for (int i = 1; i < size; ++i) {
        int tmp = arr[i];
        int j = binary_search(arr, 0, i-1, tmp);
        for (int k = i; k > j; --k) arr[k] = arr[k-1];
        arr[j] = tmp;
    }

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    insert_sort(arr, size);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");

    return 0;

}


