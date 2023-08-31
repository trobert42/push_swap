/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 13:12:06 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_and_place(t_stack *a, t_stack *b, t_array *push)
{
	t_array	*next;

	to_the_top_b(b, push);
	next = find_next(&a->top, push->index);
	if (next->index > push->index)
	{
		to_the_top(a, next);
		pa(a, b);
	}
	else
	{
		to_the_top(a, find_smallest(&a->top));
		pa(a, b);
		ra(a);
	}
}

