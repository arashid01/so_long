/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:02:38 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/10 15:29:56 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	start_game(char **map, t_map_info info)
{
	t_game	*game;

	game = initialize_game(map, info);
	render_map(game->map, game);
	mlx_hook(game->win, 17, 0, destroy_win, game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_loop(game->ptr);
}

static int	check_empty_map(char *file)
{
	int	fd;
	int	buff[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Unable to read map");
	if (read(fd, buff, 1) == 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	check_map_extension(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".ber", -1) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_map_info	map_info;

	if (argc == 2)
	{
		if (check_map_extension(argv[1]))
			ft_error("Invalid map extension");
		if (check_empty_map(argv[1]))
			ft_error("Invalid map: map empty");
		map = read_map(argv[1]);
		validate_map(map, &map_info);
		start_game(map, map_info);
	}
	ft_error("Usage: ./so_long map.ber");
}
