#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct tree_node {

    E element;
    struct tree_node *left;
    struct tree_node *right;
    int height;

} *Node;

#define max(a, b) ((a) > (b) ? (a) : (b))

Node create_node(E element) {

    Node node = malloc(sizeof(struct tree_node));

    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;
    return node;

}

int get_height(Node root) {

    if (root == NULL) return 0;
    return root->height;

}

Node min_value_node(Node node) {

    Node current = node;
    while (current->left != NULL) current = current->left;
    return current;

}

Node left_rotation(Node root) {

    Node new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;
    return new_root;

}
Node right_rotation(Node root) {

    Node new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;
    return new_root;

}

Node left_right_rotation(Node root) {

    root->left = left_rotation(root->left);
    return right_rotation(root);

}
Node right_left_rotation(Node root) {

    root->right = right_rotation(root->right);
    return left_rotation(root);

}

Node insert(Node root, E element) {

    if (root == NULL) {
      root = create_node(element);
    } else if (element < root->element) {
      root->left = insert(root->left, element);
      if (get_height(root->left) - get_height(root->right) > 1) {
        if (element < root->left->element) root = right_rotation(root);
        else root = left_right_rotation(root);
      }
    } else if (element > root->element) {
      root->right = insert(root->right, element);
      if (get_height(root->left) - get_height(root->right) < -1) {
        if (element > root->right->element) root = left_rotation(root);
        else root = right_left_rotation(root);
      }
    }

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    return root;

}

Node delete(Node root, E element) {

    if (root == NULL) return root;

    if (element < root->element) root->left = delete(root->left, element);
    else if (element > root->element) root->right = delete(root->right, element);
    else {
      if (root->left == NULL || root->right == NULL) {
        Node tmp = root->left ? root->left : root->right;
        if (tmp == NULL) {
          tmp = root;
          root = NULL;
        } else {
          *root = *tmp;
        }
        free(tmp);
      } else {
        Node tmp = min_value_node(root->right);
        root->element = tmp->element;
        root->right = delete(root->right, tmp->element);
      }
    }

    if (root == NULL) return root;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    int balance = get_height(root->left) - get_height(root->right);

    if (balance > 1 && get_height(root->left->left) >= get_height(root->left->right)) return right_rotation(root);
    if (balance > 1 && get_height(root->left->left) < get_height(root->left->right)) {
      root->left = left_rotation(root->left);
      return right_rotation(root);
    }
    if (balance < -1 && get_height(root->right->right) < get_height(root->right->left)) return left_rotation(root);
    if (balance < -1 && get_height(root->right->right) < get_height(root->right->left)) {
      root->right = right_rotation(root->right);
      return left_rotation(root);
    }

    return root;

}

void in_order(Node root) {

    if (root != NULL) {
      in_order(root->left);
      printf("%d ", root->element);
      in_order(root->right);
    }

}

int main() {

    Node root = NULL;
    int elements[] = {20, 4, 15, 70, 50, 100, 10};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; ++i) root = insert(root, elements[i]);
    in_order(root);

    root = delete(root, 15);
    in_order(root);

    return 0;

}
