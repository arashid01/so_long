/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:27 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/10 16:43:14 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_size(t_game *game, int width, int height)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->ptr, &screen_width, &screen_height);
	if (width > screen_width || height > screen_height)
	{
		destroy_game(game);
		ft_error("Map is too large for the screen");
	}
}

static void	initial_values(t_game *game, t_map_info *info)
{
	game->player_x = info->player_x;
	game->player_y = info->player_y;
	game->map_width = get_map_width(game->map);
	game->map_height = get_map_height(game->map);
	game->collectibles = count_collectibles(game->map);
	game->direction = DOWN;
}

static void	init_t_game(t_game *game)
{
	game->win = NULL;
	game->map = NULL;
	game->moves = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->direction = 0;
	game->moves = 0;
}

static void	init_game_win(t_game *game)
{
	game->win_width = get_map_width(game->map) * 64;
	game->win_height = get_map_height(game->map) * 64;
	check_map_size(game, game->win_width, game->win_height);
	game->win = mlx_new_window(game->ptr,
			game->win_width, game->win_height, "SO_LONG");
}

t_game	*initialize_game(char **map, t_map_info info)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->ptr = mlx_init();
	if (!game->ptr)
	{
		free(game);
		free_map_error(map, "Failed to connect to MLX");
	}
	init_t_game(game);
	game->map = map;
	init_game_win(game);
	if (!game->win)
	{
		destroy_game(game);
		ft_error("Failed to create window");
	}
	prepare_images(game);
	initial_values(game, &info);
	return (game);
}
