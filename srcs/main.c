/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 07:58:16 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/25 15:38:45 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>


int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (0);
	if (!valid_extension(av[1]))
	{
		printf("please put .ber as an extention\n");
		exit(1);
	}
	game.map = get_map(av[1]);
	if (!game.map)
	{
		printf("%s \n", strerror(2));
		free(game.map);
		exit(1);
	}
	ft_check_map(&game);
	printf("%s\n",game.map);
	printf("width is %d and height is %d", game.width, game.height);
	free(game.map);
	return (0);
}