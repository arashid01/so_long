/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:00:50 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/09 22:52:13 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define IMG_UP "./assets/up.xpm"
# define IMG_DOWN "./assets/down.xpm"
# define IMG_LEFT "./assets/left.xpm"
# define IMG_RIGHT "./assets/right.xpm"
# define IMG_WAY "./assets/way.xpm"
# define IMG_WALL "./assets/wall.xpm"
# define IMG_DOOR "./assets/door.xpm"
# define IMG_MONEY "./assets/money.xpm"

typedef struct s_images
{
	int		width;
	int		height;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*way;
	void	*wall;
	void	*door;
	void	*money;
}	t_images;

typedef struct s_game
{
	void		*ptr;
	void		*win;
	t_images	*imgs;
	char		**map;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collectibles;
	int			direction;
	int			moves;
}	t_game;

typedef struct s_map_info
{
	int	p_flag;
	int	c_flag;
	int	e_flag;
	int	p_count;
	int	e_count;
	int	player_x;
	int	player_y;
	int	width;
	int	height;
}	t_map_info;

char		**read_map(char *file);

void		prepare_images(t_game *game);
t_game		*initialize_game(char **map, t_map_info info);

void		render_map(char **map, t_game *game);

void		validate_map(char **map, t_map_info *info);
int			valid_path(char **map, t_map_info *info);
int			get_map_width(char **map);
int			get_map_height(char **map);
void		init_map_info(t_map_info *map_char);
void		check_rectangular_map(char **map);

int			handle_keypress(int key, t_game *game);
int			count_collectibles(char **map);

void		free_map(char **map);
void		ft_error(char *msg);
void		free_map_error(char **map, char *msg);

void		destroy_game(t_game *game);
int			destroy_win(t_game *game);
int			destroy_error(t_game *game);

#endif
