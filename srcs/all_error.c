/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:47 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 16:00:00 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	valid_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((!ft_strncmp(str + (len - 4), EXT, 4) && (str[len - 5] == '/'
				|| len == 4)))
	{
		ft_printf("%s\n", strerror(22));
		exit(1);
	}
	if (ft_strncmp(str + (len - 4), EXT, 4))
	{
		ft_printf("%s\n", strerror(22));
		exit(1);
	}
}

void	map_not_readable(t_game *game)
{
	ft_printf("%s \n", strerror(2));
	free_map_error(game);
}

void	min_width_and_height(t_game *game)
{
	if (game->width < 5 || game->height < 3)
		printf("Error map\n");
	free_map_error(game);
}

void	free_map_error(t_game *game)
{
	free(game->map);
	exit(1);
}

void	check_extremitties(t_game *game, int x, int y)
{
	if (ft_get_cell(game->map, game->width, x, y) != CELL_WALL)
	{
		ft_printf("Error map : All extremities should be wall (1)\n");
		free_map_error(game);
	}
}
