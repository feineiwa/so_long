/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:50:15 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/28 14:52:01 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	ft_get_cell(char *map, int width, int in_x, int in_y)
{
	return (map[in_y * (width + 1) + in_x]);
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
