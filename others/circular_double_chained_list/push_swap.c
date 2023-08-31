/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/17 11:51:32 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_array *top, int size)
{
	int	i;
	t_array	*lst;

	i = 1;
	lst = (*top).next;
	while (i < size)
	{
		if ((*top).nbr > (*lst).nbr)
			return (-1);
		top = lst;
		lst = (*lst).next;
		i++;
	}
	return (1);
}

void	algo1(t_stack *a)
{
	if (a->top->index == 2)
	{
		if (a->top->next->index == 1)
			sa(a);
		else
			rra(a);
	}
	else if(a->top->index == 3)
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

void	algo2(t_stack *a, t_stack *b)
{
	int	size;
	t_array	*temp;

	size = get_size_stack(a);
	while (size < (size * 0,33 + 1))
	{
		temp = find_next_nbr(&a->top, 1);
		to_the_top(a, temp);
		pb(a, b);
		find_smallest(&a->top);
	}
}


void push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		ft_printf("\n");
	else if (a->size == 2)
	{
		if (check_order(a->top, a->size) == -1)
			sa(a);
	}
	else if (a->size == 3)
		algo1(a);
	else if (a->size > 3 && a->size < 50)
		algo2(a, b);
	//else
	//	algo3();
	ft_printf("ok");
}
