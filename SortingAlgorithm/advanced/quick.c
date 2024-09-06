#include <stdio.h>

void swap(int* a, int* b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void quick_sort(int arr[], int start, int end) {

    if (start >= end) return;

    int left = start, right = end, pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) --right;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) ++left;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    quick_sort(arr, start, left-1);
    quick_sort(arr, left+1, end);

}

void dual_povot_quick_sort(int arr[], int start, int end) {

    if (start >= end) return;

    if (arr[start] > arr[end]) swap(&arr[start], &arr[end]);

    int pivot1 = arr[start], pivot2 = arr[end];
    int left = start+1, right = end-1, mid = left;
    while (mid <= right) {
        if (arr[mid] < pivot1) {
            swap(&arr[mid], &arr[left]);
            ++left;
        } else if (arr[mid] >= pivot2) {
            while (mid < right && arr[right] > pivot2) --right;
            swap(&arr[mid], &arr[right]);
            --right;
            if (arr[mid] < pivot1){
                swap(&arr[mid], &arr[left]);
                ++left;
            }
        }
        ++mid;
    }
    --left;
    ++right;
    swap(&arr[start], &arr[left]);
    swap(&arr[end], &arr[right]);
    dual_povot_quick_sort(arr, start, left-1);
    dual_povot_quick_sort(arr, left+1, right-1);
    dual_povot_quick_sort(arr, right+1, end);

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    // quick_sort(arr, 0, n - 1);
    dual_povot_quick_sort(arr, 0, size-1);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;

}

