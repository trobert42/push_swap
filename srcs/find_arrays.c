/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/27 17:09:09 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_array	*find_smallest_array(t_array **start)
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

t_array	*find_greatest_array(t_array **start)
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

t_array	*find_next_array(t_array **start, int index)
{
	t_array	*top;
	t_array	*temp;

	if (*start == 0)
		return (0);
	top = *start;
	temp = find_greatest_array(start);
	while (*start != 0)
	{
		if ((*start)->index > index && (*start)->index < temp->index)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}

t_array	*find_next_no_lis(t_stack *a, int *suite)
{
	t_array	*top;
	t_array	*temp;

	top = a->top;
	while (a->top != 0)
	{
		if (is_in_suite(suite, a->top->nbr, a->size_lis) == 0)
		{
			temp = a->top;
			a->top = top;
			return (temp);
		}
		a->top = a->top->next;
	}
	a->top = top;
	temp = 0;
	return (temp);
}

t_array	*find_smallest_score(t_array **start)
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
		if ((*start)->score < (*start)->prev->score && (*start)->score < \
				temp->score)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);
}
