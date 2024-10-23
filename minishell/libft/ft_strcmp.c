/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:45:40 by aliberal          #+#    #+#             */
/*   Updated: 2024/10/22 23:41:42 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	c;

	c = 0;
	while (str1[c] == str2[c] && str1[c] != '\0')
		c++;
	return (((unsigned char)(str1[c]) - (unsigned char)(str2[c])));
}
