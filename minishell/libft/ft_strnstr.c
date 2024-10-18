/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:30:41 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/15 22:25:04 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(search);
	if (!l_len)
		return ((char *)str);
	while (*str && l_len <= len--)
	{
		if (!ft_memcmp(str, search, l_len))
			return ((char *)str);
		str++;
	}
	return (0);
}
