/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/22 16:13:35 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_stack *stack)
{
	int	i;
	int	size;
	t_array	*lst;
	t_array	*top;

	i = 1;
	top = stack->top;
	size = get_size_stack(stack);
	if (size == 0 || size == 1)
		return (0); //not enough arg to compare
	lst = stack->top->next;
	while (i < size)
	{
		if (stack->top->nbr > (*lst).nbr)
		{
			stack->top = top;
			return (-1); //no sorted
		}
		stack->top = lst;
		lst = (*lst).next;
		i++;
	}
	stack->top = top;
	return (1);//sorted
}

void	algo_not_smart_asc(t_stack *a, t_stack *b)
{
	t_array	*big;
	t_array	*temp;

	big = find_greatest(&a->top);
	while(is_sorted_asc(a) != 1)
	{
		temp = find_prev(&a->top, big->index - 1);
		to_the_top(a, temp);
		while (temp != big->prev)
		{
			if (b->top->next && b->top->index < b->top->next->index)
				ss(a, b);
			else
				sa(a);
			if (is_sorted_asc(a) == 1)
				break ;
			if ((get_size_stack(b) > 2) && (b->top->index < b->top->next->index) && (b->top->index < find_last(&b->top)->index))
				rr(a,b);
			else
				ra(a);
		}
		big = temp;
	}
}

void	algo_not_smart_desc(t_stack *b)
{
	t_array	*small;
	t_array	*temp;

	small = find_smallest(&b->top);
	while(is_sorted_desc(b) != 1)
	{
		temp = find_prev(&b->top, small->index + 1);
		to_the_top(b, temp);
		while (temp != small->prev)
		{
			sb(b);
			rb(b);
		}
		small = temp;
	}
}



void	algo1(t_stack *a)
{
	if (a->top->index == 2)
	{
		if (a->top->next->index == 1)
			sa(a);
		else
			rra(a);
	}
	else if(a->top->index == 3)
	{
		if (a->top->next->index == 2)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else
	{
		rra(a);
		sa(a);
	}
}

void	algo2(t_stack *a, t_stack *b)
{
	int	size;
	int	stop;
	t_array	*temp;
	t_array	*temp2;

//	ft_printf("algo2 ont the way \n");
	size = get_size_stack(a);
	stop = size - (size * 0.33);
//	ft_printf("stop :%d \n", stop);
//	ft_printf("size stack a :%d \n", size);
	while (size > stop)
	{
		temp2 = find_smallest(&a->top);
		temp = find_next_nbr(&a->top, temp2->index);
		to_the_top(a, temp);
		pb(a, b);
		temp2 = find_smallest(&a->top);
		to_the_top(a, temp2);
		pb(a, b);
		size = get_size_stack(a);
	}
//	ft_printf("A NOT VERY SMART ALGO FOR THE STACK A ------------\n");
	algo_not_smart_asc(a, b);
//	ft_printf("AIN'T SMARTER THAN THE OTHER--------------\n");
	algo_not_smart_desc(b);
	while (get_size_stack(b) != 0)
		pa(a, b);
}


void push_swap(t_stack *a, t_stack *b)
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
	else if (a->size > 3 && a->size < 50)
		algo2(a, b);
	//else
	//	algo3();
}
