/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:59:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/28 18:03:08 by frahenin         ###   ########.fr       */
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
		{
			game->player.exit_count += 1;
		}
		else if (game->map[i] == CELL_ITEM)
			game->player.item_count += 1;
		i++;
	}
	if (count_p != 1 || (game->player.exit_count != 1)
		|| game->player.item_count < 1)
		free_map_error(game);
}

static void	check_extremitties(t_game *game, int x, int y)
{
	if (ft_get_cell(game->map, game->width, x, y) != CELL_WALL)
	{
		printf("The extremities should be the wall\n");
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

void	ft_check_map_second(t_game *game)
{
	count_cell(game);
	wall_extremities(game);
}
