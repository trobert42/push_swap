/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:58:07 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/30 12:42:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	have_doubles_stack(t_array **start)
{
	t_array	*top;
	t_array	*temp1;
	t_array	*temp2;

	top = *start;
	temp1 = *start;
	while (temp1 != 0)
	{
		temp2 = temp1->next;
		while (temp2 != 0)
		{
			if (temp1->nbr == temp2->nbr)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	*start = top;
	return (0);
}

int	get_temp_size(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	special_arg_is_valid(t_stack *a, int argc, char **argv)
{
	char	**temp;
	int		i;
	int		temp_size;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i++], ' ');
		if (!temp)
			return (-1);
		temp_size = get_temp_size(temp);
		if (temp_size == 0 || check_int(temp_size, temp) == -1 || \
				check_doubles(temp_size, temp) == -1)
			return (free_split(temp));
		else
		{
			if (a->top == 0)
				a->top = init_array(a, temp_size, temp);
			else
				a->top = continue_array(a, temp_size, temp);
			free_split(temp);
		}
	}
	return (1);
}
