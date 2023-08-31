/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:58:25 by trobert           #+#    #+#             */
/*   Updated: 2022/05/23 16:07:05 by trobert          ###   ########.fr       */
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
	int				index_algo2;
	int				nbr;
	int				score;
	struct s_array	*next;
	struct s_array	*prev;
}	t_array;

typedef struct s_stack
{
	t_array	*top;
	int		size;
	int		size_lis;
	int		flag_error;
}	t_stack;

//--------------PARSING && INITIALISATION------------
int				arg_is_valid(t_stack *a, int argc, char **argv);
void			init_var(t_stack *a, t_stack *b);
void			init_index(t_array *x, t_array *y);
t_array			*init_array(t_stack *a, int argc, char **argv);
t_array			*continue_array(t_stack *a, int argc, char **argv);
void			init_prev(t_array **start);
int				special_arg_is_valid(t_stack *a, int argc, char **argv);
int				check_doubles(int argc, char **argv);
int				check_int(int argc, char **argv);
int				have_doubles_stack(t_array **start);

//---------------DISPLAY-----------------------------
void			display_list(t_array **start);

//--------------CHECKS-------------------------------
int				check_order(t_stack *stack);
int				is_sorted_asc(t_stack *stack);
int				is_in_suite(int *list, int nbr, int max);

//--------------GET_UTILS----------------------------
int				get_stack_size(t_stack *stack);
int				get_list_size(int *lst);
int				get_up_moves(t_array *start);
int				get_down_moves(t_array *start);

//---------------FIND ARRAYS-------------------------
t_array			*find_smallest_array(t_array **start);
t_array			*find_greatest_array(t_array **start);
t_array			*find_next_array(t_array **start, int index);
t_array			*find_smallest_score(t_array **start);
t_array			*find_next_no_lis(t_stack *a, int *suite);

//--------------SCORING FUNCTIONS--------------------
int				placing(t_array *array, t_stack *a);
int				scoring_points(t_stack *a, t_stack *b);
void			to_the_top_a(t_stack *stack, t_array *array1);
void			to_the_top_b(t_stack *stack, t_array *array1);
t_array			*next_to_push(t_stack *a, t_stack *b);
void			push_and_place(t_stack *a, t_stack *b, t_array *push);
void			find_up_push(t_stack *a, t_stack *b);

//--------------OPERATIONS---------------------------
void			pb(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			sa(t_stack *stack);
void			ra(t_stack *stack);
void			rra(t_stack *stack);
void			sb(t_stack *b);
void			rb(t_stack *b);
void			rrb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);

//--------------LIS-----------------------------------
int				*get_in_array(t_array **start, int size);
int				*get_suite(t_stack *stack, int *arr, int size);
int				*get_suite3(int max, int size, int *arr, int *index);
int				*get_lis_index(int *lis, int size, int max);
unsigned int	get_max_lis(t_stack *stack, int *lis, int size);
t_array			*find_next_no_lis(t_stack *a, int *suite);
void			ft_be_one(int *lis, int size);

//--------------ALGOs---------------------------------
void			push_swap(t_stack *a, t_stack *b);
void			algo1(t_stack *a);
void			algo2(t_stack *a, t_stack *b);
void			algo3(t_stack *a, t_stack *b);

//--------------CHAINED LIST FUNCTIONS----------------
t_array			*ft_new(int value);
t_array			*lstfirst(t_array *list);
t_array			*lstlast(t_array *list);
void			addback(t_array **start);
void			addfront(t_array **start);
void			swapfront(t_array **start);

//--------------FREE----------------------------------
int				free_split(char **temp);
void			free_list(t_stack *stack, int size);
void			free_and_quit(t_stack *a, char **temp, int temp_size);

#endif
