/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:59:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/29 02:48:11 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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

int	get_index(int x, int y, int witdh)
{
	int	index;

	index = y * (witdh + 1) * x;
	return (index);

}


void	dfs(char *tmp, int x, int y, int width, int height,
		int *found_exit, int *collected)
{
	int	index;
	int	i;

	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	index = get_index(x, y, width);
	if (tmp[index] == CELL_EXIT)
		*found_exit = 1;
	if (tmp[index] == CELL_ITEM)
		(*collected)--;
	tmp[index] = CELL_WALL;
	i = 0;
	while (i < 4)
	{
		dfs(tmp, x + dx[i], y + dy[i], width, height, found_exit, collected);
	}
}

int	check_path_validity(t_game *game)
{
	char	*tmp;
	int		found_exit;
	int		collected;

	tmp = ft_strdup(game->map);
	found_exit = 0;
	collected = game->player.item_count;
	dfs(tmp, game->player.x, game->player.y, game->width, game->height,
		&found_exit, &collected);
	free(tmp);
	return (found_exit && (collected == 0));
}

void	ft_check_map_second(t_game *game)
{
	count_cell(game);
	wall_extremities(game);
	// if (!check_path_validity(game))
	// 	free_map_error(game);
}
