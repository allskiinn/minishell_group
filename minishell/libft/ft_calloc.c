/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:26:28 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/16 19:03:52 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	ptr = (void *) malloc(num_elements * element_size);
	if (ptr)
	{
		ft_memset(ptr, 0, num_elements * element_size);
		return (ptr);
	}
	return (NULL);
}
