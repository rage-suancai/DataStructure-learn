#include <stdio.h>
#include <stdlib.h>

typedef char E;
struct tree_node {

    E element;
    struct tree_node *left;
    struct tree_node *right;
    int flag;

};
typedef struct tree_node* Node;

typedef Node T; // stack
struct stack_node {

    T element;
    struct stack_node *next;

};
typedef struct stack_node *SNode;

typedef Node q; // queue
struct queue_node {

    T element;
    struct queue_node *next;

};
typedef struct queue_node* QNode;
struct Queue {
    QNode front, rear;
};
typedef struct Queue* linked_queue;

_Bool is_empty(SNode head) {
    return head->next == NULL;
}

_Bool is_qempty(linked_queue queue) {
    return queue->front == queue->rear;
}

T peek_stack(SNode head) {
    return head->next->element;
}

void init_stack(SNode head) {
    head->next = NULL;
}

_Bool push_stack(SNode head, T element) {

    SNode node = malloc(sizeof(struct stack_node));
    if (node == NULL) return 0;

    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;

}

T pop_stack(SNode head) {

    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top); return e;

}

_Bool init_queue(linked_queue queue) {

    QNode node = malloc(sizeof(struct queue_node));
    if (node == NULL) return 0;

    queue->front = queue->rear = node;
    return 1;

}

_Bool offer_queue(linked_queue queue, T element) {

    QNode node = malloc(sizeof(struct queue_node));
    if (node == NULL) return 0;

    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;

}

T poll_queue(linked_queue queue) {

    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;

    if (queue->rear == node) queue->rear = queue->front; 
    free(node);
    return e;

}

void pre_order1(Node root) {

    if(root == NULL) return;

    printf("%c", root->element);
    pre_order1(root->left);
    pre_order1(root->right);

}
void pre_order2(Node root) {

    struct stack_node stack;
    init_stack(&stack);

    while (root || !is_empty(&stack)) {
        while (root) {
            push_stack(&stack, root);
            printf("%c", root->element);
            root = root->left;
        }
        root = pop_stack(&stack);
        root = root->right;
    }

}

void in_order1(Node root) {

    if (root == NULL) return;

    in_order1(root->left);
    printf("%c", root->element);
    in_order1(root->right);

}
void in_order2(Node root) {

    struct stack_node stack;
    init_stack(&stack);

    while (root || !is_empty(&stack)) {
        while (root) {
            push_stack(&stack, root);
            root = root->left;
        }
        root = pop_stack(&stack);
        printf("%c", root->element);
        root = root->right;
    }

}

void post_order1(Node root) {

    if (root == NULL) return;
                      
    post_order1(root->left);
    post_order1(root->right);
    printf("%c", root->element);

}
void post_order2(Node root) {

    struct stack_node stack;
    init_stack(&stack);

    while (root || !is_empty(&stack)) {
        while (root) {
            push_stack(&stack, root);
            root->flag = 0;
            root = root->left;
        }
        root = peek_stack(&stack);
        if (root->flag == 0) {
            root->flag = 1;
            root = root->right;
        } else {
            printf("%c", root->element);
            pop_stack(&stack);
            root = NULL;
        }
    }

}

void level_order(Node root) {

    struct Queue queue;
    init_queue(&queue);
    offer_queue(&queue, root);

    while (!is_qempty(&queue)) {
        Node node = poll_queue(&queue);
        printf("%c", node->element);
        if (node->left) offer_queue(&queue, node->left);
        if (node->right) offer_queue(&queue, node->right);
    }

}

int main() {

    Node a = malloc(sizeof(struct tree_node));
    Node b = malloc(sizeof(struct tree_node));
    Node c = malloc(sizeof(struct tree_node));
    Node d = malloc(sizeof(struct tree_node));
    Node e = malloc(sizeof(struct tree_node));
    Node f = malloc(sizeof(struct tree_node));
    a->element = 'A'; b->element = 'B'; c->element = 'C';
    d->element = 'D'; e->element = 'E'; f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = e->right = NULL;
    e->left = e->right = NULL;
    f->left = f->right = NULL;

    //pre_order1(a);
    //pre_order2(a);

    //in_order1(a);
    //in_ordr2(a);

    //post_order1(a);
    //post_order2(a);

    level_order(a);

    return 0;

}

