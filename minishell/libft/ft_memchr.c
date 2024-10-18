/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:29 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/16 10:34:10 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*s;
	unsigned char		uc;
	size_t				i;

	i = 0;
	uc = value;
	s = ptr;
	while (i < num)
	{
		if (s[i] == uc)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
