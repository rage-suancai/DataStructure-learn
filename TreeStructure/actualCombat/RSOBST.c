#include <stdio.h>
#include <stdlib.h>

struct tree_node {

    int val;
    struct tree_node *left;
    struct tree_node *right;

};

struct tree_node* create_node(int value) {

    struct tree_node *new_node = (struct tree_node*)malloc(sizeof(struct tree_node));

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = value;
    return new_node;

}

int range_sum_BST(struct tree_node* root, int low, int high) {

    if (root == NULL) return 0;

    int sum = 0;
    if (root->val >= low && root->val <= high) sum += root->val;
    if (root->val > low) sum += range_sum_BST(root->left, low, high);
    if (root->val < high) sum += range_sum_BST(root->right, low, high);
    return sum;

}

int main() {

    struct tree_node *root = create_node(10);
    root->left = create_node(5);
    root->right = create_node(15);
    root->left->left = create_node(3);
    root->left->right = create_node(7);
    root->right->right = create_node(18);

    int low = 7;
    int high = 15;
    int result = range_sum_BST(root, low, high);
    printf("%d\n", result);

    return 0;
    
}
