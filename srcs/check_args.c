/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:58:07 by zerudo            #+#    #+#             */
/*   Updated: 2022/08/03 18:58:24 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sign(char *argv)
{
	if (argv[0] == '-' || argv[0] == '+' || (argv[0] >= '0' && argv[0] <= '9'))
	{
		if (argv[0] == '-' && ft_strlen(argv) == 1)
			return (-1);
		if (argv[0] == '+' && ft_strlen(argv) == 1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int	check_int_max_min(long long nbr)
{
	if (nbr < -2147483648)
		return (-1);
	else if (nbr > 2147483647)
		return (-1);
	return (1);
}

int	check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (check_int_max_min(ft_atoll(argv[i])) == -1)
			return (-1);
		if (check_sign(argv[i]) == -1)
			return (-1);
		j = 1;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_is_valid(t_stack *a, int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	else if (argc < 2 || argc > 600)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (special_arg_is_valid(a, argc, argv) == -1 || \
			have_doubles_stack(&a->top) == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}
