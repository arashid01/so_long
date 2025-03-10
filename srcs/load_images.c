/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:34:07 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/10 16:51:00 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->ptr, path, &width, &height);
	if (!img)
	{
		ft_putstr_fd("Failed to load image ", 2);
		ft_putendl_fd(path, 2);
		return (NULL);
	}
	return (img);
}

void	prepare_images(t_game *game)
{
	ft_bzero(&game->imgs, sizeof(t_images));
	game->imgs.up = load_image(game, IMG_UP);
	if (!game->imgs.up)
		destroy_error(game);
	game->imgs.down = load_image(game, IMG_DOWN);
	if (!game->imgs.down)
		destroy_error(game);
	game->imgs.left = load_image(game, IMG_LEFT);
	if (!game->imgs.left)
		destroy_error(game);
	game->imgs.right = load_image(game, IMG_RIGHT);
	if (!game->imgs.right)
		destroy_error(game);
	game->imgs.way = load_image(game, IMG_WAY);
	if (!game->imgs.way)
		destroy_error(game);
	game->imgs.wall = load_image(game, IMG_WALL);
	if (!game->imgs.wall)
		destroy_error(game);
	game->imgs.door = load_image(game, IMG_DOOR);
	if (!game->imgs.door)
		destroy_error(game);
	game->imgs.money = load_image(game, IMG_MONEY);
	if (!game->imgs.money)
		destroy_error(game);
}
