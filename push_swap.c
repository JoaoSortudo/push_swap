/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 20:52:49 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-03 20:52:49 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!fill_stack(stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		return (1);
	}
	sort(stack_a, stack_b);
	print_stack(stack_a);
	free_stacks(stack_a, stack_b);
	return (0);
}
