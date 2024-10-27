/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:37:55 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/27 02:19:06 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t get_size_args(t_token *current)
{
    size_t len = 0;
    t_token *aux = current;
    while (aux)
    {
		if (aux->type == TOKEN_PIPE)
		{
			len++;
			break ;
		}
		len++;
        aux = aux->next;
    }
    return (len);
}

char **get_agrs_token(t_token **current, t_command **cur_cmd)
{
    size_t i;
    size_t size = get_size_args((*current));

    char **args = malloc(sizeof(char *) * (size + 1));
    if (!args) return (NULL);
    
    i = 0;
    while ((*current))
    {
		args[i] = ft_strdup((*current)->content);
		if ((*current)->type == TOKEN_PIPE)
		{
			(*cur_cmd)->is_pipe = 1;
			i++;
			(*current) = (*current)->next;
			break ;
		}
		else if ((*current)->type == TOKEN_REDIRECT_OUT)
		{
			(*current) = (*current)->next;
			(*cur_cmd)->output_file = ft_strdup((*current)->content);
		}
		else if ((*current)->type == TOKEN_REDIRECT_IN)
		{
			(*current) = (*current)->next;
			(*cur_cmd)->input_file = ft_strdup((*current)->content);
		} else if ((*current)->type == TOKEN_APPEND)
		{
			(*cur_cmd)->append_mode = 1;
			(*current) = (*current)->next;
			(*cur_cmd)->output_file = ft_strdup((*current)->content);
		}
		else if ((*current)->type == TOKEN_HEREDOC)
		{
			(*cur_cmd)->heredoc_mode = 1;
			(*current) = (*current)->next;
			(*cur_cmd)->output_file = ft_strdup((*current)->content);
		}
		else
        	(*current) = (*current)->next;
        i++;
    }

    args[i] = NULL;
    return (args);
}

void print_cmd(t_command *cmds)
{
    t_command *aux;

    aux = cmds;
    while (aux)
    {
        printf("\n\nARGS: [ ");
        for (size_t i = 0; aux->args[i]; i++)
            printf("%s ", aux->args[i]);
        printf("]");
        printf("\nIS PIPE: %d", aux->is_pipe);
		printf("\nINPUT_FILE: %s", aux->input_file);
		printf("\nOUTPUT_FILE: %s", aux->output_file);
		printf("\nAPPEND_MODE: %d", aux->append_mode);
		printf("\nHEDEDOC_MODE: %d", aux->heredoc_mode);
        aux = aux->next;
    }
}

t_command *parsing(t_token *tokens)
{
    t_token *aux = tokens;
    t_command *list_cmds;
    t_command *new_cmd;
    t_command *aux_cmd;

    list_cmds = NULL;
    while (aux)
    {
        new_cmd = malloc(sizeof(t_command));
        if (!new_cmd)
            return (NULL);
		new_cmd->is_pipe = 0;
		new_cmd->append_mode = 0;
		new_cmd->heredoc_mode = 0;
		new_cmd->input_file = NULL;
		new_cmd->output_file = NULL;
        new_cmd->args = get_agrs_token(&aux, &new_cmd);
        new_cmd->next = NULL;

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
