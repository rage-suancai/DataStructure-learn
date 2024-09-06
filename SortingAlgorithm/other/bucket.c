#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10
#define ARRAY_SIZE 10

typedef struct {

    int count;
    int* values;

} bucket;

void bucket_sort(int arr[], int size) {

    int i, j, k;
    int max_value = arr[0];
    int min_value = arr[0];

    for (i = 1; i < size; ++i) {
        if (arr[i] > max_value) max_value = arr[i];
        if (arr[i] < min_value) min_value = arr[i];
    }

    int range = (max_value-min_value) / BUCKET_SIZE+1;

    bucket* buckets = (bucket*) malloc(sizeof(bucket) * BUCKET_SIZE);
    for (i = 0; i < BUCKET_SIZE; ++i) {
        buckets[i].count = 0;
        buckets[i].values = (int*) malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; ++i) {
        int index = (arr[i]-min_value) / range;
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for (i = 0; i < BUCKET_SIZE; ++i) {
        for (j = 1; j < buckets[i].count; ++j) {
            int tmp = buckets[i].values[j];
            k = j-1;
            while (k >= 0 && buckets[i].values[k] > tmp) {
                buckets[i].values[k+1] = buckets[i].values[k];
                --k;
            }
            buckets[i].values[k+1] = tmp;
        }
    }

    int index = 0;
    for (i = 0; i < BUCKET_SIZE; ++i) {
        for (j = 0; j < buckets[i].count; ++j) arr[index++] = buckets[i].values[j];
        free(buckets[i].values);
    }
    free(buckets);

}

int main() {

    int arr[] = {ARRAY_SIZE};
    for (int i = 0; i < ARRAY_SIZE; ++i) arr[i] = rand() % 1000;

    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", arr[i]);
    bucket_sort(arr, ARRAY_SIZE);
    printf("\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", arr[i]);

}



