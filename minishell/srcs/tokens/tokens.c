/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:06:49 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/27 01:31:25 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

static	void	check_quote(t_prompt *pos,
	char *content, t_token **tokens)
{
	t_token	*new;
	char *var_name = NULL;
	char *value = NULL;

	pos->quote_char = pos->command[pos->i];
	pos->start = pos->i++;
	while (pos->command[pos->i] && pos->command[pos->i] != pos->quote_char)
		pos->i++;
	if (pos->command[pos->i] == pos->quote_char)
		pos->i++;
	content = ft_strndup(pos->command + pos->start, pos->i - pos->start);
	if (pos->quote_char == '"')
	{
		size_t i = 0, j, k;
		while (pos->command[i])
		{
			if (pos->command[i] == '$')
			{
				i++;
				if (ft_isalnum(pos->command[i])
					|| pos->command[i] == '_'
					|| pos->command[i] == '?'
					|| pos->command[i] == '$')
				{
					if (pos->command[i] == '?')
					{
						var_name = ft_strdup("$?");
						value = ft_itoa(pos->last_exit_status);
					}
					else if (pos->command[i] == '$')
					{
						var_name = ft_strdup("$$");
						value = ft_itoa(getpid());
					}
					else
					{
							j = i;
							k = 0;
							while (pos->command[i] && (ft_isalnum(pos->command[i]) || pos->command[i] == '_'))
							{
								i++;
								k++;
							}
							if (!ft_isalnum(pos->command[i]) && pos->command[i] != '_') k++;
							var_name = ft_strndup(pos->command + j, k - 1);
							value = getenv(var_name);
					}
					if (value)
					{
						char *new_cmd = ft_strchr(content, '$');
						char *cmd_left = ft_substr(content, 0, (ft_strlen(content) - ft_strlen(new_cmd)));
						size_t i = 1;
						while (new_cmd[i] && (ft_isalnum(new_cmd[i]) || new_cmd[i] == '_'))
							i++;
						char *cmd_right = ft_strchr(new_cmd, new_cmd[i]);
						char *new_content = ft_strjoin(cmd_left, value);
						new_content = ft_strjoin(new_content, cmd_right);
						content = new_content;
					}
				}
			}
			i++;
		}
		
	}
	new = create_token(get_token_type(content), content);
	free(content);
	if (new == NULL)
		return ;
	add_token_to_list(tokens, new);
	pos->start = pos->i + 1;
}

int	check_unclosed_quote(t_prompt *pos)
{
	char	quote_char = pos->command[pos->i];
	int	j = pos->i + 1;

	while (pos->command[j] && pos->command[j] !=  quote_char)
		j++;
	if (pos->command[j] != quote_char)
	{
		fprintf(stderr, "Erro detectado: Aspa nao fechada");
		return (1);
	}
	return (0);
}

void	expand_env_variable(t_prompt *pos, t_token **tokens)
{
	char *var_name = NULL;
	char *value = NULL;
	t_token *new = NULL;

	if (pos->command[pos->i++] == '$')
	{
		pos->start = pos->i;
		while (pos->command[pos->i] && (ft_isalnum(pos->command[pos->i]) || pos->command[pos->i] == '_'))
			pos->i++;
		if (pos->command[pos->i] == '?')
		{
			value = ft_itoa(pos->last_exit_status);
		}
		else if (pos->command[pos->i] == '$')
		{
			value = ft_itoa(getpid());
		}
		else
		{
			var_name = ft_strndup(pos->command + pos->start, pos->i - pos->start);
			value = getenv(var_name);
		}
		if (value)
		{
			new = create_token(TOKEN_ENV_VAR, value);
			add_token_to_list(tokens, new);
			pos->start = ++pos->i + 1;
		}
		free(var_name);
	}
}

void	handle_escape_char(t_prompt *pos, t_token **tokens)
{
	char	*content = NULL;
	t_token	*new = NULL;
	if (pos->command[pos->i] == '\\')
	{
		pos->start = ++pos->i;
		if (pos->command[pos->i])
			pos->i++;
		content = ft_strndup(pos->command + pos->start, 1);
		new = create_token(TOKEN_LITERAL, content);
		free(content);
		if (new)
			add_token_to_list(tokens, new);
	}
	
}

void	parse_argument(t_prompt *pos, t_token **tokens)
{
	pos->start = pos->i;

	while (pos->command[pos->i]
		&& !is_delimiter(pos->command[pos->i])
		&& pos->command[pos->i] != '\''
		&& pos->command[pos->i] != '"'
		&& pos->command[pos->i] != '$'
		&& pos->command[pos->i] != '\\'
		&& pos->command[pos->i] != '|'
		&& pos->command[pos->i] != '>'
		&& pos->command[pos->i] != '<')
	{
		pos->i++;
	}
	char *content = ft_strndup(pos->command + pos->start, pos->i - pos->start);
	t_token *new = create_token(get_token_type(content), content);
	free(content);
	if (new)
	{
		add_token_to_list(tokens, new);
		pos->start = pos->i + 1;
	}
}

void	tokenize_red_pip(t_prompt *pos, t_token **tokens)
{
	char *content = NULL;
	t_token *new = NULL;

	if (pos->command[pos->i] == '|')
	{
		content = ft_strdup("|");
		pos->i++;
	}
	else if (pos->command[pos->i] == '>')
	{
		if (pos->command[pos->i + 1] == '>')
		{
			content = ft_strdup(">>");
			pos->i += 2;
		}
		else
		{
			content = ft_strdup(">");
			pos->i++;
		}
	}
	else if (pos->command[pos->i] == '<')
	{
		if (pos->command[pos->i + 1] == '<')
		{
			content = ft_strdup("<<");
			pos->i += 2;
		}
		else
		{
			content = ft_strdup("<");
			pos->i++;
		}
	}
	if (content)
	{
		new = create_token(get_token_type(content), content);
		free(content);
		if (new)
			add_token_to_list(tokens, new);
	}
}

t_token	*tokenize(t_prompt *pos)
{
	t_token		*tokens;
	static char	*content;

	pos->i = 0;
	pos->start = 0;
	pos->quote_char = 0;
	tokens = NULL;
	while (pos->command[pos->i])
	{
		if (is_delimiter(pos->command[pos->i]))
			pos->i++;
		else if (pos->command[pos->i] == '"' || pos->command[pos->i] == '\'')
		{
			if (check_unclosed_quote(pos))
				break ;
			check_quote(pos, content, &tokens);
		}
		else if (pos->command[pos->i] == '$')
		{
			expand_env_variable(pos, &tokens);
		}
		else if (pos->command[pos->i] == '|'
			|| pos->command[pos->i] == '>'
			|| pos->command[pos->i] == '<')
		{
			tokenize_red_pip(pos, &tokens);
		}
		else if (pos->command[pos->i] == '\\')
		{
			handle_escape_char(pos, &tokens);
		}
		else
		{
			parse_argument(pos, &tokens);
		}
	}
	return (tokens);
}
