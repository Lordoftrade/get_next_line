/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:53:52 by mgreshne          #+#    #+#             */
/*   Updated: 2024/03/02 18:53:52 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_return_null(char *buf1, char *buf2)
{
	free(buf1);
	free(buf2);
	buf2 = NULL;
	return (buf2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer_save, const char *content)
{
	char	*container;
	int		i;
	int		j;

	if (!buffer_save && !content)
		return (NULL);
	i = -1;
	j = -1;
	if (!buffer_save)
	{
		buffer_save = (char *)malloc(sizeof(char) * 1);
		buffer_save[0] = '\0';
	}
	container = (char *)malloc((ft_strlen(buffer_save)
				+ ft_strlen(content) + 1) * sizeof(char));
	if (!container)
		return (NULL);
	while (buffer_save[++i] != '\0')
		container[i] = buffer_save[i];
	while (content[++j] != '\0')
		container[i++] = content[j];
	container[i] = '\0';
	free(buffer_save);
	return (container);
}

char	*ft_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*content;
	int			read_bytes;
	static char	*buffer_save;

	read_bytes = 1;
	content = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, content, 0) < 0)
		return (NULL);
	content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	if (!buffer_save)
		buffer_save = NULL;
	while (!(ft_strchr(buffer_save, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_return_null(content, buffer_save));
		content[read_bytes] = '\0';
		buffer_save = ft_strjoin(buffer_save, content);
	}
	free(content);
	content = before_n(buffer_save);
	buffer_save = after_n(buffer_save);
	return (content);
}

/*int main(void)
{
	int		fd;
	char*	line;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error opening file\n", 20);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		write (1, "NEW_LINE ->\t", 13);
		write (1, line, ft_strlen(line));
		free(line);
	}
	//write (1, "\n" , 1);
	close(fd);
	return (0);
}*/
