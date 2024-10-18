/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:14:29 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/15 22:25:46 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_end;

	str_end = (char *)str + ft_strlen(str);
	while (str_end > str && *str_end != (char)c)
		str_end--;
	if (*str_end == (char)c)
		return (str_end);
	return (NULL);
}
