/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/08/03 19:02:51 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	ft_printf("sa\n");
	if (get_stack_size(a) > 1)
		swapfront(&a->top);
}

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	if (get_stack_size(a) > 1)
		addback(&a->top);
}

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	if (get_stack_size(a) > 1)
		addfront(&a->top);
}

void	pa_2(t_stack *a, t_stack *b)
{
	t_array	*first;
	t_array	*moving;
	t_array	*last;

	moving = b->top;
	first = b->top->next;
	last = lstlast(b->top);
	last->next = NULL;
	first->prev = NULL;
	b->top = first;
	if (a->top == 0)
	{
		a->top = moving;
		a->top->next = NULL;
		a->top->prev = NULL;
	}
	else if (a->top)
	{
		a->top->prev = moving;
		moving->next = a->top;
		moving->prev = NULL;
		a->top = moving;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	t_array	*moving;

	if (get_stack_size(b) != 0)
	{
		ft_printf("pa\n");
		moving = b->top;
		if (b->top->next == 0)
		{
			a->top->prev = moving;
			moving->next = a->top;
			moving->prev = NULL;
			a->top = moving;
			b->top = NULL;
		}
		else
			pa_2(a, b);
	}
}
