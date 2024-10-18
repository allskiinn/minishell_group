/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:53:28 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/15 22:18:17 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(str) + 1;
	dup = malloc(size);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, size);
	return (dup);
}
