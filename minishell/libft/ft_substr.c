/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:23:22 by aliberal          #+#    #+#             */
/*   Updated: 2024/07/16 12:05:05 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
