/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:32:40 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/26 17:46:17 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "X11/keysym.h"

int	control_keys(int key, void *data)
{
	t_game *game;

	game = (t_game *)data;
	if (key == 'w' || key == 'W')
		cell_move_player_up(game->map, game);
	else if (key == 'd' || key == 'D')
		printf("mandeha droite\n");
	else if (key == 's' || key == 'S')
		printf("mandeha ambany\n");
	else if (key == 'a' || key == 'A')
		printf("mandeha gauche\n");
	(void)data;
	return (1);
}