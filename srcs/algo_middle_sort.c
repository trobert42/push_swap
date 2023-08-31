/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_middle_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/30 10:48:35 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_index_quickly(t_stack *a, t_array *t1, t_array *t2, t_array *t3)
{
	t_array	*top;

	top = a->top;
	t1 = find_smallest_array(&a->top);
	t1->index_algo2 = t1->index;
	t1->index = 1;
	t3 = find_greatest_array(&a->top);
	t3->index_algo2 = t3->index;
	t3->index = 3;
	while (a->top != 0)
	{
		if (a->top != t1 && a->top != t3)
			t2 = a->top;
		a->top = a->top->next;
	}
	t2->index_algo2 = t2->index;
	t2->index = 2;
	a->top = top;
}

void	algo2(t_stack *a, t_stack *b)
{
	t_array	*t1;
	t_array	*t2;
	t_array	*t3;
	t_array	*top;

	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	if (a->size != 4)
		pb(a, b);
	pb(a, b);
	swap_index_quickly(a, t1, t2, t3);
	if (check_order(a) == -1)
		algo1(a);
	top = a->top;
	while (a->top != 0)
	{
		a->top->index = a->top->index_algo2;
		a->top = a->top->next;
	}
	a->top = top;
	find_up_push(a, b);
}
