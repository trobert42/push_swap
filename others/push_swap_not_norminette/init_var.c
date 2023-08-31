/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/22 14:29:07 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		have_doubles(int nbr, int *list)
{
	int	i;

	i = 0;
	while(list[i] != 0)
	{
		if (list[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

void	init_index(t_array *x, t_array *y, int argc)
{
	int	i;
	t_array	*start;

	start = x;
	while (x != 0)
	{
		i = 1;
		y = start;
		while (y != 0)
		{
			if (x->nbr < y->nbr && x->nbr != y->nbr)
			{
				x->index = argc - 1 - i;
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

t_array	*init_array(int argc, char **argv)
{
	int	j;
	t_array	*new;
	t_array	*list= NULL;
	t_array	*first = NULL;
	t_array	*temp;
	
	j = 1;
	while (j < argc)
	{
		new = ft_new(atoi(argv[j]), argc);
		if (j == 1)
		{
			first = new;
			temp = first;
		}
		else
		{
			list->next = new;
			new->prev = temp;
			temp = new;
		}
		list = new;
		j++;
	}
	list->next = NULL;
	first->prev = NULL;
	return (first);
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
