/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:59:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 22:51:59 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_cell(t_game *game)
{
	int	i;
	int	count_p;

	i = 0;
	count_p = 0;
	while (game->map[i])
	{
		if (game->map[i] == CELL_PLAYER)
		{
			get_axis(game, CELL_PLAYER, &game->player.x, &game->player.y);
			count_p++;
		}
		else if (game->map[i] == CELL_EXIT)
			game->player.exit_count += 1;
		else if (game->map[i] == CELL_ITEM)
			game->player.item_count += 1;
		i++;
	}
	if (count_p != 1 || (game->player.exit_count != 1)
		|| game->player.item_count < 1)
	{
		ft_printf("Error\nThe map must only have ['P' == 1, 'E' == 1, 'C' <= 1]\n");
		free_map_error(game);
	}
}

static void	wall_extremities(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		check_extremitties(game, x, y);
		while (x < game->width)
		{
			if (y == 0)
				check_extremitties(game, x, y);
			if (x == game->width - 1)
				check_extremitties(game, x, y);
			if (y == game->height - 1)
				check_extremitties(game, x, y);
			x++;
		}
		y++;
	}
}

static void	path_finding(t_game *game_c, int x, int y)
{
	t_cell	cell;

	cell = ft_get_cell(game_c->map, game_c->width, x, y);
	if (cell == CELL_WALL)
		return ;
	if (cell == 'F')
		return ;
	if (cell == CELL_ITEM)
		game_c->player.item_count--;
	if (cell == CELL_EXIT)
	{
		game_c->player.exit_count--;
		cell_set(game_c, x, y, 'F');
		if (game_c->player.item_count != 0)
			return ;
	}
	cell_set(game_c, x, y, 'F');
	path_finding(game_c, x + 1, y);
	path_finding(game_c, x - 1, y);
	path_finding(game_c, x, y + 1);
	path_finding(game_c, x, y - 1);
}

static int	check_path_validity(t_game *game)
{
	t_game	game_c;

	game_c.height = game->height;
	game_c.width = game->width;
	game_c.map = ft_strdup(game->map);
	game_c.player.x = game->player.x;
	game_c.player.y = game->player.y;
	game_c.player.exit_count = game->player.exit_count;
	game_c.player.item_count = game->player.item_count;
	path_finding(&game_c, game_c.player.x, game_c.player.y);
	free(game_c.map);
	if (game_c.player.exit_count <= 0 && game_c.player.item_count <= 0)
		return (1);
	return (0);
}

void	ft_check_map_second(t_game *game)
{
	count_cell(game);
	wall_extremities(game);
	if (!check_path_validity(game))
	{
		ft_printf("Error\nThis map is not playable\n");
		free_map_error(game);
	}
}
