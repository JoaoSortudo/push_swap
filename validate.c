/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 20:53:16 by jpires-n          #+#    #+#             */
/*   Updated: 2024-12-03 20:53:16 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	validate_atoi_result(const char *str, long result)
// {
// 	if (result > 2147483647 || result < -2147483648)
// 		return (0);
// 	return (1);
// }


int	is_number(char *str)
{
	if (!str || !*str) // Verifica string vazia
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str) // Verifica caso apenas tenha um sinal
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *error)
{
	int		i;
	long	result;
	int		symb;

	*error = 0;
	result = 0;
	symb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		symb = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result * symb > 2147483647 || result * symb < -2147483648)
			*error = 1;
	}
	if (str[i] != '\0')
		*error = 1;
	return (*error ? 0 : (int)(result * symb));
}


int	fill_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;
	int	error;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			write(2, "Invalid argument\n", 17);
			return (0);
		}
		value = ft_atoi(argv[i], &error);
		if (error)
		{
			write(2, "Conversion error\n", 17);
			return (0);
		}
		if (!push(stack, value))
		{
			write(2, "Push error\n", 11);
			return (0);
		}
		i++;
	}
	return (1);
}
