/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 10:49:21 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stack *b)
{
	ft_printf("sb\n");
	if (get_stack_size(b) > 1)
		swapfront(&b->top);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	if (get_stack_size(b) > 1)
		addback(&b->top);
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	if (get_stack_size(b) > 1)
		addfront(&b->top);
}

void	pb_2(t_stack *a, t_stack *b)
{
	t_array	*first;
	t_array	*moving;
	t_array	*last;

	moving = a->top;
	first = a->top->next;
	last = lstlast(a->top);
	last->next = NULL;
	first->prev = NULL;
	a->top = first;
	if (b->top == 0)
	{
		b->top = moving;
		b->top->next = NULL;
		b->top->prev = NULL;
	}
	else if (b->top)
	{
		b->top->prev = moving;
		moving->next = b->top;
		moving->prev = NULL;
		b->top = moving;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_array	*moving;

	if (get_stack_size(a) != 0)
	{
		ft_printf("pb\n");
		moving = a->top;
		if (a->top->next == 0)
		{
			b->top->prev = moving;
			moving->next = b->top;
			moving->prev = NULL;
			b->top = moving;
			a->top = NULL;
		}
		else
			pb_2(a, b);
	}
}
