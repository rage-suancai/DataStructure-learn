#include <limits.h>
#include <stdbool.h>
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

bool is_BST_util(struct tree_node *node, long min, long max) {

    if (node == NULL) return true;
    if (node->val <= min || node->val >= max) return false;

    return is_BST_util(node->left, min, node->val) && is_BST_util(node->right, node->val, max);

}

bool is_valid_BST(struct tree_node *root) {
    return is_BST_util(root, LONG_MIN, LONG_MAX);
}

int main() {

    struct tree_node *root1 = new_node(4);
    root1->left = new_node(2);
    root1->right = new_node(6);
    root1->left->left = new_node(1);
    root1->left->right = new_node(3);
    root1->right->left = new_node(5);
    root1->right->right = new_node(7);
    printf("tree 1 is %s BST\n", is_valid_BST(root1) ? "a valid" : "not a valid");

    struct tree_node *root2 = new_node(5);
    root2->left = new_node(1);
    root2->right = new_node(4);
    root2->right->left = new_node(3);
    root2->right->right = new_node(6);
    printf("tree 2 is %s BTST\n", is_valid_BST(root2) ? "a valid" : "not a valid");

    return 0;

}
