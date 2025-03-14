/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:55 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/11 22:58:14 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **map, int x, int y, t_map_info *info)
{
	if (x < 0 || x >= info->width || y < 0 || y >= info->height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'E')
		map[y][x] = 'F';
	flood_fill(map, x + 1, y, info);
	flood_fill(map, x - 1, y, info);
	flood_fill(map, x, y + 1, info);
	flood_fill(map, x, y - 1, info);
}

static char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	valid_path(char **map, t_map_info *info)
{
	int		i;
	int		valid;
	char	**map_copy;

	valid = 1;
	map_copy = copy_map(map, info->height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, info->player_x, info->player_y, info);
	i = 0;
	while (map_copy[i])
	{
		if (ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'E'))
			valid = 0;
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	return (valid);
}
