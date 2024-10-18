/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:01:20 by aliberal          #+#    #+#             */
/*   Updated: 2024/07/16 12:01:36 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_aux(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
