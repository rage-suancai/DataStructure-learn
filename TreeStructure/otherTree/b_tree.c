#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_KETS 3
#define MIN_KEYS (MAX_KETS / 2)

typedef struct B_tree_node {

    int keys[MAX_KETS];
    struct B_tree_node *children[MAX_KETS + 1];
    int num_keys;
    bool is_leaf;

} B_tree_node;

void remove_from_node(B_tree_node* node, int key);

B_tree_node* create_node(bool is_leaf) {

    B_tree_node* new_node = (B_tree_node*)malloc(sizeof(B_tree_node));

    new_node->is_leaf = is_leaf;
    new_node->num_keys = 0;

    for (int i = 0; i <= MAX_KETS; ++i) new_node->children[i] = NULL;
    return new_node;

}

void split_child(B_tree_node* parent, int i, B_tree_node* y) {

    B_tree_node* z = create_node(y->is_leaf);
    z->num_keys = MIN_KEYS;

    for (int j = 0; j < MIN_KEYS; ++j) z->keys[j] = y->keys[j + MIN_KEYS + 1];

    if (!y->is_leaf) {
      for (int j = 0; j <= MIN_KEYS; ++j) z->children[j] = y->children[j + MIN_KEYS + 1];
    }

    y->num_keys = MIN_KEYS;

    for (int j = parent->num_keys; j >= i + 1; --j) parent->children[j + 1] = parent->children[j];
    parent->children[i + 1] = z;

    for (int j = parent->num_keys - 1; j >= i; --j) parent->children[j + 1] = parent->children[j];
    parent->keys[i] = y->keys[MIN_KEYS];

    parent->num_keys++;

}

void insert_non_full(B_tree_node* node, int key) {

    int i = node->num_keys - 1;

    if (node->is_leaf) {
      while (i >= 0 && key < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        --i;
      }
      node->keys[i + 1] = key;
      node->num_keys++;
    } else {
      while (i >= 0 && key < node->keys[i]) --i;
      ++i;
      if (node->children[i]->num_keys == MAX_KETS) {
        split_child(node, i, node->children[i]);
        if (key > node->keys[i]) ++i;
      }
      insert_non_full(node->children[i], key);
    }

}

void insert(B_tree_node** root, int key) {

    B_tree_node* r = *root;

    if (r->num_keys == MAX_KETS) {
      B_tree_node* s = create_node(false);
      s->children[0] = r;
      split_child(s, 0, r);
      insert_non_full(s, key);
      *root = s;
    } else {
      insert_non_full(r, key);
    }

}

void merge(B_tree_node* node, int idx) {

    B_tree_node* child = node->children[idx];
    B_tree_node* sibling = node->children[idx + 1];

    child->keys[MIN_KEYS] = node->keys[idx];

    for (int i = 0; i < sibling->num_keys; ++i) child->keys[i + MIN_KEYS + 1] = sibling->keys[i];

    if (!child->is_leaf) {
      for (int i = 0; i <= sibling->num_keys; ++i) node->children[i - 1] = node->children[i];
    }

    for (int i = idx + 1; i < node->num_keys; ++i) node->keys[i - 1] = node->keys[i];

    for (int i = idx + 2; i <= node->num_keys; ++i) node->children[i - 1] = node->children[i];

    child->num_keys += sibling->num_keys + 1;
    node->num_keys--;

    free(sibling);

}

void fill(B_tree_node* node, int idx) {

    if (idx != 0 && node->children[idx - 1]->num_keys >= MIN_KEYS + 1) {
      B_tree_node* child = node->children[idx];
      B_tree_node* sibling = node->children[idx - 1];

      for (int i = child->num_keys - 1; i >= 0; --i) child->keys[i + 1] = child->keys[i];

      if (!child->is_leaf) {
        for (int i = child->num_keys; i >= 0; --i) child->children[i + 1] = child->children[i];
      }

      child->keys[0] = node->keys[idx - 1];

      if (!node->is_leaf) child->children[0] = sibling->children[sibling->num_keys];

      node->keys[idx - 1] = sibling->keys[sibling->num_keys - 1];

      child->num_keys++;
      sibling->num_keys--;
    } else if (idx != node->num_keys && node->children[idx + 1]->num_keys >= MIN_KEYS + 1) {
      B_tree_node* child = node->children[idx];
      B_tree_node* sibling = node->children[idx + 1];

      child->keys[child->num_keys] = node->keys[idx];

      if (!child->is_leaf) child->children[child->num_keys + 1] = sibling->children[0];

      node->keys[idx] = sibling->keys[0];

      for (int i = 1; i < sibling->num_keys; ++i) sibling->keys[i - 1] = sibling->keys[i];

      if (!sibling->is_leaf) {
        for (int i = 1; i <= sibling->num_keys; ++i) sibling->children[i - 1] = sibling->children[i];
      }

      child->num_keys++;
      sibling->num_keys--;
    } else {
      if (idx != node->num_keys) {
        merge(node, idx);
      } else {
        merge(node, idx - 1);
      }
    }

}

void remove_from_leaf(B_tree_node* node, int idx) {

    for (int i = idx + 1; i < node->num_keys; ++i) node->keys[i - 1] = node->keys[i];
    node->num_keys--;

}

void remove_from_non_leaf(B_tree_node* node, int idx) {

    int key = node->keys[idx];

    if (node->children[idx]->num_keys >= MIN_KEYS + 1) {
      B_tree_node* cur = node->children[idx];
      while (!cur->is_leaf) cur = cur->children[cur->num_keys];
      int pred = cur->keys[cur->num_keys - 1];
      node->keys[idx] = pred;
      remove_from_node(node->children[idx], pred);
    } else if (node->children[idx + 1]->num_keys >= MIN_KEYS + 1) {
      B_tree_node* cur = node->children[idx + 1];
      while (!cur->is_leaf) cur = cur->children[0];
      int succ = cur->keys[0];
      node->keys[idx] = succ;
      remove_from_node(node->children[idx + 1], succ);
    } else {
      merge(node, idx);
      remove_from_node(node->children[idx], key);
    }

}

void remove_from_node(B_tree_node* node, int key) {

    int idx = 0;
    while (idx < node->num_keys && node->keys[idx] < key) ++idx;

    if (idx < node->num_keys && node->keys[idx] == key) {
      if (node->is_leaf) {
        remove_from_leaf(node, idx);
      } else {
        remove_from_non_leaf(node, idx);
      }
    } else {
      if (node->is_leaf) return;
      bool flag = (idx == node->num_keys);
      if (node->children[idx]->num_keys < MIN_KEYS + 1) fill(node, idx);
      if (flag && idx > node->num_keys) {
        remove_from_node(node->children[idx - 1], key);
      } else {
        remove_from_node(node->children[idx], key);
      }
    }

}

void remove_key(B_tree_node** root, int key) {

    remove_from_node(*root, key);

    if ((*root)->num_keys == 0) {
      B_tree_node* tmp = *root;
      if ((*root)->is_leaf) {
        *root = NULL;
      } else {
        *root = (*root)->children[0];
      }
      free(tmp);
    }

}

void printf_tree(B_tree_node* root, int level) {

    if (root != NULL) {
      for (int i = 0; i < root->num_keys; ++i) {
        printf_tree(root->children[i], level + 1);
        for (int j = 0; j < level; ++j) {
          printf("    ");
        }
        printf("%d\n", root->keys[i]);
      }
      printf_tree(root->children[root->num_keys], level + 1);
    }

}

int main() {

    B_tree_node* root = create_node(true);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);

    printf_tree(root, 0);

    return 0;
    
}
