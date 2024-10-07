/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 07:58:16 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 22:31:21 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_nodes_to_null(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	game->player.exit_count = 0;
	game->player.item_count = 0;
	game->player.move_count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->vars.mlx = NULL;
	game->vars.win = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\n%s\n", strerror(22));
		return (1);
	}
	valid_extension(av[1]);
	init_nodes_to_null(&game);
	game.map = get_map(av[1]);
	if (!game.map)
		map_not_readable(&game);
	ft_check_map_first(&game);
	ft_check_map_second(&game);
	game_building(&game);
	return (0);
}
