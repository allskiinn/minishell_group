# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliberal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 22:32:34 by aliberal          #+#    #+#              #
#    Updated: 2024/10/23 18:20:13 by aliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft.a

LIBFTDIR = ./libft

CLEAR = clear

# colors
RESET            := \033[0m
GREEN            := \033[32m
CYAN             := \033[1;36m
YELLOW           := \033[33m
BLUE             := \033[34m
WHITE            := \033[00m
RED              := \033[1;31m
BOLD             := \033[1;1m

# FDF
NAME = minishell
SRCS = 	./srcs/minishell.c \
		./srcs/tokens/tokens_aux.c \
		./srcs/tokens/tokens.c \
		./srcs/tokens/free_tokens.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) .

$(NAME): $(LIBFT) $(OBJS)
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Criando executavel...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -L. -lreadline -o $(NAME)
	@echo "$(GREEN)$(BOLD)Executavel criado!$(RESET)"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(CLEAR)
	@echo "$(YELLOW)$(BOLD)Removendo objectos...$(RESET)"
	$(RM) $(OBJSDIR)
	@make -C $(LIBFTDIR) clean
	@echo "$(YELLOW)$(BOLD)Objectos removidos!$(RESET)"

fclean: clean
	@$(CLEAR)
	@echo "$(RED)$(BOLD)Removendo executavel...$(RESET)"
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)$(BOLD)Executavel removido!$(RESET)"

re: fclean all
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Recompilado com sucesso!$(RESET)"

push:
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Projecto enviado com sucesso!$(RESET)"
	git add .
	git commit -m "MinishellFinished"
	git push
	git status

norm:
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Norminette!$(RESET)"
	norminette ./includes/*
	norminette ./src/*
	norminette ./libft/*.c
	norminette ./libft/*.h

.PHONY: clean fclean all re

.SILENT: