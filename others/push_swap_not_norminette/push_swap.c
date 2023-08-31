/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:17 by trobert           #+#    #+#             */
/*   Updated: 2022/03/26 17:40:18 by zerudo           ###   ########.fr       */
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

int	get_size_list(int *lst)
{
	int	i;
	i = 0;
	while (lst[i] != 0)
		i++;
	return (i);
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
	t_array	*temp;
	t_array	*temp1;
	t_array	*temp2 = NULL;
	t_array	*temp3;
	t_array	*top;


	if (a->size == 4)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
	}
	top = a->top;
	temp1 = find_smallest(&a->top);
	temp1->index_algo2 = temp1->index;
	temp1->index = 1;
	temp3 = find_greatest(&a->top);
	temp3->index_algo2 = temp3->index;
	temp3->index = 3;
	while (a->top != 0)
	{
		if (a->top != temp1 && a->top != temp3)
			temp2 = a->top;
		a->top = a->top->next;
	}
	temp2->index_algo2 = temp2->index;
	temp2->index = 2;
	a->top = top;
//	ft_printf("temp index[%d]\n", temp1->index);
//	ft_printf("temp index[%d]\n", temp2->index);
//	ft_printf("temp index[%d]\n", temp3->index);
	
	if (check_order(a) == -1)
		algo1(a);
	
//	ft_printf("displaying a stack\n");
//	display_list(&a->top);
//	ft_printf("displaying b stack\n");
//	display_list(&b->top);
	
	temp1->index = temp1->index_algo2;
//	ft_printf("temp index[%d]\n", temp1->index);
	temp2->index = temp2->index_algo2;
//	ft_printf("temp index[%d]\n", temp2->index);
	temp3->index = temp3->index_algo2;
//	ft_printf("temp index[%d]\n", temp3->index);

	int size_b;
	size_b = get_size_stack(b);
	while (size_b != 0)
	{
		temp = next_to_push(a, b);
		push_and_place(a, b, temp);
		size_b = get_size_stack(b);
//		ft_printf("displaying a stack\n");
//		display_list(&a->top);
//		ft_printf("displaying b stack\n");
//		display_list(&b->top);
	}
	to_the_top(a, find_smallest(&a->top));
//	if (check_order(a) == 1)
//		display_list(&a->top);
}

void	algo3(t_stack *a, t_stack *b)
{
	int	*list;
	int	*suite;
	t_array *temp;

	//-----------------get LIS-----------------------//
	list = get_in_list(&a->top, a->size);
	suite = get_suite(a, list, a->size);
	int i = 0;
	while (i < a->size_lis)
	{
		//ft_printf("suite[%d] = %d\n", i, suite[i]);
		i++;
	}
	//display_list(&a->top);
	//-----PUSH INTO B NON LIS NBRS------------------//
	while (find_next_no_lis(a,suite) != 0)
	{
		temp = find_next_no_lis(a, suite);
		//ft_printf("temp.nbr = [%d]\n", temp->nbr);
		to_the_top(a, temp);
		pb(a, b);
	//	display_list(&a->top);
	}
	temp = find_smallest(&a->top);
	to_the_top(a, temp);
	//ft_printf("displaying a stack\n");
	//display_list(&a->top);
	//ft_printf("displaying b stack\n");
	//display_list(&b->top);
	//------SCORING, PUSHING BACK INTO A AND PLACING------//
	int	size_b;
	size_b = get_size_stack(b);
	while (size_b != 0)
	{
		temp = next_to_push(a, b);
		push_and_place(a, b, temp);
		size_b = get_size_stack(b);
		//ft_printf("displaying a stack\n");
		//display_list(&a->top);
		//ft_printf("displaying b stack\n");
		//display_list(&b->top);
	}
	//------------LAST CHECK------------------------------//
	to_the_top(a, find_smallest(&a->top));
//	if (check_order(a) == 1)
//		display_list(&a->top);
	free(suite);
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
	else if (a->size > 3 && a->size < 6)
		algo2(a, b);
	else if (a->size > 3 && a->size < 1000)
		algo3(a, b);
}
