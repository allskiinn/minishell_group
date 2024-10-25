/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:38:10 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/25 13:47:45 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
    t_prompt	prompt;
    t_token		*tokens;
    t_command	*command;

    prompt.len = 34;
    prompt.prompt = GREEN BOLD"\n---(allskiin@shell)-[~]\n $> "RESET;
    prompt.command = readline(prompt.prompt);
    
    while ((prompt.command)) 
    {
        if (!ft_strcmp(prompt.command, "exit"))
        {
            free(prompt.command);
            free_tokens(tokens);
            // free(command);
            exit(0);
        }
        
        tokens = tokenize(&prompt);
		command = parsing(tokens);
        print_cmd(command);
        // print_tokens(tokens);
        
        free(prompt.command);
        
        prompt.command = readline(prompt.prompt);
    }
    
    free(prompt.command);
    free_tokens(tokens);
    return (0);
}

