/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/26 18:00:04 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_list(t_array **start)
{
	t_array	*stop;
	t_array	*top;

	if (*start != 0)
	{
		top = *start;
		stop = lstlast(*start);
		while (*start != stop)
		{
			ft_printf("int[%d]\n", (*start)->nbr, (*start)->index);
			*start = (*start)->next;
		}
		ft_printf("int[%d]", (*start)->nbr, (*start)->index);
		*start = top;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (arg_is_valid(argc, argv) != 1)
		return (0);
	else
	{
		init_var(&a, &b);
		a.size = argc - 1;
		a.top = init_array(argc, argv);
		init_index(a.top, a.top->next, argc);
		init_prev(&a.top);
		if (check_order(&a) == -1)
			push_swap(&a, &b);
		free_list(&a, get_size_stack(&a));
		free_list(&b, get_size_stack(&b));
		return (0);
	}
}
