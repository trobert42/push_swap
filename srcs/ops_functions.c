/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/05/17 16:18:37 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		temp2->prev = NULL;
		temp2->next = temp1;
		temp3->prev = temp1;
	}
	else
	{
		temp2->next = temp1;
		temp2->prev = NULL;
		temp1->next = NULL;
		temp1->prev = temp2;
	}
	*start = top;
}
