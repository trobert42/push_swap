/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:44 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 14:06:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

unsigned int	get_max_lis(t_stack *stack, int *lis, int size)
{
	unsigned int	max;
	int				i;

	i = 0;
	max = 0;
	while (i < size)
	{
		if ((int)max < lis[i])
			max = lis[i];
		i++;
	}
	stack->size_lis = max;
	return (max);
}

int	*get_suite3(int max, int size, int *arr, int *index)
{
	int	i;
	int	*suite;

	suite = malloc(sizeof(int) * max);
	if (!suite)
		return (0);
	i = size - 1;
	while (max > 0)
	{
		if (index[i] == 1 && max > 0)
		{
			suite[max - 1] = arr[i];
			max--;
		}
		i--;
	}
	return (suite);
}

void	ft_be_one(int *lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
		lis[i++] = 1;
}
