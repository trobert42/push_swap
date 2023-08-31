/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:58:07 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 18:01:29 by zerudo           ###   ########.fr       */
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
			{
				ft_printf("Error\n");
				ft_printf("il y a un doublon : argv[%d] et argv[%d] \n", i, j);
				ft_printf("ft_atoi(argv[%d]) : %d  & ft_atoi(argv[%d]) : %d  \n", i,  ft_atoi(argv[i]), j , ft_atoi(argv[j]));
				return (-1);
			}
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
	{
		ft_printf("nbr too low, try some weed to get higher \n");
		return (-1);
	}
	else if (nbr > 2147483647)
	{
		ft_printf("nbr too high, don't smoke weed kids \n");
		return (-1);
	}
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
		{
			ft_printf("Error\n");
			ft_printf("come on, did you really think i didn't check about that? silly evaluator!\n");
			return (-1);
		}
		if (check_int_max_min(ft_atoll(argv[i])) == -1)
			return (-1);
		if (check_sign(argv[i]) == -1)
		{
			ft_printf("Error\n");
			ft_printf("u can have a '+' or a '-' AND the nbr, or the nbr only, otherwise its error man \n");
			return (-1);
		}
		j = 1;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error\n");
				ft_printf("try a number maybe ? :/ \n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_is_valid(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("Error\n");
		ft_printf("not enough args \n");
		return (-1);
	}
	if (check_int(argc, argv) == -1 || check_doubles(argc, argv) == -1 )
		return (-1);
	return (1);
}
