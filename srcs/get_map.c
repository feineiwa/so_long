/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:07:26 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/25 11:45:42 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_map(char *dir)
{
	int	fd;
	char *line;
	char *map;

	map = NULL;
	fd = open(dir, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!map)
			map = ft_strdup(line);
		else
			map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}