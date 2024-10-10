/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:18:00 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/10 07:32:11 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	swift_axis_and_render(t_game *game, int x, int y, t_player *player)
{
	int	first_moves_on_screen;

	first_moves_on_screen = 0;
	cell_set(game, player->x, player->y, CELL_FLOOR);
	cell_set(game, x, y, CELL_PLAYER);
	game->player.move_count += 1;
	if (first_moves_on_screen == 0)
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->image.wall, 2 * IMAGE_SIZE, 0 * IMAGE_SIZE);
		first_moves_on_screen = 1;
	}
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.floor,
		player->x * IMAGE_SIZE, player->y * IMAGE_SIZE);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.player,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
	if (game->player.item_count <= 0)
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->image.open, game->exit.x * IMAGE_SIZE, game->exit.y
			* IMAGE_SIZE);
	game->player.x = x;
	game->player.y = y;
	ft_display_moves(game);
	ft_putstr_fd("\rMoves : ", 1);
	ft_putnbr_fd(game->player.move_count, 1);
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
			swift_axis_and_render(game, x, y, player);
	}
}
