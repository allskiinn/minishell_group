/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:06:49 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/23 23:34:15 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_delimiter(char c)
{
	return (c == ' ' || c == '|' || c == '>' || c == '<');
}

static	void	check_quote(t_prompt *pos,
	char *content, t_token **tokens)
{
	t_token	*new;

	pos->quote_char = pos->command[pos->i];
	pos->start = pos->i++;
	while (pos->command[pos->i] && pos->command[pos->i] != pos->quote_char)
		pos->i++;
	if (pos->command[pos->i] == pos->quote_char)
		pos->i++;
	content = ft_strndup(pos->command + pos->start, pos->i - pos->start);
	new = create_token(get_token_type(content), content);
	free(content);
	if (new == NULL)
		return ;
	add_token_to_list(tokens, new);
	pos->start = pos->i;
}

void	set_content(t_prompt *pos,
	char *content, t_token **tokens)
{
	t_token	*new;

	if (pos->start != pos->i && (pos->command[pos->start] != ' '))
	{
		content = ft_strndup(pos->command + pos->start, pos->i - pos->start);
		new = create_token(get_token_type(content), content);
		free(content);
		if (new == NULL)
			return ;
		add_token_to_list(tokens, new);
	}
	if (pos->command[pos->i] != ' ')
	{
		content = ft_strndup(pos->command + pos->i, 1);
		new = create_token(get_token_type(content), content);
		free(content);
		if (new == NULL)
			return ;
		add_token_to_list(tokens, new);
	}
	pos->start = pos->i + 1;
}

void	check_last_token(t_prompt *pos,
	char *content, t_token **tokens)
{
	t_token	*new;

	if (pos->start < pos->i)
	{
		content = ft_strndup(pos->command + pos->start, pos->i - pos->start);
		if (content[0] != '\0')
		{
			new = create_token(get_token_type(content), content);
			free(content);
			if (new == NULL)
				return ;
			add_token_to_list(tokens, new);
		}
	}
}

t_token	*tokenize(t_prompt *pos)
{
	t_token		*tokens;
	static char	*content;

	pos->i = -1;
	pos->start = 0;
	pos->quote_char = 0;
	tokens = NULL;
	while (pos->command[++pos->i])
	{
		if (pos->command[pos->i] == '"' || pos->command[pos->i] == '\'')
		{
			check_quote(pos, content, &tokens);
			continue ;
		}
		if (is_delimiter(pos->command[pos->i]))
			set_content(pos, content, &tokens);
	}
	check_last_token(pos, content, &tokens);
	return (tokens);
}
