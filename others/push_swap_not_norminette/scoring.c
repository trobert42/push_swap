/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 12:18:04 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if ((*start)->score < (*start)->prev->score && (*start)->score < temp->score)
			temp = *start;
		*start = (*start)->next;
	}
	*start = top;
	return (temp);

}

int	placing(t_array *array, t_stack *a)
{
	t_array	*next;
	int	i;
	int	j;

	if (find_smallest(&a->top)->index > array->index)
		return (0);
	if (find_greatest(&a->top)->index < array->index)
		return (1);
	next = find_next(&a->top, array->index); // gotta find the next array but in the stack a
	i = up_count_moves(next); 
	j = down_count_moves(next);
	if (i <= j) /// if the same nbr, is there a better choice ?
		return (i);
	else
		return (j);
}


int	scoring_points(t_stack *a, t_stack *b)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = up_count_moves(b->top);
	j = down_count_moves(b->top);
	if (i <= j) /// if the same nbr, is there a better choice ?
		count += i;
	else
		count += j;
	count += placing(b->top, a);
	return (count + 1); //for the the pb
}


t_array	*next_to_push(t_stack *a, t_stack *b)
{
	t_array	*top;
	t_array	*push;

	top = b->top;
	while (b->top != 0)
	{
		b->top->score = scoring_points(a, b);
	//	ft_printf("nbr : [%d], score [%d]\n", b->top->nbr, b->top->score);
		b->top = b->top->next;
	}
	b->top = top;
	push = find_smallest_score(&b->top);
	return (push);
}

