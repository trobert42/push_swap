/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 10:58:51 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_up_moves(t_array *start)
{
	int		i;
	t_array	*top;

	top = start;
	i = 0;
	while (start != 0)
	{
		start = start->prev;
		i++;
	}
	start = top;
	return (i - 1);
}

int	get_down_moves(t_array *start)
{
	int		y;
	t_array	*top;

	y = 0;
	top = start;
	while (start != 0)
	{
		start = start->next;
		y++;
	}
	start = top;
	return (y);
}

int	get_stack_size(t_stack *stack)
{
	t_array	*start;
	int		i;

	i = 0;
	start = stack->top;
	while (stack->top != 0)
	{
		i++;
		stack->top = stack->top->next;
	}
	stack->top = start;
	return (i);
}

int	get_list_size(int *lst)
{
	int	i;

	i = 0;
	while (lst[i] != 0)
		i++;
	return (i);
}
