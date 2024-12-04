#include "push_swap.h"

void pb(t_stack *a, t_stack *b) {
    if (a->size > 0) {
        int value = pop(a);
        push(b, value);
    }
}

void sb(t_stack *stack) {
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

void rb(t_stack *stack) {
    t_node *first;
    t_node *last;

    if (stack->size < 2)
        return;
    first = stack->top;
    stack->top = first->next;

    last = stack->top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = first;
    first->next = NULL;
}

void rrb(t_stack *stack) {
    t_node *prev;
    t_node *last;

    if (stack->size < 2)
        return;
    last = stack->top;
    prev = NULL;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
}