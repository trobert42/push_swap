/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:58:25 by trobert           #+#    #+#             */
/*   Updated: 2022/03/17 12:10:22 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_array
{
	int				index;
	int				nbr;
	struct s_array	*next;
	struct s_array	*prev;
}	t_array;

typedef struct s_stack
{
	int	size;
	t_array *top;
	t_array *bot;
	int	flag_error;
}	t_stack;

int			arg_is_valid(int argc, char **argv);
void		init_var(t_stack *a, t_stack *b);
void		init_index(t_array *x, t_array *y, int argc);
t_array		*init_array(int argc, char **argv);
void		init_prev(t_array **start);
t_array		*find_stop_nbr(t_array **start, int size);
int			check_order(t_array *array, int size);
int			is_sorted_asc(t_array **start);
int			is_sorted_desc(t_array **start);
t_array		*find_smallest(t_array **start);
t_array		*find_next_nbr(t_array **start, int next_nbr);
int			up_count_moves(t_array *top, t_array *nbr);
int			down_count_moves(t_array *bot, t_array *nbr);
t_array		*scoring_index(t_array **start, t_array *array1, t_array *array2);
void		to_the_top(t_stack *stack, t_array *array1);
int			get_size_stack(t_stack *stack);
void		display_list(t_array **start);
void		push_swap(t_stack *a, t_stack *b);
void		free_list(t_array *top, int argc);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *stack);
void		ra(t_stack *stack);
void		rra(t_stack *stack);
void		sb(t_stack *b);
void		rb(t_stack *b);
void		rrb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);


t_array		*ft_new(int value, int argc);
t_array		*ft_not_first(int value, t_array *prev);
t_array		*lstlast(t_array *list);
t_array		*lstlastdiff(t_array *list);
void		addback(t_array **start);
void		addfront(t_array **start);
void		swapfront(t_array **start);
t_array		*lstdel(t_array *list);
//void		lstdel(t_array *list, void (*del)(int));

#endif
