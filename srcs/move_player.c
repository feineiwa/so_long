/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:18:00 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 15:45:02 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	swift_axis(t_game *game, int x, int y, t_player *player)
{
	cell_set(game, player->x, player->y, CELL_FLOOR);
	cell_set(game, x, y, CELL_PLAYER);
	game->player.x = x;
	game->player.y = y;
	game->player.move_count += 1;
	draw_map(game);
}

void	cell_move_player(t_game *game, int x, int y, t_player *player)
{
	char	cell_to_move;
	int		can_move;

	cell_to_move = ft_get_cell(game->map, game->width, x, y);
	can_move = 0;
	if (ft_is_in(cell_to_move, CELL_MOVABLE))
	{
		if (cell_to_move == CELL_ITEM)
		{
			game->player.item_count--;
			if (game->player.item_count <= 0)
				game->player.item_count = 0;
			can_move = 1;
		}
		else if (cell_to_move == CELL_FLOOR)
			can_move = 1;
		else if (cell_to_move == CELL_EXIT && game->player.item_count <= 0)
		{
			game->player.item_count = 0;
			game->player.exit_count = 0;
			can_move = 1;
		}
		if (can_move)
			swift_axis(game, x, y, player);
	}
}
