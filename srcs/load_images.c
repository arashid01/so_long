/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:34:07 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/09 22:57:22 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*load_image(t_game *game, char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->ptr, path, width, height);
	if (!img)
		return (NULL);
	return (img);
}

static void	init_t_imgs(t_images *imgs)
{
	imgs->up = NULL;
	imgs->down = NULL;
	imgs->left = NULL;
	imgs->right = NULL;
	imgs->way = NULL;
	imgs->wall = NULL;
	imgs->door = NULL;
	imgs->money = NULL;
	imgs->height = 0;
	imgs->width = 0;
}

void	prepare_images(t_game *game)
{
	game->imgs = malloc(sizeof(t_images));
	if (!game->imgs)
		destroy_error(game);
	init_t_imgs(game->imgs);
	game->imgs->up = load_image(game, IMG_UP,
			&game->imgs->width, &game->imgs->height);
	game->imgs->down = load_image(game, IMG_DOWN,
			&game->imgs->width, &game->imgs->height);
	game->imgs->left = load_image(game, IMG_LEFT,
			&game->imgs->width, &game->imgs->height);
	game->imgs->right = load_image(game, IMG_RIGHT,
			&game->imgs->width, &game->imgs->height);
	game->imgs->way = load_image(game, IMG_WAY,
			&game->imgs->width, &game->imgs->height);
	game->imgs->wall = load_image(game, IMG_WALL,
			&game->imgs->width, &game->imgs->height);
	game->imgs->door = load_image(game, IMG_DOOR,
			&game->imgs->width, &game->imgs->height);
	game->imgs->money = load_image(game, IMG_MONEY,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->up || !game->imgs->down || !game->imgs->left
		|| !game->imgs->right || !game->imgs->way || !game->imgs->wall
		|| !game->imgs->door || !game->imgs->money)
		destroy_error(game);
}
