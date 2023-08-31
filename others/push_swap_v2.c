/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/23 10:43:21 by zerudo           ###   ########.fr       */
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
	t_array	*start;
	t_array	*temp;

	start = b->top;
	if (get_size_stack(b) == 2 && is_sorted_desc(b) != 1)
		sb(b);
	else if (b->top == find_smallest(&b->top))
		rb(b);
	else if (b->top->index == (find_prev(&b->top, b->top->next->index))->index)
		sb(b);
	else
	{
		temp = find_next(&b->top, b->top->index);
		while (temp->next != start)
		{
		//	display_list(&b->top);
			sb(b);
				if (is_sorted_desc(b) == 1 || temp->next == start)
					break ;
			rb(b);
		}
		to_the_top(b, find_greatest(&b->top));
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
	pb(a,b);
	while (get_size_stack(a) != 0)
	{
		pb(a, b);
		while (is_sorted_desc(b) != 1)
			algo_not_smart_desc(b);
	}
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
