#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct tree_node {

    E element;
    struct tree_node *left;
    struct tree_node *right;

} *Node;

Node create_node(E element) {

    Node node = malloc(sizeof(struct tree_node));

    node->left = node->right = NULL;
    node->element = element;
    return node;

}

Node insert(Node root, E element) {

    if (root) {
      if (root->element > element) root->left = insert(root->left, element);
      if (root->element < element) root->right = insert(root->right, element);
    } else {
      root = create_node(element);
    }
    return root;

}

Node find(Node root, E target) {

    while (root) {
      if (root->element > target) root = root->left;
      else if (root->element < target) root = root->right;
      else return root;
    }
    return NULL;

}

Node find_max(Node root) {

    while (root && root->right) root = root->right;
    return root;

}

Node delete(Node root, E target) {

    if (root == NULL) return NULL;

    if (root->element > target) root->left = delete(root->left, target);
    else if (root->element < target) root->right = delete(root->right, target);
    else {
      if (root->left && root->right) {
        Node max = find_max(root->left);
        root->element = max->element;
        root->left = delete(root->left, root->element);
      } else {
        Node tmp = root;
        if (root->right) root = root->right;
        else root = root->left;
        free(tmp);
      }
    }
    return root;

}

void in_order(Node root) {

    if (root == NULL) return;

    in_order(root->left);
    printf("%d ", root->element);
    in_order(root->right);

}

int main() {

    Node root = insert(NULL, 18);

    insert(root, 10);
    insert(root, 20);
    insert(root, 7);
    insert(root, 15);
    insert(root, 22);
    insert(root, 9);

    // in_order(root);

    /*Node root = NULL;
    while (1) {
      E element;
      scanf("%d", &element);
      root = insert(root, element);
      in_order(root);
      putchar('\n');
    }*/

    /*printf("%p\n", find(root, 17));
    printf("%p\n", find(root, 9));*/

    // printf("%p\n", find_max(root));

    delete (root, 9);
    in_order(root);

    return 0;

}
