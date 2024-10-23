/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:09 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/23 14:23:45 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

const	char	*token_type_to_string(t_token_type type)
{
	if (type == TOKEN_COMMAND)
		return ("TOKEN_COMMAND");
	else if (type == TOKEN_ARGUMENT)
		return ("TOKEN_ARGUMENT");
	else if (type == TOKEN_PIPE)
		return ("TOKEN_PIPE");
	else if (type == TOKEN_REDIRECT_IN)
		return ("TOKEN_REDIRECT_IN");
	else if (type == TOKEN_REDIRECT_OUT)
		return ("TOKEN_REDIRECT_OUT");
	else if (type == TOKEN_APPEND)
		return ("TOKEN_APPEND");
	else if (type == TOKEN_HEREDOC)
		return ("TOKEN_HEREDOC");
	else if (type == TOKEN_DOUBLE_Q)
		return ("TOKEN_DOUBLE_Q");
	else if (type == TOKEN_SINGLE_Q)
		return ("TOKEN_SINGLE_Q");
	else if (type == TOKEN_EOF)
		return ("TOKEN_EOF");
	else
		return ("UNKNOWN");
}

void	print_tokens(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	while (aux)
	{
		printf("\n\nType: %s\nContent: %s\nlen: %ld",
			token_type_to_string(aux->type),
			aux->content, ft_strlen(aux->content));
		aux = aux->next;
	}
}

t_token_type	get_token_type(char *content)
{
	if (ft_strcmp(content, "|") == 0)
		return (TOKEN_PIPE);
	else if (ft_strcmp(content, "<") == 0)
		return (TOKEN_REDIRECT_IN);
	else if (ft_strcmp(content, ">") == 0)
		return (TOKEN_REDIRECT_OUT);
	else if (ft_strcmp(content, ">>") == 0)
		return (TOKEN_APPEND);
	else if (ft_strcmp(content, "<<") == 0)
		return (TOKEN_HEREDOC);
	else if (content[0] == '\'' && (content[ft_strlen(content) - 1] == '\''))
		return (TOKEN_SINGLE_Q);
	else if (content[0] == '"' && (content[ft_strlen(content) - 1] == '"'))
		return (TOKEN_DOUBLE_Q);
	else if (content[0] == '-')
		return (TOKEN_ARGUMENT);
	else
		return (TOKEN_COMMAND);
}

void	add_token_to_list(t_token **tokens, t_token *new_token)
{
	t_token	*aux;

	if (!*tokens)
		*tokens = new_token;
	else
	{
		aux = *tokens;
		while (aux->next)
			aux = aux->next;
		aux->next = new_token;
	}
}

t_token	*create_token(t_token_type type, char *content)
{
	t_token	*no;

	no = malloc(sizeof(t_token));
	if (!no)
		return (NULL);
	no->type = type;
	no->content = ft_strdup(content);
	no->next = NULL;
	return (no);
}
