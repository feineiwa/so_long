/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 07:58:16 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/26 14:39:40 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>


int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (0);
	valid_extension(av[1]);
	game.map = get_map(av[1]);
	if (!game.map)
		map_not_readable(&game);
	ft_check_map(&game);
	game_building(&game);
	free(game.map);
	return (0);
}
