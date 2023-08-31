/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/05/17 14:53:57 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_array	*ft_new(int value)
{
	t_array	*new;

	new = malloc(sizeof(t_array));
	if (!new)
		return (0);
	new->nbr = value;
	new->index = 1;
	new->score = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_array	*lstfirst(t_array *list)
{
	if (!list)
		return (0);
	while (list->prev != 0)
		list = list->prev;
	return (list);
}

t_array	*lstlast(t_array *list)
{
	if (!list)
		return (0);
	while (list->next != 0)
		list = list->next;
	return (list);
}
