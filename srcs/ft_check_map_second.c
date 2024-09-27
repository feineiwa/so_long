/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:59:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/27 18:16:09 by frahenin         ###   ########.fr       */
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
			// get_axis(i, &game->player.x, &game->player.y);
			count_p++;
		}
		if (game->map[i] == CELL_EXIT)
		{
			game->player.exit_count++;
		}
		if (game->map[i] == CELL_ITEM)
			game->player.item_count++;
		i++;
	}
	if (count_p != 1 || game->player.exit_count != 1
		|| game->player.item_count < 1)
	{
		free(game->map);
		exit(1);
	}
}

void	ft_check_map_second(t_game *game)
{
	count_cell(game);
}