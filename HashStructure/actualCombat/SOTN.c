#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

typedef int K;
typedef int V;

typedef struct LNode {

    K key;
    V value;
    struct LNode* next;

} *Node;

typedef struct hash_table {

    struct LNode* table;

} *hash_table;

int hash(unsigned int key) {
    return key % SIZE;
}

void init(hash_table hash_table) {

    hash_table->table = malloc(sizeof(struct LNode) * SIZE);

    for (int i = 0; i < SIZE; ++i) {
        hash_table->table[i].key = -1;
        hash_table->table[i].value = -1;
        hash_table->table[i].next = NULL;
    }

}

Node create(K key, V value) {

    Node node = malloc(sizeof(struct LNode));

    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;

}

void insert(hash_table hash_table, K key, V value) {

    int hash_code = hash(key);
    Node head = hash_table->table + hash_code;

    while (head->next) head = head->next;
    head->next = create(key, value);

}

Node find(hash_table hash_table, K key) {

    int hash_code = hash(key);
    Node head = hash_table->table + hash_code;

    while (head->next && head->next->key != key) head = head->next;
    return head->next;

}

int* result(int i, int j, int* return_size) {

    *return_size = 2;
    int* result  = malloc(sizeof(int) * 2);

    result[0] = i;
    result[1] = j;
    return result;

}

int* two_sum(int* nums, int num_size, int target, int* return_size) {

    struct hash_table table;
    init(&table);

    for (int i = 0; i < num_size; ++i) {
        Node node = find(&table, target - nums[i]);
        if (node != NULL) return result(i, node->value, return_size);
        insert(&table, nums[i], i);
    }

    return NULL;

}

int main() {

    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int return_size1 = 0;
    int* result1 = two_sum(nums1, 4, target1, &return_size1);
    printf("Test Case 1:\n");
    if (result1 != NULL) {
        printf("Found pair: [%d, %d]\n", result1[0], result1[1]);
        free(result1);
    } else {
        printf("No pair found\n");
    }

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int return_size2 = 0;
    int* result2 = two_sum(nums2, 3, target2, &return_size2);
    printf("\nTets case 2:\n");
    if (result2 != NULL) {
        printf("Found pair: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("No pair found\n");
    }

    int nums3[] = {1, 2, 3, 4};
    int target3 = 10;
    int return_size3 = 0;
    int* result3 = two_sum(nums3, 4, target3, &return_size3);
    printf("\nTets case 3:\n");
    if (result3 != NULL) {
        printf("Found pair: [%d, %d]\n", result3[0], result3[1]);
        free(result2);
    } else {
        printf("No pair found\n");
    }

    return 0;

}


