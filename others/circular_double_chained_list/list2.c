/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/17 12:00:21 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_array	*find_smallest(t_array **start)
{
	t_array	*temp;
	t_array	*stop;

	temp = *start;
	stop = (*start)->prev;
	while (*start != stop)
	{
		if ((*start)->nbr < (*start)->next->nbr && (*start)->nbr < temp->nbr)
			temp = *start;
		*start = (*start)->next;
	}
	if ((*start)->nbr < (*start)->next->nbr && (*start)->nbr < temp->nbr)
		temp = *start;
	*start = stop->next;
	return (temp);
}

t_array	*find_stop_nbr(t_array **start, int size)
{
	int	i;
	int	index_stop;
	t_array	*stop;
	t_array	*temp;

	i = 0;
	index_stop = size * 0.33 + 1; //+1
	stop = (*start)->prev;
	while (*start != stop)
	{
		if (i == index_stop)
		{
			temp = *start;
			*start = stop->next;
			return (temp);
		}
		i++;
		*start = (*start)->next;
	}
	*start = stop->next;
	return (temp);
}

int	up_count_moves(t_array *top, t_array *array1)
{
	int	i;
	t_array	*temp;

	temp = top;
	i = 0;
	while (array1 != top)
	{
		array1 = array1->prev;
		i++;
	}
	ft_printf("i : %d \n", i);
	return (i);
}

int	down_count_moves(t_array *bot, t_array *array1)
{
	int	y;

	y = 0;
	while (array1 != bot)
	{
		array1 = array1->next;
		y++;
	}
	ft_printf("y : %d \n", y);
	return (y + 1); //get down on it
}

int	is_sorted_asc(t_array **start)
{
	t_array	*stop;

	stop = (*start)->prev;
	while(*start != stop)
	{
		if ((*start)->index > (*start)->next->index)
		{
			*start = stop->next;
			return (0);
		}
		*start = (*start)->next;
	}
	*start = stop->next;
	return (1);
}

int	is_sorted_desc(t_array **start)
{
	t_array	*stop;
	
	stop = (*start)->prev;
	while(*start != stop)
	{
		if ((*start)->index < (*start)->next->index)
		{
			*start = stop->next;
			return (0);
		}
		*start = (*start)->next;
	}
	*start = stop->next;
	return (1);
}

t_array	*scoring_index(t_array **start, t_array *array1, t_array *array2)
{
	t_array	*temp;

	int	i;
	int	j;
	int	k;
	int	l;
	int	test;

	i = up_count_moves(*start, array1);
	j = down_count_moves((*start)->prev, array1);
	k = up_count_moves(*start, array2);
	l = down_count_moves((*start)->prev, array2);

	temp = array1;
	if (i > j)
		test = j;
	else
		test = i;
	if (test < k)
	{
		if (test == l)
		{
			if (temp->index > array2->index)
				temp = array2;
		}
		if (test > l)
			temp = array2;
	}
	else if (test < l)
		temp = array2;
	return (temp);
}


t_array	*find_next_nbr(t_array **start, int next_nbr)
{
	t_array	*temp1;
	t_array	*temp2;
	t_array	*stop;

	stop = (*start)->prev;
	while(*start != stop)
	{
		if ((*start)->index == next_nbr)
			temp1 = *start;
		if ((*start)->index == next_nbr + 1)
			temp2 = *start;
		*start = (*start)->next;
	}
	if ((*start)->index == next_nbr)
		temp1 = *start;
	if ((*start)->index == next_nbr + 1)
		temp2 = *start;
	*start = stop->next;
	ft_printf("%d \n", temp1->index);
	ft_printf("%d \n", temp2->index);

	ft_printf("%d, \n", (scoring_index(start, temp1, temp2))->index);
	return (scoring_index(start, temp1, temp2));
}

void	to_the_top(t_stack *stack, t_array *array1)
{
	int	i;
	int	y;

	i = up_count_moves(stack->top, array1);
	y = down_count_moves(stack->top->prev, array1);
	if (i < y)
		while (i-- != 0)
			ra(stack);
	else
		while (y-- != 0)
			rra(stack);
}

int	get_size_stack(t_stack *stack)
{
	t_array	*temp;
	t_array	*stop;
	int	i;

	i = 0;
	temp = stack->top;
	stop = stack->top->prev;
	while (stack->top != stop)
	{
		i++;
		stack->top = stack->top->next;
	}
	stack->top = temp;
	return (i + 1);
}
