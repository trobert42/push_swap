/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/27 17:17:24 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	to_the_top_a(t_stack *stack, t_array *array1)
{
	int	i;
	int	y;

	i = get_up_moves(array1);
	y = get_down_moves(array1);
	if (i < y)
		while (i-- != 0)
			ra(stack);
	else
		while (y-- != 0)
			rra(stack);
}

void	to_the_top_b(t_stack *stack, t_array *array1)
{
	int	i;
	int	y;

	i = get_up_moves(array1);
	y = get_down_moves(array1);
	if (i < y)
		while (i-- != 0)
			rb(stack);
	else
		while (y-- != 0)
			rrb(stack);
}

int	placing(t_array *array, t_stack *a)
{
	t_array	*next;
	int		i;
	int		j;

	if (find_smallest_array(&a->top)->index > array->index)
		return (0);
	if (find_greatest_array(&a->top)->index < array->index)
		return (1);
	next = find_next_array(&a->top, array->index);
	i = get_up_moves(next);
	j = get_down_moves(next);
	if (i <= j)
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
	i = get_up_moves(b->top);
	j = get_down_moves(b->top);
	if (i <= j)
		count += i;
	else
		count += j;
	count += placing(b->top, a);
	return (count + 1);
}

t_array	*next_to_push(t_stack *a, t_stack *b)
{
	t_array	*top;
	t_array	*push;

	top = b->top;
	while (b->top != 0)
	{
		b->top->score = scoring_points(a, b);
		b->top = b->top->next;
	}
	b->top = top;
	push = find_smallest_score(&b->top);
	return (push);
}
