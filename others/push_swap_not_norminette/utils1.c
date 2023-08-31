/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 11:33:55 by zerudo           ###   ########.fr       */
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
	new->score = 0;
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

t_array	*lstfirst(t_array *list)
{
	if (!list)
		return (0);
	list = lstlast(list);
	while (list->prev != 0)
		list = list->prev;
	return (list);
}


t_array	*lstdel(t_array *list)
{
	t_array *temp;
	temp = list->next;
	free (list);
	return (temp);
}



void	addback(t_array **start)
{
	t_array	*top;
	t_array	*moving;
	
	moving = *start;
	top = (*start)->next;

	*start = lstlast(*start);
	(*start)->next = moving;
	moving->prev = *start;
	moving->next = NULL;
	*start = top;
	top->prev = NULL;
}

void	addfront(t_array **start)
{
	t_array	*top;
	t_array	*temp2;

	temp2 = *start;
	top = lstlast(*start);
	*start = lstlast(*start);
	*start = (*start)->prev;
	(*start)->next = NULL;
	temp2->prev = top;
	top->next = temp2;
	top->prev = NULL;
	*start = top;
}
/*
void	swapfront(t_array **start)
{
	int	temp_nbr;
	int	temp_index;
	t_array	*top;

	if ((*start)->next)
	{
		temp_index = (*start)->index;
		temp_nbr = (*start)->nbr;
		(*start)->nbr = (*start)->next->nbr;
		(*start)->index = (*start)->next->index;
		(*start)->next->nbr = temp_nbr;
		(*start)->next->index = temp_index;
	}
}*/


void	swapfront(t_array **start)
{
	t_array	*temp1;
	t_array	*temp2;
	t_array	*temp3;
	t_array	*top;

	top = (*start)->next;
	temp1 = *start;
	temp2 = (*start)->next;
	if ((*start)->next->next)
	{
		temp3 = (*start)->next->next;
		temp1->prev = temp2;
		temp1->next = temp3;
		temp2->prev = 0;
		temp2->next = temp1;
		temp3->prev = temp1;
	}
	else
	{
		temp2->next = temp1;
		temp2->prev = 0;
		temp1->next = 0;
		temp1->prev = temp2;
	}
	*start = top;
}
