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

#include "get_next_line_bonus.h"

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
	static char	*buffer_save[FOPEN_MAX];

	read_bytes = 1;
	content = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, content, 0) < 0)
		return (NULL);
	content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	if (!buffer_save[fd])
		buffer_save[fd] = NULL;
	while (!(ft_strchr(buffer_save[fd], '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_return_null(content, buffer_save[fd]));
		content[read_bytes] = '\0';
		buffer_save[fd] = ft_strjoin(buffer_save[fd], content);
	}
	free(content);
	content = before_n(buffer_save[fd]);
	buffer_save[fd] = after_n(buffer_save[fd]);
	return (content);
}

/*int main(void)
{
	int		fd, fd1, fd2;
	char*	line;

	fd = open("example.txt", O_RDONLY);
	fd1 = open("example2.txt", O_RDONLY);
	fd2 = open("example3.txt", O_RDONLY);
	if (fd == -1 || fd1 == -1 || fd2 == -1)
	{
		write (2, "Error opening file\n", 20);
		return (1);
	}
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	write (1, "NEW_LINE ->\t", 13);
	// 	write (1, line, ft_strlen(line));
	// 	free(line);
	// }
	line = get_next_line(fd);
    printf("%s", line);
	free(line);
	line = get_next_line(fd1);
    printf("%s", line);
	free(line);
    line = get_next_line(fd2);
    printf("%s", line);
	free(line);
	line = get_next_line(fd);
    printf("%s", line);
	free(line);
	line = get_next_line(fd1);
    printf("%s", line);
	free(line);
    line = get_next_line(fd2);
    printf("%s", line);
	free(line);
	line = get_next_line(fd);
    printf("%s", line);
	free(line);
	line = get_next_line(fd1);
    printf("%s", line);
	free(line);
    line = get_next_line(fd2);
    printf("%s", line);
	free(line);
	//write (1, "\n" , 1);
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}*/
