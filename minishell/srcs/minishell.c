/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:54 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/17 16:42:22 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
    char *command;
    while (strcmp(command, "exit"))
    {
        command = readline(GREEN"allskiin > "RESET);
        if (!strcmp(command, "pwd")) {
            printf(YELLOW"%s\n"RESET, getcwd(NULL, 0));
        } else {
            printf(BLUE"%s\n"RESET, command);
        }
        if (!strcmp(command, "exit")) break ;
    }
    return (0);
}
