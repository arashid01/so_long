/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <amrashid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:01:27 by amrashid          #+#    #+#             */
/*   Updated: 2025/03/09 22:51:16 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	destroy_win(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	destroy_error(t_game *game)
{
	destroy_game(game);
	exit(1);
}
