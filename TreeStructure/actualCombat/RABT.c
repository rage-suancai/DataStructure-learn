#include <stdio.h>
#include <stdlib.h>

struct tree_node {

    int val;
    struct tree_node *left;
    struct tree_node *right;

};

int find_index(int *inorder, int inorder_size, int val) {

    for (int i = 0; i < inorder_size; ++i) {
      if (inorder[i] == val)
        return i;
    }
    return -1;

}

struct tree_node* build_tree_helper(int *preorder, int preorder_size, int *inorder, int inorder_size, int *pre_index) {

    if (inorder_size == 0) return NULL;

    struct tree_node *root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->val = preorder[*pre_index];
    (*pre_index)++;

    int root_index = find_index(inorder, inorder_size, root->val);

    root->left = build_tree_helper(preorder, preorder_size, inorder, root_index, pre_index);
    root->right = build_tree_helper(preorder, preorder_size, inorder + root_index + 1, inorder_size - root_index - 1, pre_index);

    return root;

}

struct tree_node* build_tree(int *preorder, int preorder_size, int *inorder, int inorder_size) {

    int pre_index = 0;
    return build_tree_helper(preorder, preorder_size, inorder, inorder_size, &pre_index);

}

void print_tree(struct tree_node* root) {

    if (root == NULL) {
      printf("null ");
      return;
    }

    printf("%d ", root->val);
    print_tree(root->left);
    print_tree(root->right);
    
}

int main() {

    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    struct tree_node* root = build_tree(preorder, size, inorder, size);

    print_tree(root);
    printf("\n");

    return 0;

}
