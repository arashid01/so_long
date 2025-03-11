/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:02:30 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/11 12:30:12 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.wall, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.money, x * 64, y * 64);
	else if (tile == 'E')
	{
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.door, x * 64, y * 64);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (tile == '0')
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.way, x * 64, y * 64);
}

static void	render_player(t_game *game, int x, int y)
{
	if (game->direction == UP)
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.up, x * 64, y * 64);
	else if (game->direction == DOWN)
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.down, x * 64, y * 64);
	else if (game->direction == LEFT)
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.left, x * 64, y * 64);
	else if (game->direction == RIGHT)
		mlx_put_image_to_window(game->ptr,
			game->win, game->imgs.right, x * 64, y * 64);
}

void	render_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				render_player(game, j, i);
			else
				render_tile(game, map[i][j], j, i);
			j++;
		}
		i++;
	}
}
