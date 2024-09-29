/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:50:15 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/29 12:57:22 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	ft_get_cell(char *map, int width, int in_x, int in_y)
{
	return (map[in_y * (width + 1) + in_x]);
}

void	cell_set(t_game *game, int in_x, int in_y, char cell)
{
	game->map[in_y * (game->width + 1) + in_x] = cell;
}

void	get_axis(t_game *game, char cell, int *ax_x, int *ax_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (cell == ft_get_cell(game->map, game->width, x, y))
				break ;
			x++;
		}
		if (cell == ft_get_cell(game->map, game->width, x, y))
			break ;
		y++;
	}
	*ax_x = x;
	*ax_y = y;
}

void	exit_game(t_game *game)
{
	free(game->map);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_destroy_image(game->vars.mlx, game->image.exit);
	mlx_destroy_image(game->vars.mlx, game->image.floor);
	mlx_destroy_image(game->vars.mlx, game->image.item);
	mlx_destroy_image(game->vars.mlx, game->image.player);
	mlx_destroy_image(game->vars.mlx, game->image.wall);
	mlx_destroy_image(game->vars.mlx, game->image.open);
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