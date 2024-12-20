/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-15 18:44:50 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-15 18:44:50 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i + 1] && array[i] > array [i + 1])
		{
			ft_swap(&array[i], &array[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static int	find_index(int value, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	convert_to_index(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		i;

	values = malloc(stack->size * sizeof(long int));
	if (!values)
		return ;
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	bubble_sort(values);
	current = stack->top;
	while (current)
	{
		current->value = find_index(current->value, values, stack->size);
		current = current->next;
	}
	free(values);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		convert_to_index(a);
		radix_sort(a, b);
	}
}
