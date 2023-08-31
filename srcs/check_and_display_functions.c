/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_display_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 10:58:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	have_doubles(int nbr, int *list)
{
	int	i;

	i = 0;
	while (list[i] != 0)
	{
		if (list[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted_asc(t_stack *stack)
{
	t_array	*first;
	t_array	*start;

	first = stack->top;
	start = stack->top->next;
	while (start != 0)
	{
		if (start->index < start->prev->index)
		{
			start = first;
			return (0);
		}
		start = start->next;
	}
	start = first;
	return (1);
}

int	check_order(t_stack *stack)
{
	int		i;
	int		size;
	t_array	*lst;
	t_array	*top;

	i = 1;
	top = stack->top;
	size = get_stack_size(stack);
	if (size == 0 || size == 1)
		return (0);
	lst = stack->top->next;
	while (i++ < size)
	{
		if (stack->top->nbr > (*lst).nbr)
		{
			stack->top = top;
			return (-1);
		}
		stack->top = lst;
		lst = (*lst).next;
	}
	stack->top = top;
	return (1);
}

void	display_list(t_array **start)
{
	t_array	*stop;
	t_array	*top;

	if (*start != 0)
	{
		top = *start;
		stop = lstlast(*start);
		while (*start != stop)
		{
			ft_printf("int[%d], index[%d]\n", (*start)->nbr, (*start)->index);
			*start = (*start)->next;
		}
		ft_printf("int[%d], index[%d]\n]", (*start)->nbr, (*start)->index);
		*start = top;
	}
}

int	is_in_suite(int *list, int nbr, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (list[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
