/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-15 18:48:06 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-15 18:48:06 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first = a->top->value;
	int	second = a->top->next->value;
	int	third = a->top->next->next->value;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four_or_five(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		min;
	while (a->size > 3) // Mover os menores elementos para `b`
	{
		current = a->top;
		min = current->value;

		// Encontra o menor elemento
		while (current)
		{
			if (current->value < min)
				min = current->value;
			current = current->next;
		}
		// Move o menor para `b`
		while (a->top->value != min)
			ra(a); // Ajuste com `rra` se preferir
		pb(a, b);
	}
	// Ordena os 3 elementos restantes
	sort_three(a);
	// Retorna os elementos de `b` para `a`
	while (b->size > 0)
		pa(a, b);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_or_five(a, b);
}
