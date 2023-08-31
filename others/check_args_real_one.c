/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:58:07 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/27 18:16:48 by zerudo           ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
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

int	arg_is_valid(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	else if (argc < 2 || argc > 1000)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (check_int(argc, argv) == -1 || check_doubles(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	return (1);
}
