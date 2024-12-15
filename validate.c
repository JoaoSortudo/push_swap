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

int	validate_atoi_result(const char *str, long result)
{
	int	i;

	if (result > 2147483647 || result < -2147483648)
		return (0);
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	is_number(char *str)
{
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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	symb;

	result = 0;
	symb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			symb *= -1;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (!validate_atoi_result(str, result))
		return (0);
	return (result * symb);
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
			return (0);
		error = 0;
		value = ft_atoi(argv[i]);
		if (error || !push(stack, value))
			return (0);
		i++;
	}
	return (1);
}
