/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 20:53:26 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-03 20:53:26 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */


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

void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
}

void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
}

void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
}
