/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:02 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/11 18:09:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_array *top, int argc)
{
	int	j;
	t_array *temp = NULL;
	t_array *lst = NULL;

	j = 1;
	lst = (*top).next; 
	while (j < argc - 1)
	{
		if (j == 1)
			free(top);
		else
		{
			temp = (*lst).next;
			free(lst);
			lst = temp;
		}
		j++;
	}
	if (argc == 3) 
		free(lst);
	free(temp);
}
