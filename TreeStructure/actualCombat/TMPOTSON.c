#include <limits.h>
#include <stdio.h>

struct tree_node {

    int val;
    struct tree_node *left;
    struct tree_node *right;

};

int max_gain(struct tree_node *node, int *max_sum) {

    if (node == NULL) return 0;

    int left_gain = max_gain(node->left, max_sum);
    int right_gain = max_gain(node->right, max_sum);
    left_gain = left_gain > 0 ? left_gain : 0;
    right_gain = right_gain > 0 ? right_gain : 0;

    int current_path_sum = node->val + left_gain + right_gain;

    if (current_path_sum > *max_sum) *max_sum = current_path_sum;
    return node->val + (left_gain > right_gain ? left_gain : right_gain);

}

int max_path_sum(struct tree_node *root) {

    int max_sum = INT_MIN;
    max_gain(root, &max_sum);
    return max_sum;

}

int main() {

    struct tree_node n1 = {1, NULL, NULL};
    struct tree_node n2 = {2, NULL, NULL};
    struct tree_node n3 = {3, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;

    int result = max_path_sum(&n1);
    printf("%d\n", result);

    return 0;
    
}
