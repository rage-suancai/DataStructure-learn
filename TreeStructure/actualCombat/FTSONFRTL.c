#include <stdio.h>
#include <stdlib.h>

struct tree_node {

    int val;
    struct tree_node *left;
    struct tree_node *right;

};

struct tree_node *new_node(int val) {

    struct tree_node *node = (struct tree_node *)malloc(sizeof(struct tree_node));

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;

}

int sum_numbers_helper(struct tree_node *root, int current_sum) {

    if (root == NULL) return 0;

    current_sum = current_sum * 10 + root->val;

    if (root->left == NULL && root->right == NULL) return current_sum;

    return sum_numbers_helper(root->left, current_sum) + sum_numbers_helper(root->right, current_sum);

}

int sum_numbers(struct tree_node *root) { 
  return sum_numbers_helper(root, 0);
}

int main() {

    struct tree_node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);

    int result = sum_numbers(root);
    printf("%d\n", result);

    free(root->left);
    free(root->right);
    free(root);

    return 0;

}
