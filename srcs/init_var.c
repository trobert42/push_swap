/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 14:58:06 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_array *x, t_array *y)
{
	int		i;
	t_array	*start;

	start = x;
	while (x != 0)
	{
		i = 2;
		y = start;
		while (y != 0)
		{
			if (x->nbr > y->nbr && x->nbr != y->nbr)
			{
				x->index = i;
				i++;
			}
			y = y->next;
		}
		x = x->next;
	}
}

void	init_prev(t_array **start)
{
	t_array	*top;
	t_array	*temp;
	t_array	*stop;

	top = *start;
	*start = lstlast(*start);
	stop = *start;
	*start = top;
	while ((*start)->next != stop)
	{
		temp = *start;
		(*start) = (*start)->next;
		(*start)->prev = temp;
	}
	*start = top;
}

void	init_var(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	a->flag_error = 0;
	b->top = NULL;
	b->size = 0;
	b->flag_error = 0;
}

t_array	*init_array(t_stack *a, int argc, char **argv)
{
	int		j;
	t_array	*new;
	t_array	*list;
	t_array	*first;
	t_array	*temp;

	new = ft_new(ft_atoi(argv[0]));
	if (!new)
		free_and_quit(a, argv, argc);
	first = new;
	temp = first;
	list = new;
	j = 1;
	while (j < argc)
	{
		new = ft_new(ft_atoi(argv[j++]));
		if (!new)
			free_and_quit(a, argv, argc);
		list->next = new;
		new->prev = temp;
		temp = new;
		list = new;
	}
	return (first);
}

t_array	*continue_array(t_stack *a, int argc, char **argv)
{
	int		j;
	t_array	*new;
	t_array	*top;

	top = a->top;
	a->top = lstlast(a->top);
	j = 0;
	while (j < argc)
	{
		new = ft_new(ft_atoi(argv[j]));
		if (!new)
			free_and_quit(a, argv, argc);
		a->top->next = new;
		new->prev = a->top;
		a->top = a->top->next;
		j++;
	}
	a->top->next = NULL;
	a->top = top;
	return (a->top);
}
