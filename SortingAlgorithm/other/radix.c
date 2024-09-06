#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10
#define MAX_DIGITS 4

int get_digit(int num, int exp) {
    return (num/exp) % 10;
}

void counting_sort(int array[], int size, int exp) {

    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; ++i) count[get_digit(array[i], exp)]++;

    for (int i = 1; i < 10; ++i) count[i] += count[i-1];

    for (int i = size-1; i >= 0; --i) {
        output[count[get_digit(array[i], exp)] - 1] = array[i];
        count[get_digit(array[i], exp)]--;
    }

    memcpy(array, output, size*sizeof(int));

}

void radix_sort(int array[], int size) {

    int max = array[0];
    for (int i = 1; i < size; ++i) if (array[i] > max) max = array[i];

    for (int exp = 1; max/exp > 0; exp *= 10) counting_sort(array, size, exp);

}

int main() {

    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) arr[i] = rand() % 100;

    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", arr[i]);
    printf("\n");
    radix_sort(arr, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", arr[i]);
 
    return 0;

}


