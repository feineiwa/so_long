/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:47 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/09 09:59:09 by frahenin         ###   ########.fr       */
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
		ft_printf("Error\nPlease check your file's name\n");
		exit(1);
	}
	if (ft_strncmp(str + (len - 4), EXT, 4))
	{
		ft_printf("Error\nThe extension should be .ber\n");
		exit(1);
	}
}

void	map_not_readable(t_game *game)
{
	ft_printf("Error\n%s or empty file\n", strerror(2));
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
		ft_printf("Error\nAll extremities should be wall (1)\n");
		free_map_error(game);
	}
}

void	check_error_cells(int p, int e, int c, t_game *game)
{
	if (p != 1 || e != 1 || c < 1)
	{
		ft_printf("Error\nThe map must have ['P' == 1, 'E' == 1, 'C' >= 1]\n");
		free_map_error(game);
	}
}
