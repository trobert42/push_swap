# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:43:19 by trobert           #+#    #+#              #
#    Updated: 2022/08/03 19:03:20 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	algo_small_sort.c\
		algo_middle_sort.c\
		algo_big_sort.c\
		check_and_display_functions.c\
		check_args.c\
		check_special_args.c\
		find_arrays.c\
		free_functions.c\
		get_utils.c\
		init_var.c\
		lis.c\
		lis_utils.c\
		list_functions.c\
		ops_functions.c\
		ops_ab.c\
		ops_a.c\
		ops_b.c\
		push_swap.c\
		scoring.c\

SRCS = ${addprefix srcs/, ${SRC}}

OBJS = ${SRCS:.c=.o}

NAME = push_swap

LIBFT = libft/superlibft.a

INC = -I./includes

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

MAKELIB = make -C libft/

CLEANLIB = make fclean -C libft/

all: ${NAME}

${NAME}: ${OBJS} libcompil includes/push_swap.h 
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

libcompil :
	${MAKELIB}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${BOBJS}

libclean:
	${CLEANLIB}

re: fclean all

.PHONY: clean fclean bonus all re
