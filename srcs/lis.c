/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:44 by zerudo            #+#    #+#             */
/*   Updated: 2022/05/23 15:35:09 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*get_lis_index(int *lis, int size, int max)
{
	int	i;
	int	*index;

	i = size - 1;
	index = malloc(sizeof(int) * size);
	if (!index)
		return (0);
	while (i >= 0)
	{
		if (lis[i] == max)
		{
			index[i] = 1;
			max--;
		}
		else
			index[i] = 0;
		i--;
	}
	return (index);
}

int	*get_suite2(t_stack *stack, int *arr, int size, int *lis)
{
	unsigned int	max;
	int				*index;
	int				*suite;

	max = get_max_lis(stack, lis, size);
	index = get_lis_index(lis, size, max);
	free(lis);
	if (!index)
		return (0);
	suite = get_suite3(max, size, arr, index);
	free(index);
	return (suite);
}

int	*get_suite(t_stack *stack, int *arr, int size)
{
	int	*lis;
	int	*suite;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * size);
	if (!lis)
		return (0);
	ft_be_one(lis, size);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	suite = get_suite2(stack, arr, size, lis);
	return (suite);
}

int	*get_in_array(t_array **start, int size)
{
	int		*arr;
	int		i;
	t_array	*top;

	i = 0;
	top = *start;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (*start != 0)
	{
		arr[i] = (*start)->nbr;
		i++;
		*start = (*start)->next;
	}
	*start = top;
	return (arr);
}
