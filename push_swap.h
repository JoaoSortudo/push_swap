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

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node *top;
	int    size;
} t_stack;

// Funções para as pilhas
t_stack *init_stack(void);
void    free_stack(t_stack *stack);
int     push(t_stack *stack, int value);
int     pop(t_stack *stack);

// Funções auxiliares
int     fill_stack(t_stack *stack, int argc, char **argv);
void    sort(t_stack *a, t_stack *b);

#endif
