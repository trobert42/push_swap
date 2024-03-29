/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:09:35 by zerudo            #+#    #+#             */
/*   Updated: 2022/03/28 12:10:31 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H 

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int						ft_atoi(const char *str);
long long				ft_atoll(const char *str);
unsigned long long		ft_atoull(const char *str);
void					ft_bzero(void *s, int n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
void					*ft_calloc(int nitems, int size);
char					*ft_itoa(int n);
void					*ft_memchr(const void *s, int c, int n);
int						ft_memcmp(const void *s1, const void *s2, int n);
void					*ft_memcpy(void *dest, const void *src, int n);
void					*ft_memmove(void *dest, const void *src, int n);
void					*ft_memset(void *s, int c, int n);
char					**ft_split(char const *str, char c);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(char *src);
char					*ft_strjoin(char *s1, char *s2);
int						ft_strlcat(char *dest, const char *src, int size);
int						ft_strlcpy(char *dest, const char *src, int size);
int						ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, int n);
char					*ft_strnstr(const char *str, const char *to_find, \
		int n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strtrim(char *s1, char *set);
char					*ft_substr(char *s, int start, int len);
char					*ft_strmapi(char const *s, char (*f)(unsigned int, \
			char));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putchar(char c);
void					ft_putstr(char *s);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
int						ft_printf(const char *s, ...);
int						print_c(va_list ap);
int						print_s(va_list ap);
int						print_purcent(void);
int						print_d(va_list ap);
int						print_p(va_list ap);
int						print_u(va_list ap);
int						print_x(va_list ap, char c);
void					ft_string_reverse(char *str);
void					ft_putstr(char *str);
void					ft_strtoupper(char *str);
unsigned int			ft_abs(int n);
int						ft_u_nbrlen(unsigned long long n, int base);
char					*ft_uitoa_base(unsigned long long nbr, int base);
int						is_line(const char *s);
char					*getline_cutline(char *str, int flag);
char					*save(char *buf, char *stock, int fd);
char					*get_next_line(int fd);

#endif
