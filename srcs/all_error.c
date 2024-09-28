/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:47 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/28 15:34:59 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	valid_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 4), EXT, 4))
	{
		printf("please put .ber as an extention\n");
		exit(1);
	}
}

void	map_not_readable(t_game *game)
{
	printf("%s \n", strerror(2));
	free_map_error(game);
}

void	min_width_and_height(t_game *game)
{
	if (game->width < 5)
		printf("width should be more than 4\n");
	if (game->height < 3)
		printf("height should be more than 2");
	free_map_error(game);
}

void	free_map_error(t_game *game)
{
	free(game->map);
	exit(1);
}
