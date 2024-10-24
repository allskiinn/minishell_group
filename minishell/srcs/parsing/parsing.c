/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:37:55 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/24 01:38:50 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	get_size_args(t_token *current)
{
	size_t	len = 0;
	t_token *aux = current;
	while (aux && aux->type != TOKEN_PIPE)
	{
		len++;
		aux = aux->next;
	}
	return (len);
}

char **get_agrs_token(t_token **current)
{
	size_t i;
	size_t size = get_size_args((*current));
	printf("\nSIZE: %ld", size);
	char **args = malloc(sizeof(char *) * size);
	if (!args) return (NULL);
	i = 0;
	while ((*current) && (*current)->type != TOKEN_PIPE)
	{
		printf("\ni: %ld", i);
		args[i] = ft_strdup((*current)->content);
		(*current) = (*current)->next;
		i++;
	}
	return (args);
}

void	print_cmd(t_command *cmds)
{
	t_command	*aux;

	aux = cmds;
	while (aux)
	{
		printf("\n\nARGS: [ ");
		for (size_t i = 0; aux->args[i]; i++)
			printf("%s ", aux->args[i]);
		printf("\nIS PIPE: %d", aux->is_pipe);
		aux = aux->next;
	}
}

t_command	*parsing(t_token *tokens)
{
	t_token *aux = tokens;
	t_command *list_cmds;
	t_command *new_cmd;
	t_command *aux_cmd;

	list_cmds = NULL;
	while (aux)
	{
		new_cmd = malloc(sizeof(t_command));
		if (aux->type == TOKEN_PIPE)
			new_cmd->is_pipe = 1;
		else
			new_cmd->is_pipe = 0;
		new_cmd->args = get_agrs_token(&aux);
		
		if (!list_cmds)
			list_cmds = new_cmd;
		else
		{
			aux_cmd = list_cmds;
			while (aux_cmd->next)
				aux_cmd = aux_cmd->next;
			aux_cmd->next = new_cmd;
		}
	}
	return (list_cmds);
}