#include <stdio.h>

void merge(int arr[], int tmp[], int left, int mid, int right) {

    int i = left, j = mid+1, k=left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];

    for (int p = left; p <= right; ++p) arr[p] = tmp[p];

}

void merge_sort(int arr[], int tmp[], int left, int right) {

    if (left < right) {
        int mid = left + (right-left) / 2;
        merge_sort(arr, tmp, left, mid);
        merge_sort(arr, tmp, mid+1, right);
        merge(arr, tmp, left, mid, right);
    }

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int tmp[size];

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    merge_sort(arr, tmp, 0, size-1);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);

    return 0;

}

