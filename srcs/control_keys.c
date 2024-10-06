/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:32:40 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/02 22:42:26 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	control_keys(int key, t_game *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key == 'w' || key == 'W' || key == 65362)
		move_player_up(game, game->player);
	else if (key == 'd' || key == 'D' || key == 65363)
		move_player_right(game, game->player);
	else if (key == 's' || key == 'S' || key == 65364)
		move_player_down(game, game->player);
	else if (key == 'a' || key == 'A' || key == 65361)
		move_player_left(game, game->player);
	else if (key == 65307)
		exit_game(game);
	if (game->player.exit_count == 0)
		exit_game(game);
	return (0);
}

int	close_windows(t_game *data)
{
	t_game	*game;

	game = (t_game *)data;
	exit_game(game);
	return (0);
}
