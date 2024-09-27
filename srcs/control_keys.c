/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:32:40 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/27 17:16:55 by frahenin         ###   ########.fr       */
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

// t_cell	cell_move_player(char *map, int x, int y, t_player *player)
// {
// 	t_cell	old_cell;
// 	int		can_move;
// 	oldcell = ft_cell_get(map, x, y);
// }

// t_cell	cell_move_player_up(char *map, t_player *player)
// {
// 	return (cell_move_player(map, player->x, player->y - 1, player));
// }

int	control_keys(int key, t_game *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key == 'w' || key == 'W')
		printf("mandeha ambony\n");
		// cell_move_player_up(game->map, &game->player);
	else if (key == 'd' || key == 'D')
		printf("mandeha droite\n");
	else if (key == 's' || key == 'S')
		printf("mandeha ambany\n");
	else if (key == 'a' || key == 'A')
		printf("mandeha gauche\n");
	else if (key == 65307)
		exit_game(game);
	return (0);
}
