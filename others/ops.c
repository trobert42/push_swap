/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 18:22:28 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	ft_printf("sa\n");
	if (get_size_stack(a) > 1)
		swapfront(&a->top);
}

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	if (get_size_stack(a) > 1)
		addback(&a->top);
}

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	if (get_size_stack(a) > 1)
		addfront(&a->top);
}

void	pa(t_stack *a, t_stack *b)
{
	t_array	*first;
	t_array	*moving;
	t_array	*last;

	if (get_size_stack(b) != 0) ///its the opposite for stack b, you gotta check the size sb
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
		{
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
//		ft_printf("displaying a stack \n");
//		display_list(&a->top);
// 		ft_printf("displaying b stack \n");
//		display_list(&b->top);
	}
}



void	pb(t_stack *a, t_stack *b)
{
	t_array	*first;
	t_array	*moving;
	t_array	*last;

	if (get_size_stack(a) != 0) ///its the opposite for stack b, you gotta check the size sb
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
		{
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
//		ft_printf("displaying a stack \n");
//		display_list(&a->top);
//		ft_printf("displaying b stack \n");
//		display_list(&b->top);
	}
}


void	sb(t_stack *b)
{
	ft_printf("sb\n");
	if (get_size_stack(b) > 1)
		swapfront(&b->top);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	if (get_size_stack(b) > 1)
		addback(&b->top);
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	if (get_size_stack(b) > 1)
		addfront(&b->top);
}
