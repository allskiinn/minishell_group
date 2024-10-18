/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:37:49 by aliberal          #+#    #+#             */
/*   Updated: 2024/07/16 12:04:40 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

struct				s_list
{
	void			*content;
	struct s_list	*next;
};

typedef struct s_list	t_list;

/*
** files of the project get_next_line
*/

char	*get_next_line(int fd);
void	ft_bzero_aux(void *s, size_t n);
size_t	ft_strlen_aux(const char *str);
char	*ft_strchr_aux(const char *s, int c);
char	*ft_strjoin_aux(char const *s1, char const *s2);

/*
** files of the project ft_printf
*/

int		ft_printf(const char *format, ...);
int		ft_print_pointer(void *ptr_addr);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_string(char *s);
int		ft_print_int(int n);
int		ft_print_char(char c);
int		ft_print_hex(unsigned int value, int asc);

void	ft_bzero(void *s, size_t num);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *ptr, int value, size_t num);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *search, size_t len);

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int letter);
int		ft_isascii(int c);
int		ft_isdigit(int nbr);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void const *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif