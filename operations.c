#include "push_swap.h"

// Troca os dois primeiros elementos da pilha
void sa(t_stack *stack) {
    t_node *first;
    t_node *second;

    if (stack->size < 2)
        return;
    first = stack->top;
    second = stack->top->next;

    first->next = second->next;
    second->next = first;
    stack->top = second;
}

// Move o topo da pilha B para a pilha A
void pa(t_stack *a, t_stack *b) {
    if (b->size > 0) {
        int value = pop(b);
        push(a, value);
    }
}
