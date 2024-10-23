/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:53:28 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/23 00:51:52 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	size_t	size;

	size = ft_strnlen(str, n);
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, str, size);
	dup[size] = '\0'; 
	return (dup);
}
