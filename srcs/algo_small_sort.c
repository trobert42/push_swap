/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/30 10:48:38 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo1(t_stack *a)
{
	if (a->top->index == 2)
	{
		if (a->top->next->index == 1)
			sa(a);
		else
			rra(a);
	}
	else if (a->top->index == 3)
	{
		if (a->top->next->index == 2)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else
	{
		rra(a);
		sa(a);
	}
}
