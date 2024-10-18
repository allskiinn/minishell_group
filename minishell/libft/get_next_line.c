/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:20:28 by aliberal          #+#    #+#             */
/*   Updated: 2024/07/16 12:34:49 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_string(int fd, char **str, char *word)
{
	char	*tmp;
	int		bytes;

	ft_bzero_aux(word, BUFFER_SIZE + 1);
	bytes = read(fd, word, BUFFER_SIZE);
	if (bytes < 0 || word == NULL)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	tmp = ft_strjoin_aux(*str, word);
	free(*str);
	*str = tmp;
	return (bytes);
}

static void	remove_result(char **str)
{
	char	*nl;
	char	*tmp;
	size_t	i;
	size_t	j;

	nl = ft_strchr_aux(*str, '\n');
	if (!nl)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	tmp = malloc((ft_strlen_aux(nl)) * sizeof(char));
	i = 0;
	j = ft_strlen_aux(*str) - ft_strlen_aux(nl) + 1;
	while (j < ft_strlen_aux(*str))
		tmp[i++] = (*str)[j++];
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
	if (**str == 0)
	{
		free(*str);
		*str = NULL;
	}
}

static void	get_result(char **str, char **result)
{
	char	*nl;
	size_t	len;
	size_t	i;

	nl = ft_strchr_aux(*str, '\n');
	len = ft_strlen_aux(*str) - ft_strlen_aux(nl) + 2;
	*result = (char *)malloc(len * sizeof(char));
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*str)[i];
		i++;
	}
	(*result)[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	char		*word;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (ft_strchr_aux(str, '\n') == NULL
		&& bytes > 0)
		bytes = read_string(fd, &str, word);
	free(word);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen_aux(str) == 0)
		return (NULL);
	get_result(&str, &result);
	remove_result(&str);
	return (result);
}
