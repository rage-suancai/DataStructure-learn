#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;
typedef struct RB_tree_node {

    int data;
    Color color;
    struct RB_tree_node *left;
    struct RB_tree_node *right;
    struct RB_tree_node *parent;

} RB_tree_node;

typedef struct RB_tree {

    RB_tree_node *root;
    RB_tree_node *nil;

} RB_tree;

RB_tree_node* new_node(int data, Color color, RB_tree_node* nil) {

    RB_tree_node* node = (RB_tree_node*)malloc(sizeof(RB_tree_node));

    node->data = data;
    node->color = color;
    node->left = nil;
    node->right = nil;
    node->parent = nil;
    return node;

}
RB_tree* create_RB_tree() {

    RB_tree* tree = (RB_tree*)malloc(sizeof(RB_tree));
    tree->nil = (RB_tree_node*)malloc(sizeof(RB_tree_node));

    tree->nil->color = BLACK;
    tree->root = tree->nil;
    return tree;

}

void left_rotation(RB_tree* tree, RB_tree_node* x) {

    RB_tree_node* y = x->right;

    x->right = y->left;
    if (y->left != tree->nil) y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == tree->nil) tree->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;

}
void right_rotation(RB_tree* tree, RB_tree_node* y) {

    RB_tree_node* x = y->left;

    y->left = x->right;
    if (x->right != tree->nil) x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == tree->nil) tree->root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;

    x->right = y;
    y->parent = x;

}

RB_tree_node *mini_mum(RB_tree* tree, RB_tree_node* node) {

    while (node->left != tree->nil) node = node->left;
    return node;

}

void insert_fixup(RB_tree* tree, RB_tree_node* z) {

    while (z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        RB_tree_node* y = z->parent->parent->right;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            left_rotation(tree, z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          right_rotation(tree, z->parent->parent);
        }
      } else {
        RB_tree_node* y = z->parent->parent->left;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotation(tree, z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          left_rotation(tree, z->parent->parent);
        }
      }
    }

    tree->root->color = BLACK;

}
void insert(RB_tree* tree, int data) {

    RB_tree_node* z = new_node(data, RED, tree->nil);
    RB_tree_node* y = tree->nil;
    RB_tree_node* x = tree->root;

    while (x != tree->nil) {
      y = x;
      if (z->data < x->data) x = x->left;
      else x = x->right;
    }

    z->parent = y;
    if (y == tree->nil) tree->root = z;
    else if (z->data < y->data) y->left = z;
    else y->right = z;

    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;

    insert_fixup(tree, z);

}

void delete_fixup(RB_tree* tree, RB_tree_node* x) {

    while (x != tree->root && x->color == BLACK) {
      if (x == x->parent->left) {
        RB_tree_node* w = x->parent->right;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          left_rotation(tree, x->parent);
          w = x->parent->right;
        }
        if (w->left->color == BLACK && w->right->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->right->color == BLACK) {
            w->left->color = BLACK;
            w->color = RED;
            right_rotation(tree, w);
            w = x->parent->right;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->right->color = BLACK;
          left_rotation(tree, x->parent);
          x = tree->root;
        }
      } else {
        RB_tree_node* w = x->parent->left;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          right_rotation(tree, x->parent);
          w = x->parent->left;
        }
        if (w->right->color == BLACK && w->left->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->left->color == BLACK) {
            w->right->color = BLACK;
            w->color = RED;
            left_rotation(tree, w);
            w = x->parent->left;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->left->color = BLACK;
          right_rotation(tree, x->parent);
          x = tree->root;
        }
      }
    }

    x->color = BLACK;

}
void delete_node(RB_tree* tree, RB_tree_node* z) {

    RB_tree_node* y = z;
    RB_tree_node* x;
    Color y_original_color = y->color;

    if (z->left == tree->nil) {
      x = z->right;
      if (z->parent == tree->nil) tree->root = x;
      else if (z == z->parent->left) z->parent->left = x;
      else z->parent->right = x;
      x->parent = z->parent;
    } else if (z->right == tree->nil) {
      x = z->left;
      if (z->parent == tree->nil) tree->root = x;
      else if (z == z->parent->left) z->parent->left = x;
      else z->parent->right = x;
      x->parent = z->parent;
    } else {
      y = mini_mum(tree, z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        if (y->parent != tree->nil) y->parent->left = x;
        y->right = z->right;
        y->right->parent = y;
      }
      if (z->parent == tree->nil) tree->root = y;
      else if (z == z->parent->left) z->parent->left = y;
      else z->parent->right = y;

      y->parent = z->parent;
      y->color = z->color;
      y->left = z->left;
      z->left->parent = y;
    }

    if (y_original_color == BLACK) delete_fixup(tree, x);
    free(z);

}

void in_order(RB_tree_node* root, RB_tree_node* nil) {

    if (root != nil) {
      in_order(root->left, nil);
      printf("%d ", root->data);
      in_order(root->right, nil);
    }

}

void free_node(RB_tree_node* node, RB_tree_node* nil) {

    if (node != nil) {
      free_node(node->left, nil);
      free_node(node->right, nil);
      free(node);
    }

}
void free_RB_tree(RB_tree* tree) {

    if (tree) {
      free_node(tree->root, tree->nil);
      free(tree->nil);
      free(tree);
    }

}

int main() {

  RB_tree* tree = create_RB_tree();

  insert(tree, 10);
  insert(tree, 20);
  insert(tree, 30);
  insert(tree, 15);

  in_order(tree->root, tree->nil);
  printf("\n");
  delete_node(tree, tree->root->left);
  in_order(tree->root, tree->nil);

  free_RB_tree(tree);
  return 0;

}
