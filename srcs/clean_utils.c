/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:09 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/11 12:18:34 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	destroy_images(t_game *game)
{
	if (game->imgs.way)
		mlx_destroy_image(game->ptr, game->imgs.way);
	if (game->imgs.wall)
		mlx_destroy_image(game->ptr, game->imgs.wall);
	if (game->imgs.door)
		mlx_destroy_image(game->ptr, game->imgs.door);
	if (game->imgs.money)
		mlx_destroy_image(game->ptr, game->imgs.money);
	if (game->imgs.up)
		mlx_destroy_image(game->ptr, game->imgs.up);
	if (game->imgs.down)
		mlx_destroy_image(game->ptr, game->imgs.down);
	if (game->imgs.left)
		mlx_destroy_image(game->ptr, game->imgs.left);
	if (game->imgs.right)
		mlx_destroy_image(game->ptr, game->imgs.right);
}

void	destroy_game(t_game *game)
{
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->ptr, game->win);
	mlx_destroy_display(game->ptr);
	free_map(game->map);
	free(game->ptr);
	free(game);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_map_error(char **map, char *msg)
{
	free_map(map);
	ft_error(msg);
}
