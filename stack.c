/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 20:52:58 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-03 20:52:58 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack *init_stack(void) {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void free_stack(t_stack *stack) {
    t_node *tmp;
    while (stack->top) {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    free(stack);
}

int push(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    return (1);
}

int pop(t_stack *stack) {
    t_node *tmp;
    int value;

    if (!stack->top)
        return (0);
    tmp = stack->top;
    value = tmp->value;
    stack->top = tmp->next;
    free(tmp);
    stack->size--;
    return (value);
}
