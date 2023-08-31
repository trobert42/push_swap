/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 10:49:20 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	if (get_stack_size(a) > 1)
		swapfront(&a->top);
	if (get_stack_size(b) > 1)
		swapfront(&b->top);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	if (get_stack_size(a) > 1)
		addback(&a->top);
	if (get_stack_size(b) > 1)
		addback(&b->top);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	if (get_stack_size(a) > 1)
		addfront(&a->top);
	if (get_stack_size(b) > 1)
		addfront(&b->top);
}
