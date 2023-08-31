/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/30 10:59:17 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		ft_printf("\n");
	else if (a->size == 2)
	{
		if (check_order(a) == -1)
			sa(a);
	}
	else if (a->size == 3)
		algo1(a);
	else if (a->size > 3 && a->size < 6)
		algo2(a, b);
	else if (a->size > 3 && a->size < 1000)
		algo3(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_var(&a, &b);
	if (arg_is_valid(&a, argc, argv) != 1 || get_stack_size(&a) < 2)
		free_list(&a, get_stack_size(&a));
	else
	{
		a.size = get_stack_size(&a);
		init_index(a.top, a.top->next);
		init_prev(&a.top);
		if (check_order(&a) == -1)
			push_swap(&a, &b);
		free_list(&a, get_stack_size(&a));
		free_list(&b, get_stack_size(&b));
	}
	return (0);
}
