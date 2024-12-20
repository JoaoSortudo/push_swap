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
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long int	ft_atoll(const char *str)
{
	long int	result;
	int			i;
	int			symb;

	result = 0;
	symb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symb *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * symb);
}

int	fill_stack(t_stack *stack, int argc, char **argv)
{
	long int	value;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		value = ft_atoll(argv[i]);
		if (value > 2147483647 || value < -2147483648)
			return (0);
		if (!push(stack, value))
			return (0);
		i++;
	}
	// if (has_double(stack))
	// 	return (0);
	return (1);
}
