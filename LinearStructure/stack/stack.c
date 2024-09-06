#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct Stack {

    E *array;
    int capactity;
    int top;
    
};
typedef struct Stack *array_stack;

_Bool is_empty(array_stack stack) {
    return stack->top == -1;
}

_Bool init_stack(array_stack stack) {

    stack->array = malloc(sizeof(E) * 10);

    if (stack->array == NULL) return 0;

    stack->capactity = 10;
    stack->top = -1;
    return 1;

}

_Bool push_stack(array_stack stack, E element) {

    if (stack->top + 1 == stack->capactity) {
        int new_capacity = stack->capactity + (stack->capactity >> 1);
        E *new_array = realloc(stack->array, new_capacity * sizeof(E));
        if (new_array == NULL) return 0;
        stack->array = new_array;
        stack->capactity = new_capacity;
    }

    stack->array[stack->top + 1] = element;
    stack->top++;
    return 1;

}

E pop_stack(array_stack stack) {
    return stack->array[stack->top--];
}

int size_stack(array_stack stack) {

    if (is_empty(stack)) return 0;
    return stack->top + 1;

}

E find_value(array_stack stack, int index) {

    if (index < 0 || index > stack->top) return 0;
    return stack->array[index];

}

int get_index(array_stack stack, E element) {

    for (int i = 0; i <= stack->top; ++i) {
        if (stack->array[i] == element) return i;
    }
    return -1;

}

_Bool delete_list(array_stack stack, int index) { // TODO

    if (index < 0 || index > stack->top) return 0;

    

}

void print_stack(array_stack stack) {

    for (int i = 0; i < stack->top + 1; ++i) printf("%d ", stack->array[i]);
    printf("\n");

}

int main() {

    struct Stack stack;
    init_stack(&stack);
    for (int i = 0; i < 5; ++i) push_stack(&stack, i*100);
    
    /*print_stack(&stack);

    printf("%d ", size_stack(&stack));

    printf("%d ", find_value(&stack, 3));

    int index = get_index(&stack, 200);
    printf("%d", index);*/

    while (!is_empty(&stack)) printf("%d ", pop_stack(&stack));

    return 0;

}
