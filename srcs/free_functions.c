/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 12:37:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list2(t_stack *stack)
{
	int		j;
	t_array	*temp;
	t_array	*lst;

	j = 1;
	temp = NULL;
	lst = stack->top->next;
	while (lst != 0)
	{
		if (j == 1)
			free(lst->prev);
		else
		{
			temp = (*lst).next;
			free(lst);
			lst = temp;
		}
		j++;
	}
}

void	free_list(t_stack *stack, int size)
{
	if (size > 1)
		free_list2(stack);
	else if (size == 1)
		free(stack->top);
}

int	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	if (temp)
		free(temp);
	return (-1);
}

void	free_and_quit(t_stack *a, char **temp, int temp_size)
{
	int	i;

	i = 0;
	a->top = lstfirst(a->top);
	while (a->top != 0)
	{
		free(a->top);
		a->top = a->top->next;
	}
	while (i < temp_size)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	exit(0);
}
