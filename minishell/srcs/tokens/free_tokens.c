/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:13:52 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/25 13:48:01 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    free_tokens(t_token *token)
{
    t_token *aux;

    while (token)
    {
        aux = token->next;
        free(token->content);
        free(token);
        token = aux;
    }
}