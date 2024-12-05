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

void ra(t_stack *stack) {
    if (stack->size < 2)
        return;

    t_node *first = stack->top;
    t_node *current = stack->top;

    while (current->next)
        current = current->next;

    stack->top = first->next;
    first->next = NULL;
    current->next = first;
}

void rra(t_stack *stack) {
    if (stack->size < 2)
        return;

    t_node *prev = NULL;
    t_node *current = stack->top;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = stack->top;
    stack->top = current;
}