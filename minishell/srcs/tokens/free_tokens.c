/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:13:52 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/23 18:19:01 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    free_tokens(t_token *token)
{
    t_token *aux;

    while (token) // Enquanto houver tokens na lista
    {
        aux = token->next; // Salva o próximo token
        free(token->content); // Libera o conteúdo do token, se necessário
        free(token); // Libera o token atual
        token = aux; // Avança para o próximo token
    }
}