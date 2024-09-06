#include <stdio.h>
#include <stdlib.h>

typedef char E;
typedef struct tree_node {

    E element;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
    int leftTag, rightTag;

} *Node;

Node create_node(E element) {

    Node node = malloc(sizeof(struct tree_node));
    node->left = node->right = NULL;

    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;

}

Node pre = NULL;

void pre_order_threaded(Node root) {

    if (root == NULL) return;

    if (root->left == NULL) {
      root->left = pre;
      root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
      pre->right = root;
      pre->rightTag = 1;
    }
    pre = root;

    if (root->leftTag == 0) pre_order_threaded(root->left);
    if (root->rightTag == 0) pre_order_threaded(root->right);

}
void pre_order(Node root) {

    while (root) {
      printf("%c", root->element);
      if (root->leftTag == 0) root = root->left;
      else root = root->right;
    }

}

void in_order_threaded(Node root) {

    if (root == NULL) return;

    if (root->leftTag == 0) in_order_threaded(root->left);

    if (root->left == NULL) {
      root->left = pre;
      root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
      pre->right = root;
      pre->rightTag = 1;
    }
    pre = root;

    if (root->rightTag == 0) in_order_threaded(root->right);

}
void in_order(Node root) {

    while (root && root->leftTag == 0) root = root->left;

    while (root) {
        printf("%c", root->element);
        while (root && root->rightTag == 1) {
            root = root->right;
            printf("%c", root->element);
        }
        root = root->right;
    }

}

void post_order_threaded(Node root) {

    if (root == NULL) return;

    if (root->leftTag == 0) {
      post_order_threaded(root->left);
      if (root->left) root->left->parent = root;
    }
    if (root->rightTag == 0) {
      post_order_threaded(root->right);
      if (root->right) root->right->parent = root;
    }

    if (root->left == NULL) {
      root->left = pre;
      root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
      pre->right = root;
      pre->rightTag = 1;
    }
    pre = root;

}
void post_order(Node root) {

    Node last = NULL, node = root;

    while (root) {
      while (root->left != last && root->leftTag == 0) root = root->left;
      while (root && root->rightTag == 1) {
        printf("%c", root->element);
        last = root;
        root = root->right;
      }

      if (node == root && root->right == last) {
        printf("%c", root->element); return;
      }

      while (root && root->right == last) {
        printf("%c", root->element);
        last = root;
        root = root->parent;
      }

      if (root && root->rightTag == 0) root = root->right;
    }

}

int main() {

    Node a = create_node('A');
    Node b = create_node('B');
    Node c = create_node('C');
    Node d = create_node('D');
    Node e = create_node('E');

    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;

    /*pre_order_threaded(a);
    pre_order(a);*/

    /*in_order_threaded(a);
    in_order(a);*/

    post_order_threaded(a);
    post_order(a);

    return 0;
    
}
