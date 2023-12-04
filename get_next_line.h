/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:28:46 by mboukour          #+#    #+#             */
/*   Updated: 2023/12/04 09:49:44 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h> // to remove
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_and_append(int fd, char **save);
char	*process_line(char **save);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif