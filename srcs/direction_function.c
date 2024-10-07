/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:45:34 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 15:45:57 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player_up(t_game *game, t_player player)
{
	cell_move_player(game, player.x, player.y - 1, &player);
}

void	move_player_right(t_game *game, t_player player)
{
	cell_move_player(game, player.x + 1, player.y, &player);
}

void	move_player_down(t_game *game, t_player player)
{
	cell_move_player(game, player.x, player.y + 1, &player);
}

void	move_player_left(t_game *game, t_player player)
{
	cell_move_player(game, player.x - 1, player.y, &player);
}
