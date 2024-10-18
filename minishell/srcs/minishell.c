/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:54 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/17 23:48:51 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
    char *command;
    static char **cmd, *title = GREEN BOLD"\n---(allskiin@shell)-[~]\n $> "RESET;
    size_t  len = 34;
    
    while ((command = readline(title))) {
        cmd = ft_split(command, ' ');
        if (!strcmp(cmd[0], "pwd")) {
            printf(YELLOW"%s\n"RESET, getcwd(NULL, 0));
        } else if (!strcmp(cmd[0], "cd")) {
            if (ft_strlen(cmd[1]) > 0)
            {
                if (!chdir(cmd[1])) {
                    title = ft_substr(title, 0, len);
                    title = ft_strjoin(title, "/");
                    title = ft_strjoin(title, cmd[1]);
                    title = ft_strjoin(title, "]\n $> ");
                    len += ft_strlen(cmd[1]);
                } else {
                    printf(RED"\n> '%s' isn't a directory.\n"RESET, cmd[1]);
                }
            }
            else
            {
                chdir("/home/allskiin/Desktop/minishell_group/minishell");
                title = GREEN BOLD"\n---(allskiin@shell)-[~]\n $> "RESET;
            }
        } else if (!strcmp(command, "exit")) {
            free(command);
            for (size_t i = 0; cmd[i]; i++)
                free(cmd[i]);
            free(cmd);
            free(title);
            exit(0);
        } else {
            printf(RED"\n> command '%s' not found\n"RESET, command);
        }
        add_history(command);
    }
    return (0);
}
