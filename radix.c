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

void	convert_to_index(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		i;
	int		j;

	values = malloc(stack->size * sizeof(int));
	if (!values)
		return ;
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value; // Armazena os valores da pilha em um array
		current = current->next;
	}
	// Ordena os valores
	for (i = 0; i < stack->size - 1; i++)
		for (j = i + 1; j < stack->size; j++)
			if (values[i] > values[j])
			{
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
	// Substitui valores pelos índices
	current = stack->top;
	while (current)
	{
		for (i = 0; i < stack->size; i++)
			if (current->value == values[i])
			{
				current->value = i;
				break ;
			}
		current = current->next;
	}
	free(values);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits; // Quantidade de bits no maior número
	int	i;
	int	j;
	int	size;

	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0) // Calcula o número de bits necessários
		max_bits++;
	i = 0;
	while (i < max_bits) // Para cada bit
	{
		j = 0;
		while (j < size) // Para cada número na pilha
		{
			if (((a->top->value >> i) & 1) == 0) // Verifica o bit atual
				pb(a, b); // Bit 0 -> vai para b
			else
				ra(a); // Bit 1 -> rotaciona em a
			j++;
		}
		while (b->size > 0)
			pa(a, b); // Retorna todos os números para a
		i++;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		small_sort(a, b); // Ordenação especial para pilhas pequenas
	else
	{
		convert_to_index(a); // Converte valores para índices
		radix_sort(a, b);    // Aplica o Radix Sort
	}
}
