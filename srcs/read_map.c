/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:02:22 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/08 16:11:56 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map");
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (count);
}

static char	**allocate_map(int lines_count)
{
	char	**map;

	map = malloc(sizeof(char *) * (lines_count + 1));
	if (!map)
		ft_error("Memory allocation failed");
	return (map);
}

static void	fill_map(char **map, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free_map(map);
		ft_error("Error opening map");
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
}

char	**read_map(char *file)
{
	int		lines_count;
	char	**map;

	lines_count = count_lines(file);
	map = allocate_map(lines_count);
	fill_map(map, file);
	return (map);
}
