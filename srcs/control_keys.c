/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:32:40 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/28 18:19:38 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_game *game)
{
	free(game->map);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_destroy_image(game->vars.mlx, game->image.exit);
	mlx_destroy_image(game->vars.mlx, game->image.floor);
	mlx_destroy_image(game->vars.mlx, game->image.item);
	mlx_destroy_image(game->vars.mlx, game->image.player);
	mlx_destroy_image(game->vars.mlx, game->image.wall);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(0);
}

int	ft_is_in(char cell, char *cell_mov)
{
	int	i;

	i = 0;
	while (cell_mov[i])
	{
		if (cell == cell_mov[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	cell_set(t_game *game, int in_x, int in_y, char cell)
{
	game->map[in_y * (game->width + 1) + in_x] = cell;
}

void	cell_move_player(t_game *game, int x, int y, t_player *player)
{
	char	old_cell;
	char	cell_to_move;
	int		can_move;

	old_cell = ft_get_cell(game->map, game->width, player->x, player->y);
	cell_to_move = ft_get_cell(game->map, game->width, x, y);
	can_move = 0;
	if (ft_is_in(cell_to_move, CELL_MOVABLE))
	{
		if (cell_to_move == CELL_ITEM)
		{
			game->player.item_count--;
			if (game->player.item_count <= 0)
				game->player.item_count = 0;
			game->player.move_count += 1;
			can_move = 1;
		}
		else if (cell_to_move == CELL_FLOOR)
			can_move = 1;
		else if (old_cell == CELL_EXIT && game->player.item_count <= 0)
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
}

int	control_keys(int key, t_game *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key == 'w' || key == 'W')
	{
		printf("x = %d et y = %d\n", game->player.x, game->player.y);
		move_player_up(game, game->player);
		printf("x = %d et y = %d\n", game->player.x, game->player.y);
		printf("move : %d", game->player.move_count);
		// printf("player->item_cout est %d\n", game->player.item_count);
	}
	else if (key == 'd' || key == 'D')
		printf("mandeha droite\n");
	else if (key == 's' || key == 'S')
		printf("mandeha ambany\n");
	else if (key == 'a' || key == 'A')
		printf("mandeha gauche\n");
	else if (key == 65307)
		exit_game(game);
	printf("%d\n", key);
	return (0);
}

int	close_windows(t_game *data)
{
	t_game	*game;

	game = (t_game *)data;
	exit_game(game);
	return (0);
}
