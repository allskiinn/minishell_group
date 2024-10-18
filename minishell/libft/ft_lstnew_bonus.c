/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:27:09 by aliberal          #+#    #+#             */
/*   Updated: 2024/05/16 13:25:03 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*no;

	no = (t_list *) malloc(sizeof(t_list));
	if (no)
	{
		if (content)
		{
			no->content = (char *)malloc(sizeof(char) * ft_strlen(content) + 1);
			if (no->content)
				ft_memcpy(no->content, content, ft_strlen(content));
			else
			{
				free(no);
				return (NULL);
			}
		}
		else
			no->content = NULL;
		no->next = NULL;
	}
	return (no);
}
