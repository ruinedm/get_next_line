/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:28:26 by mboukour          #+#    #+#             */
/*   Updated: 2023/12/04 09:50:43 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char **save, char *buffer, int bytes_read)
{
	char	*temp;

	if (bytes_read == -1)
	{
		free(buffer);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	temp = *save;
	*save = ft_strjoin(*save, buffer);
	free(temp);
	if (!*save)
		return (NULL);
	return (*save);
}

char	*read_and_append(int fd, char **save)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*save, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		*save = append_buffer(save, buffer, bytes_read);
		if (!*save)
			return (NULL);
		if (bytes_read == 0)
			break ;
	}
	free(buffer);
	if (bytes_read == 0 && *save && (*save)[0] == '\0')
	{
		free(*save);
		*save = NULL;
	}
	return (*save);
}

char	*extract_line(char **save, char *newline)
{
	char	*line;
	char	*temp;

	if (newline)
	{
		line = ft_substr(*save, 0, newline - *save + 1);
		temp = *save;
		*save = ft_strdup(newline + 1);
		free(temp);
		if (!*save)
			return (NULL);
	}
	else
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*process_line(char **save)
{
	char	*newline;

	newline = ft_strchr(*save, '\n');
	if (!newline && **save == '\0')
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	return (extract_line(save, newline));
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_append(fd, &save);
	if (!save)
		return (NULL);
	line = process_line(&save);
	return (line);
}
