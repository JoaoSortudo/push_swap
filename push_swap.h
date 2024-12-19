/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 20:52:35 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-03 20:52:35 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	int		size;
}	t_stack;

// Funções para as pilhas
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);

// Funções auxiliares
int		fill_stack(t_stack *stack, int argc, char **argv);
int		validate_atoi_result(const char *str, long result);
int		is_number(char *str);
int	ft_atoi(const char *str, int *error);

// Funções de algoritmos
void	convert_to_index(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four_or_five(t_stack *a, t_stack *b);
void	small_sort(t_stack *a, t_stack *b);

// Operações
void	sa(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pb(t_stack *a, t_stack *b);
void	sb(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
