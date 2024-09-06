#include <stdio.h>

int search(int *nums, int mumsSize, int target) {

    /*for (int i = 0; i <= mumsSize; ++i) if (nums[i] == target) return i;
    return -1;*/

    /*for (int i = 0; i < mumsSize; ++i) {
        if (nums[i] == target) return i;
        if (nums[i] > target) break;
    }
    return -1;*/

    return binarySearch(nums, target, 0, mumsSize-1);

}

int binarySearch(int *nums, int target, int left, int right) {

    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target) return binarySearch(nums, target, left, mid-1);
    else return binarySearch(nums, target, mid+1, right);
    
}

int main() {

    int arr[] = {1, 3, 4, 6, 7, 8, 10, 11, 13, 15}, target = 3;
    printf("%d", search(arr, 10, target));

}
