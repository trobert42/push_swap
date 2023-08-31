/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/17 15:24:09 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	ft_printf("sa\n");
	swapfront(&a->top);
	display_list(&a->top);
}

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	addback(&a->top);
	display_list(&a->top);
}

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	addfront(&a->top);
	display_list(&a->top);
}

void	pb(t_stack *a, t_stack *b)
{
	t_array	*temp1;
	t_array	*temp2;
	t_array	*temp3;

	ft_printf("pb\n");
	a->top = a->top->next;
	temp1 = a->top;
	temp2 = a->top->prev; 
	temp3 = a->top->prev->prev;
	temp3->next = a->top;
	a->top->prev = temp3;
	if (b->top == 0)
	{
		b->top = temp2;
		b->top->next = NULL;
		b->top->prev = NULL;
	}
	else if (b->top->next == NULL)
	{
		b->top->next = temp2;
		b->top->prev = temp2;
		temp2->next = b->top;
		temp2->prev = b->top;
		b->top = b->top->prev;
	}
	else if (b->top->next != NULL)
	{
		(b->top->prev)->next = temp2;
		b->top->prev = temp2;
		temp2->next = b->top;
		temp2->prev = b->top->prev;
		b->top = b->top->prev;
	}
	ft_printf("displaying a stack \n");
	display_list(&a->top);
	ft_printf("displaying b stack \n");
	display_list(&b->top);
}


void	sb(t_stack *b)
{
	ft_printf("sb\n");
	swapfront(&b->top);
	display_list(&b->top);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	addback(&b->top);
	display_list(&b->top);
}

void	rrb(t_stack *b)
{
	ft_printf("rra\n");
	addfront(&b->top);
	display_list(&b->top);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swapfront(&a->top);
	swapfront(&b->top);
	/////display_list(&b->top);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	addback(&a->top);
	addback(&b->top);
	/////display_list(&a->top);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	addfront(&a->top);
	addfront(&b->top);
	///////display_list(&a->top);
}
