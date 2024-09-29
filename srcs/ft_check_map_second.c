/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:59:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/29 18:59:33 by frahenin         ###   ########.fr       */
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

int	get_index(int x, int y, int width)
{
	int	index;

	index = y * (width + 1) + x;
	return (index);
}
int	is_movable(t_game *game_c)
{
	if (ft_get_cell(game_c->map, game_c->width,
			game_c->player.x, game_c->player.y) == CELL_ITEM)
		return (1);
	else if (ft_get_cell(game_c->map, game_c->width,
			game_c->player.x, game_c->player.y) == CELL_EXIT)
		return (1);
	else if (ft_get_cell(game_c->map, game_c->width,
			game_c->player.x, game_c->player.y) == CELL_FLOOR)
		return (1);
	return (0);
}

void	dfs(t_game *game_c, int x, int y, t_count *count)
{
	t_cell	nextcell;

	if (x < 0 || y < 0 || x >= game_c->width || y >= game_c->height)
		return ;
	nextcell = ft_get_cell(game_c->map, game_c->width, x, y);
	if (nextcell == CELL_ITEM)
		count->item--;
	if (!ft_is_in(nextcell, CELL_MOVABLE))
		return ;
	cell_set(game_c, x, y, CELL_PLAYER);
	dfs(game_c, x - 1, y, count);
	dfs(game_c, x, y - 1, count);
	dfs(game_c, x, y + 1, count);
	dfs(game_c, x + 1, y, count);
	if (nextcell == CELL_EXIT && !count->item)
		count->exit--;
}

int	check_path_validity(t_game *game)
{
	t_game	game_c;
	t_count	count;

	game_c.height = game->height;
	game_c.width = game->width;
	game_c.map = ft_strdup(game->map);
	game_c.player.x = game->player.x;
	game_c.player.y = game->player.y;
	count.exit = game->player.exit_count;
	count.item = game->player.item_count;
	dfs(&game_c, game_c.player.x + 1, game_c.player.y, &count);
	dfs(&game_c, game_c.player.x - 1, game_c.player.y, &count);
	dfs(&game_c, game_c.player.x, game_c.player.y + 1, &count);
	dfs(&game_c, game_c.player.x, game_c.player.y - 1, &count);
	free(game_c.map);
	if (count.exit <= 0 && count.item <= 0)
		return (1);
	return (0);
}

void	ft_check_map_second(t_game *game)
{
	count_cell(game);
	wall_extremities(game);
	if (!check_path_validity(game))
		free_map_error(game);
}
