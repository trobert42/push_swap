/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/17 15:24:10 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_array	*ft_new(int value, int argc)
{
	t_array	*new;
	
	new = malloc(sizeof(t_array));
	if (!new)
		return(0);
	new->nbr = value;
	new->index = argc - 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_array	*ft_lstdup(t_array *copy)
{
	t_array	*new;

	new = malloc(sizeof(t_array));
	if (!new)
		return(0);
	new->nbr = copy->nbr;
	new->index = copy->index;
	new->next = copy->next;
	new->prev = copy->prev;
	return (new);
}

t_array	*lstlast(t_array *list)
{
	if (!list)
		return (0);
	while (list->next != 0)
		list = list->next;
	return (list);
}
/*
void	addback(t_array **start)
{
	t_array	*temp;
	t_array	*top;
	
	top = (*start)->next;
	temp = *start;
	*start = lstlast(*start);
	(*start)->next = temp;
	temp->next = 0;
	*start = top;
}

void	swapfront(t_array **start, t_array *new)
{
	t_array	*temp;

	temp = new->next;
	new->next = *start;
	*start = new;
	(*start)->next->next = temp;
}*/

void	addback(t_array **start)
{
	if ((*start)->next)
	*start = (*start)->next;
}

void	addfront(t_array **start)
{
	if ((*start)->prev)
		*start = (*start)->prev;
}

void	swapfront(t_array **start)
{
	int	temp_nbr;
	int	temp_index;

	if ((*start)->next)
	{
		temp_index = (*start)->index;
		temp_nbr = (*start)->nbr;
		(*start)->nbr = (*start)->next->nbr;
		(*start)->index = (*start)->next->index;
		(*start)->next->nbr = temp_nbr;
		(*start)->next->index = temp_index;
	}
}

t_array	*lstdel(t_array *list)
{
	t_array *temp;
	temp = list->next;
	free (list);
	return (temp);
}

