/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:58:00 by mgreshne          #+#    #+#             */
/*   Updated: 2024/03/02 18:58:00 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
size_t		find_new_line(char *str);
char		*after_n(char *str);
char		*before_n(char *str);
char		*ft_strchr(char const *str, int c);
char		*ft_strjoin(char *buffer_save, char const *content);
char		*free_return_null(char *buf1, char *buf2);

#endif
