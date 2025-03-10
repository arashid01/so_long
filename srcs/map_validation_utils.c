/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:46 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/09 23:36:55 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_width(char **map)
{
	int	width;

	if (!map || !map[0])
		ft_error("Invalid map: empty map");
	width = ft_strlen(map[0]);
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	check_rectangular_map(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			free_map_error(map, "Invalid map: map not rectangular");
		i++;
	}
}

void	init_map_info(t_map_info *map_info)
{
	map_info->p_flag = 0;
	map_info->c_flag = 0;
	map_info->e_flag = 0;
	map_info->p_count = 0;
	map_info->e_count = 0;
	map_info->width = 0;
	map_info->height = 0;
	map_info->player_x = -1;
	map_info->player_y = -1;
}
