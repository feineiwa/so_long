/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:18:00 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/02 23:25:36 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	cell_move_player(t_game *game, int x, int y, t_player *player)
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
		{
			cell_set(game, player->x, player->y, CELL_FLOOR);
			cell_set(game, x, y, CELL_PLAYER);
			game->player.x = x;
			game->player.y = y;
			game->player.move_count += 1;
		}
	}
}

void	move_player_up(t_game *game, t_player player)
{
	cell_move_player(game, player.x, player.y - 1, &player);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	draw_map(game);
}

void	move_player_right(t_game *game, t_player player)
{
	cell_move_player(game, player.x + 1, player.y, &player);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	draw_map(game);
}

void	move_player_down(t_game *game, t_player player)
{
	cell_move_player(game, player.x, player.y + 1, &player);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	draw_map(game);
}

void	move_player_left(t_game *game, t_player player)
{
	cell_move_player(game, player.x - 1, player.y, &player);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	draw_map(game);
}