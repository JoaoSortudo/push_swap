/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsB.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 18:18:21 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-05 18:18:21 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (a->size > 0)
	{
		value = pop(a);
		push(b, value);
	}
	write(1, "pb", 2);
	write(1, "\n", 1);
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack->size < 2)
		return ;
	last = stack->top;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	write(1, "rrb", 2);
	write(1, "\n", 1);
}
