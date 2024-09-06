#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

struct Node {

    char data;
    unsigned freq;
    struct Node *left, *right;

};

struct min_heap {

    unsigned size;
    unsigned capacity;
    struct Node** array;

};

int is_leaf(struct Node* root) {
    return !(root->left) && !(root->right);
}

int is_size_one(struct min_heap* min_heap) { 
    return (min_heap->size == 1); 
}

void swap_node(struct Node** a, struct Node** b) {

    struct Node* t = *a;
    *a = *b;
    *b = t;

}

struct Node* new_node(char data, unsigned freq) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;

}

struct min_heap* create_min_heap(unsigned capacity) {

    struct min_heap* min_heap = (struct min_heap*)malloc(sizeof(struct min_heap));

    min_heap->size = 0;
    min_heap->capacity = capacity;

    min_heap->array = (struct Node**)malloc(min_heap->capacity * sizeof(struct Node*));
    return min_heap;

}

void min_heap_pify(struct min_heap* min_heap, int idx) {

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) smallest = left;
    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) smallest = right;
    if (smallest != idx) {
      swap_node(&min_heap->array[smallest], &min_heap->array[idx]);
      min_heap_pify(min_heap, smallest);
    }

}

struct Node* extract_min(struct min_heap* min_heap) {

    struct Node* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heap_pify(min_heap, 0);
    return temp;

}

void insert_min_heap(struct min_heap* min_heap, struct Node* min_heap_node) {

    int i = min_heap->size;
    ++min_heap->size;

    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
      min_heap->array[i] = min_heap->array[(i - 1) / 2];
      i = (i - 1) / 2;
    }
    min_heap->array[i] = min_heap_node;

}

void build_min_heap(struct min_heap* min_heap) {

    int n = min_heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) min_heap_pify(min_heap, i);

}

struct min_heap* create_and_build_min_heap(char data[], int freq[], int size) {

    struct min_heap* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) min_heap->array[i] = new_node(data[i], freq[i]);

    min_heap->size = size;
    build_min_heap(min_heap);

    return min_heap;

}

struct Node* build_huffman_tree(char data[], int freq[], int size) {

    struct Node *left, *right, *top;
    struct min_heap* min_heap = create_and_build_min_heap(data, freq, size);

    while (!is_size_one(min_heap)) {
      left = extract_min(min_heap);
      right = extract_min(min_heap);

      top = new_node('$', left->freq + right->freq);
      top->left = left;
      top->right = right;

      insert_min_heap(min_heap, top);
    }

    return extract_min(min_heap);

}

void print_codes(struct Node* root, int arr[], int top) {

    if (root->left) {
      arr[top] = 0;
      print_codes(root->left, arr, top+1);
    }
    if (root->right) {
      arr[top] = 1;
      print_codes(root->right, arr, top+1);
    }
    if (is_leaf(root)) {
      printf("%c: ", root->data);
      for (int i = 0; i < top; ++i) printf("%d", arr[i]);
      printf("\n");
    }

}

void huffman_codes(char data[], int freq[], int size) {

    struct Node* root = build_huffman_tree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    print_codes(root, arr, top);

}

int main() {

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    huffman_codes(arr, freq, size);

    return 0;

}
