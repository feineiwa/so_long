/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:35:33 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 22:46:51 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_with_and_height(t_game *game)
{
	int	i;

	i = 0;
	game->width = 0;
	game->height = 0;
	while (game->map[i])
	{
		if (game->map[i] == '\n' || game->map[i + 1] == '\0')
		{
			if (game->width == 0)
				game->width = i;
			(game->height)++;
		}
		i++;
	}
}

static void	check_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->width < 5 || game->height < 3)
		min_width_and_height(game);
	while (game->map[i])
	{
		j++;
		if (game->map[i] == '\n' || game->map[i + 1] == '\0')
		{
			if (game->map[i + 1] != '\0')
				j--;
			if (j != game->width)
			{
				ft_printf("Error\nThe map should be rectangular\n");
				free_map_error(game);
			}
			j = 0;
		}
		i++;
	}
}

static int	valid_cell(char c)
{
	if (c == CELL_EXIT || c == CELL_FLOOR || c == CELL_ITEM
		|| c == CELL_PLAYER || c == CELL_WALL || c == '\n')
		return (1);
	return (0);
}

static void	check_valid_cell(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (!valid_cell(game->map[i]))
		{
			ft_printf("Error\nOnly characters \"0 1 P C\" are allowed\n");
			free_map_error(game);
		}
		i++;
	}
}

void	ft_check_map_first(t_game *game)
{
	get_with_and_height(game);
	check_rectangular(game);
	check_valid_cell(game);
}
