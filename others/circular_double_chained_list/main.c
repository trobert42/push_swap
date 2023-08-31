/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:33:40 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/17 14:43:12 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_list(t_array **start)
{
	t_array *stop;
	int	size;

	size = 0;
	stop = (*start)->prev; /// it doesnt stop/////////////// 
	if ((*start)->next != 0)
	{
		ft_printf("int[%d], index[%d], prev[%d], next[%d]\n", (*start)->nbr, (*start)->index, (*start)->prev->nbr, (*start)->next->nbr);
		*start = (*start)->next;
		while (*start != stop)
		{
			ft_printf("int[%d], index[%d], prev[%d], next[%d]\n", (*start)->nbr, (*start)->index, (*start)->prev->nbr, (*start)->next->nbr);
			*start = (*start)->next;
		}
		ft_printf("int[%d], index[%d], prev[%d], next[%d]\n", (*start)->nbr, (*start)->index, (*start)->prev->nbr, (*start)->next->nbr);
		*start = stop->next;
	}
	else
		ft_printf("int[%d], index[%d], prev[NULL], next[NULL]\n", (*start)->nbr, (*start)->index);
}

void	display_rev_list(t_array *bot)
{
	while (bot != NULL)
	{
		ft_printf("%d \n", bot->nbr);
		bot = bot->prev;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
/*	t_array *temp;
	t_array *temp2;
	t_array *temp3;
	t_array	*temp4;*/

	if (arg_is_valid(argc, argv) != 1)
		return (0);
	else
	{
		init_var(&a,&b);
		ft_printf("the array of numbers are valid ! yay :D \n");
		a.top = init_array(argc, argv);
		a.size = argc - 1;
		ft_printf("size of list : %d \n", a.size);
		ft_printf("stack.top [%d] \n", a.top->nbr);
		init_index(a.top, a.top->next, argc);
		init_prev(&a.top);
		display_list(&a.top);
		ft_printf("----------------------------\n");
		if (check_order(a.top, a.size) == -1)
		{
			ft_printf("the list isn't sorted, lets go pushy swapy \n");
			//push_swap(&a, &b);
			pb(&a, &b);////////////////////
			pb(&a, &b);////////////////////
			pb(&a, &b);////////////////////
		}
		else
			ft_printf("list is already sorted ! \n");
	//	if (is_sorted_asc(&a.top) == 1)
	//		ft_printf("that is sorted ascendingly baby! \n");
	//	if (is_sorted_desc(&a.top) == 1)
	//		ft_printf("that is sorted descendingly baby! \n");
		/*temp = find_stop_nbr(&a.top, a.size);
		ft_printf("stop nbr ?: int[%d] \n", temp->nbr);
		temp = a.top->next->next->next;
		temp2 = find_smallest(&a.top, a.top,a.top->next);
		ft_printf("smallest nbr ?: int[%d] \n", temp2->nbr);
		temp3 = scoring_index(&a.top, temp, temp2);
		ft_printf("which one is better to move : temp [%d] or temp2 [%d]? this one !!! int[%d] \n", temp->nbr, temp2->nbr, temp3->nbr);
		display_list(&a.top);
		temp4 = find_next_nbr(&a.top, 1);
		ft_printf("next index: [%d], int: [%d] \n", temp4->index, temp4->nbr);
		display_list(&a.top);
		to_the_top(&a, temp4);
		ft_printf("size stack : %d \n", get_size_stack(&a));*/
		//free_list(a.top, argc);
		return (0);
	}
}
