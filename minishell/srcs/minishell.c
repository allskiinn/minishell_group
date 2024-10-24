/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:38:10 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/24 01:35:28 by aliberal         ###   ########.fr       */
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
    prompt.command = readline(prompt.prompt); // Aloca memória para `prompt.command`
    
    while ((prompt.command)) 
    {
        if (!ft_strcmp(prompt.command, "exit"))
        {
            free(prompt.command); // Libera memória alocada para `prompt.command`
            free_tokens(tokens); // Aqui, não sabemos se `tokens` é liberado corretamente
            free(command);
            exit(0);
        }
        
        tokens = tokenize(&prompt);
		command = parsing(tokens);
        //print_cmd(command);
        
        free(prompt.command); // Liberar a memória de `prompt.command` antes da próxima leitura
        
        prompt.command = readline(prompt.prompt); // Nova alocação de memória
    }
    
    free(prompt.command); // Libera a memória ao final
    free_tokens(tokens); // Certifique-se de liberar `tokens` se ele estiver alocado
    return (0);
}

