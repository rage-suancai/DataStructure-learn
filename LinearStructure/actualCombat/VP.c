#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {

    int top;
    char items[MAX_SIZE];

};

void initialize_stack(struct Stack *stack) {
    stack->top = -1;
}

bool is_empty(struct Stack *stack) {
    return stack->top == -1;
}

bool is_full(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {

    if (is_full(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;

}

char pop(struct Stack *stack) {

    if (is_empty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];

}

char peek(struct Stack *stack) {
    if (is_empty(stack)) return '\0';
}

bool is_valid(char *s) {

    struct Stack stack;
    initialize_stack(&stack);

    for (int i = 0; i < strlen(s); ++i) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(&stack)) return false;
            char top = pop(&stack);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return is_empty(&stack);

}

int main() {

    char s1[] = "()";
    char s2[] = "([)]";
    char s3[] = "{[]}";

    printf("Input: %s\nOutput: %s\n", s1, is_valid(s1) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n", s2, is_valid(s2) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n", s3, is_valid(s3) ? "true" : "false");

    return 0;

}
