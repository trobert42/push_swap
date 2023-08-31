/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/24 12:32:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_array	*find_smallest(t_array **start)
{
	t_array	*temp;
	t_array	*top;

	if (*start == 0)
		return (0);
	temp = *start;
	top = *start;
	*start = (*start)->next;
	while (*start != 0)
	{
		if ((*start)->nbr < (*start)->prev->nbr && (*start)->nbr < temp->nbr)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}

t_array	*find_greatest(t_array **start)
{
	t_array	*temp;
	t_array	*top;

	if (*start == 0)
		return (0);
	temp = *start;
	top = *start;
	*start = (*start)->next;
	while (*start != 0)
	{
		if ((*start)->nbr > (*start)->prev->nbr && (*start)->nbr > temp->nbr)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}


t_array	*find_prev(t_array **start, int index)//find an index
{
	(void)index;
	t_array	*top;
	t_array	*bigger;
	t_array	*temp = NULL;

	bigger = find_greatest(start);
	if (*start == 0)
		return (0);
	top = *start;
	temp = *start;
	while (*start != 0)
	{
		if ((*start)->index > temp->index && *start != bigger)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}

t_array	*find_next(t_array **start, int index)//find an index
{
	(void)index;
	t_array	*top;
	t_array	*bigger;
	t_array	*temp = NULL;

	if (*start == 0)
		return (0);
	top = *start;
	bigger = find_greatest(start);
	temp = bigger;
	while (*start != 0)
	{
		if ((*start)->index > top->index)
		{
			if ((*start)->index < temp->index)
				temp = *start;
		}
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}

t_array	*find_last(t_array **start)
{
	t_array	*last;
	t_array	*top;

	top = *start;
	while (*start != 0)
		*start = (*start)->next;
	last = (*start)->prev;
	*start = top;
	return (last);
}

/*t_array	*find_stop_nbr(t_array **start, int size)
{
	int	i;
	int	index_stop;
	t_array	*top;
	t_array	*temp = NULL;

	i = 0;
	index_stop = size * 0.33 + 1; //+1
	top = *start;
	while (*start != 0)
	{
		if (i == index_stop)
		{
			temp = *start;
			*start = top;
			return (temp);
		}
		i++;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}*/

int	up_count_moves(t_array *start)
{
	int	i;
	t_array	*top;

	top = start;
	i = 0;
	while (start != 0)
	{
		start = start->prev;
		i++;
	}
	start = top;
	return (i - 1);
}

int	down_count_moves(t_array *start)
{
	int	y;
	t_array	*top;

	y = 0;
	top = start;
	while (start != 0)
	{
		start = start->next;
		y++;
	}
	start = top;
	return (y); //get down on it
}

int	is_sorted_asc(t_stack *stack)
{
	t_array	*first;
	t_array	*start;

	first = stack->top;
	start = stack->top->next;
	while(start != 0)
	{
		if (start->index < start->prev->index)
		{
			start = first;
			return (0);
		}
		start = start->next;
	}
	start = first;
	return (1);
}

int	is_sorted_desc(t_stack *stack)
{
	t_array	*first;
	t_array	*start;
	
	first = stack->top;
	start = stack->top->next;
	while (start != 0)
	{
		if (start->index > start->prev->index)
		{
			start = first->next;
			return (0);
		}
		start = start->next;
	}
	start = first;
	return (1);
}

	
t_array	*scoring_index(t_array *array1, t_array *array2)
{
	t_array	*temp;
	int	i;
	int	j;
	int	k;
	int	l;
	int	test;

	i = up_count_moves(array1);
	j = down_count_moves(array1);
	k = up_count_moves(array2);
	l = down_count_moves(array2);

	temp = array1;
	if (i > j)
		test = j;
	else
		test = i;
	if (test <= k)
	{
		if (test == l || test == k)
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
	t_array	*temp1 = NULL;
	t_array	*temp2 = NULL;
	t_array	*top;

	top = *start;
	if ((*start)->next == 0)
		return (*start);
	while(*start != 0)
	{
		if ((*start)->index == next_nbr)
			temp1 = *start;
		if ((*start)->index == next_nbr + 1)
			temp2 = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (scoring_index(temp1, temp2));
}

void	to_the_top(t_stack *stack, t_array *array1)
{
	int	i;
	int	y;

	i = up_count_moves(array1);
	y = down_count_moves(array1);
	if (i < y)
		while (i-- != 0)
			ra(stack);
	else
		while (y-- != 0)
			rra(stack);
}

int	get_size_stack(t_stack *stack)
{
	t_array	*start;
	int	i;

	i = 0;
	start = stack->top;
	while (stack->top != 0)
	{
		i++;
		stack->top = stack->top->next;
	}
	stack->top = start;
	return (i);
}
