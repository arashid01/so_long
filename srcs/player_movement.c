/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:02:04 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/09 23:04:43 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	next_char;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	next_char = game->map[new_y][new_x];
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (new_y == game->exit_y && new_x == game->exit_x
		&& game->collectibles == 0)
	{
		ft_printf("You win!\n");
		destroy_win(game);
	}
	render_map(game->map, game);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == ESC)
		destroy_win(game);
	else if (key == LEFT || key == A_KEY)
	{
		game->direction = LEFT;
		move_player(game, -1, 0);
	}
	else if (key == UP || key == W_KEY)
	{
		game->direction = UP;
		move_player(game, 0, -1);
	}
	else if (key == RIGHT || key == D_KEY)
	{
		game->direction = RIGHT;
		move_player(game, 1, 0);
	}
	else if (key == DOWN || key == S_KEY)
	{
		game->direction = DOWN;
		move_player(game, 0, 1);
	}
	return (0);
}
