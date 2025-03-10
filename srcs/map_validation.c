/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:39 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/10 21:34:00 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_info(char c, t_map_info *map_info, char **map)
{
	if (c == 'P')
	{
		map_info->p_flag = 1;
		map_info->p_count++;
	}
	if (c == 'E')
	{
		map_info->e_flag = 1;
		map_info->e_count++;
	}
	if (c == 'C')
		map_info->c_flag = 1;
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E')
		free_map_error(map, "Invalid map: map contains invalid characters");
}

static void	check_wall_borders(char **map, int width, int height)
{
	int	i;

	i = 0;
	check_rectangular_map(map);
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			free_map_error(map, "Invalid map: map not surrounded by walls");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			free_map_error(map, "Invalid map: map not surrounded by walls");
		i++;
	}
}

static void	check_map_req(t_map_info *map_info, char **map)
{
	if (map_info->p_count != 1)
		free_map_error(map, "Invalid map: there must be exactly one player");
	if (map_info->e_count != 1)
		free_map_error(map, "Invalid map: there must be exactly one exit");
	if (!map_info->p_flag)
		free_map_error(map, "Invalid map: no player found");
	if (!map_info->c_flag)
		free_map_error(map, "Invalid map: no collectable found");
	if (!map_info->e_flag)
		free_map_error(map, "Invalid map: no exit found");
}

static void	player_pos(t_map_info *map_info, int y, int x)
{
	map_info->player_y = y;
	map_info->player_x = x;
}

void	validate_map(char **map, t_map_info *info)
{
	int			i;
	int			j;

	ft_bzero(info, sizeof(t_map_info));
	info->width = get_map_width(map);
	info->height = get_map_height(map);
	if (info->height <= 2 || info->width <= 2)
		free_map_error(map, "Invalid map");
	check_wall_borders(map, info->width, info->height);
	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (map[i][j] == 'P')
				player_pos(info, i, j);
			check_map_info(map[i][j], info, map);
			j++;
		}
		i++;
	}
	check_map_req(info, map);
	if (!valid_path(map, info))
		free_map_error(map, "Invalid path");
}
