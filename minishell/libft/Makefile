# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliberal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:24:31 by aliberal          #+#    #+#              #
#    Updated: 2024/07/25 03:40:51 by aliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
NAME_BONUS	= libft_bonus.a
CFLAGS = -Wall -Werror -Wextra -I. -c -fPIC

FILES	= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_bzero_aux.c \
			ft_strlen_aux.c \
			ft_strchr_aux.c \
			ft_strjoin_aux.c \
			get_next_line.c \
			ft_print_char.c \
			ft_print_hex.c \
			ft_print_int.c \
			ft_print_pointer.c \
			ft_print_string.c \
			ft_print_unsigned.c \
			ft_printf.c 
			
FILES_BONUS	= ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ_BONUS	= $(FILES_BONUS:%.c=%.o)

OBJ		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	cc $(CFLAGS) $(FILES)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	ar rcs $(NAME_BONUS) $(OBJ_BONUS)

$(OBJ_BONUS): $(FILES_BONUS)
	cc $(CFLAGS) $(FILES_BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all bonus

.PHONY: clean fclean all bonus re

.SILENT: