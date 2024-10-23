/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:09:20 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/23 00:47:41 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t i = 0;

    // Copia caracteres de src para dest enquanto não atingirmos o tamanho n e src não for terminado
    while (i < size && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    // Preenche o restante do dest com '\0' se ainda não alcançamos n
    while (i < size)
    {
        dest[i] = '\0';
        i++;
    }

    return (i);
}
