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

int is_number(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return (0);
    while (*str) {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int ft_atoi_safe(char *str, int *error) {
    long result = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str) {
        result = result * 10 + (*str - '0');
        if (result > 2147483647 || result < -2147483648) {
            *error = 1;
            return (0);
        }
        str++;
    }
    return ((int)(result * sign));
}

int fill_stack(t_stack *stack, int argc, char **argv) {
    int i = 1;
    int value, error;

    while (i < argc) {
        if (!is_number(argv[i]))
            return (0);
        error = 0;
        value = ft_atoi_safe(argv[i], &error);
        if (error || !push(stack, value))
            return (0);
        i++;
    }
    return (1);
}
