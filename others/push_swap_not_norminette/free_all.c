/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 18:00:57 by zerudo           ###   ########.fr       */
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
