/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:41:14 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/08 16:07:26 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_fd(int fd, char *line)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_gnl_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_gnl_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*set_line(char *line)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	current_line = malloc(sizeof(char) * i + 1);
	if (!current_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		current_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		current_line[i++] = '\0';
	current_line[i] = '\0';
	return (current_line);
}

static char	*save_remain(char *line)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	remain = malloc(sizeof(char) * (ft_gnl_strlen(line) - i + 1));
	if (!remain)
		return (NULL);
	i++;
	while (line[i])
		remain[j++] = line[i++];
	remain[j] = '\0';
	free(line);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	final = NULL;
	line = read_fd(fd, line);
	if (!line)
		return (NULL);
	final = set_line(line);
	line = save_remain(line);
	return (final);
}
