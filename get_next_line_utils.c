/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:57:42 by mgreshne          #+#    #+#             */
/*   Updated: 2024/03/02 18:57:42 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_new_line(char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = str;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	return (i);
}

char	*after_n(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	i = find_new_line(str);
	new_str = (char *)malloc((ft_strlen(str) - i) + 1);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*before_n(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	i = find_new_line(str);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
