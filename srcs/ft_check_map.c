/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:35:33 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/26 08:44:40 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_square(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((*game)->width < 5 || (*game)->height < 3)
		min_width_and_height(game);
	while ((*game)->map[i])
	{
		j++;
		if ((*game)->map[i] == '\n' || (*game)->map[i + 1] == '\0')
		{
			if ((*game)->map[i + 1] != '\0')
				j--;
			if (j != (*game)->width)
			{
				printf("the map should be squarred\n");
				free((*game)->map);
				exit(1);
			}
			j = 0;
		}
		i++;
	}
}

static void	get_with_and_height(t_game **game)
{
	int	i;

	i = 0;
	(*game)->width = 0;
	(*game)->height = 0;
	while ((*game)->map[i])
	{
		if ((*game)->map[i] == '\n' || (*game)->map[i + 1] == '\0')
		{
			if ((*game)->width == 0)
				(*game)->width = i;
			((*game)->height)++;
		}
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	get_with_and_height(&game);
	check_square(&game);
}
