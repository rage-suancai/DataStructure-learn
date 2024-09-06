#include <stdio.h>

int findkth_missing_positive(int *arr, int arr_size, int k) {

    int missing_count = 0;
    int current = 1;
    int i = 0;

    while (missing_count < k) {
        if (i < arr_size && arr[i] == current) {
            ++i;
        } else {
            ++missing_count;
            if (missing_count == k) return current;
        }
        ++current;
    }

    return -1;

}
 
int binary_search(int *arr, int arr_size, int k) {

    int left = 0, right = arr_size-1;

    while (left <= right) {
        int mid = left + (right-left) / 2;
        int missing_count = arr[mid] - (mid+1);

        if (missing_count < k) left = mid+1;
        right = mid-1;
    }
    return left+k;

}

int main() {

    int arr[] = {2, 3, 4, 7, 11};
    int k = 5;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, arr_size, k);
    printf("the %d missing positive inieger is %d\n", k, result);

    return 0;

}
