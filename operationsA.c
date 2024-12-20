/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 18:13:17 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-05 18:13:17 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Troca os dois primeiros elementos da pilha
void	sa(t_stack *stack)
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
	write(1, "sa", 2);
	write(1, "\n", 1);
}

// Move o topo da pilha B para a pilha A
void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->size > 0)
	{
		value = pop(b);
		push(a, value);
	}
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*current;

	if (stack->size < 2)
		return ;
	first = stack->top;
	current = stack->top;
	while (current->next)
		current = current->next;
	stack->top = first->next;
	first->next = NULL;
	current->next = first;
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	prev = NULL;
	current = stack->top;
	if (stack->size < 2)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
	write(1, "rra", 3);
	write(1, "\n", 1);
}
