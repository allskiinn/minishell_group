/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:45:40 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/16 10:22:45 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	if (n != 0)
	{
		while (str1[c] == str2[c] && str1[c] != '\0' && c < n - 1)
			c++;
	}
	else
		return (0);
	return (((unsigned char)(str1[c]) - (unsigned char)(str2[c])));
}
