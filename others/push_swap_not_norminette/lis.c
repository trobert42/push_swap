/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:44 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 16:33:17 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	*get_suite2(int *lis, int size, int max)
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
	//	ft_printf("index[%d] = %d\n", i, index[i]);
		i--;
	}
	return (index);
}

int	*get_suite(t_stack *stack, int *arr, int size)
{
	int	*suite;
	int	*lis;
	int	*index;
	unsigned int	max = 0;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * size);
	i = 0;
	while(i < size)
		lis[i++] = 1;
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
	i = 0;
	while (i < size)
	{
		if ((int)max < lis[i])
		{
			max = lis[i];
//			printf("max value = [%d]\n", max);
		}
		i++;
	}
	stack->size_lis = max;
//	ft_printf("max = %d\n", max);
	index = get_suite2(lis, size, max);
	suite = malloc(sizeof(int) * max);
	if (!suite)
		return(0);
	i = size - 1;
	j = 0;
	while (max > 0)
	{
		if (index[i] == 1 && max > 0)
		{
			suite[max - 1] = arr[i];
//			ft_printf("suite[%d] = %d\n", max, suite[max - 1]);
			max--;
		}
		i--;
	}
	free(arr);
	free(lis);
	free(index);
	return (suite);
}



int	is_in_suite(int *list, int nbr, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (list[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	*get_in_list(t_array **start, int size)
{
	int	*arr;
	int	i;
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
