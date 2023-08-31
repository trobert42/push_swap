/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/30 14:06:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_and_place(t_stack *a, t_stack *b, t_array *push)
{
	t_array	*next;

	to_the_top_b(b, push);
	next = find_next_array(&a->top, push->index);
	if (next->index > push->index)
	{
		to_the_top_a(a, next);
		pa(a, b);
	}
	else
	{
		to_the_top_a(a, find_smallest_array(&a->top));
		pa(a, b);
		ra(a);
	}
}

void	find_up_push(t_stack *a, t_stack *b)
{
	t_array	*temp;
	int		size_b;

	size_b = get_stack_size(b);
	while (size_b != 0)
	{
		temp = next_to_push(a, b);
		push_and_place(a, b, temp);
		size_b = get_stack_size(b);
	}
	to_the_top_a(a, find_smallest_array(&a->top));
}

void	algo3(t_stack *a, t_stack *b)
{
	int		*arr;
	int		*suite;
	t_array	*temp;

	arr = get_in_array(&a->top, a->size);
	if (arr)
	{
		suite = get_suite(a, arr, a->size);
		if (suite)
		{
			while (find_next_no_lis(a, suite) != 0)
			{
				temp = find_next_no_lis(a, suite);
				to_the_top_a(a, temp);
				pb(a, b);
			}
			temp = find_smallest_array(&a->top);
			to_the_top_a(a, temp);
			find_up_push(a, b);
			free(suite);
		}
		free(arr);
	}
}
