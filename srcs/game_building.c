/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:04:49 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/26 17:24:18 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	ft_get_cell(t_game *game, int	in_x, int in_y)
{
	return (game->map[in_y * (game->width + 1) + in_x]);
}

static void	put_image(char cell, t_game *game, void **img)
{
	if (cell == CELL_EXIT)
		*img = game->exit;
	else if (cell == CELL_FLOOR)
		*img = game->floor;
	else if (cell == CELL_ITEM)
		*img = game->item;
	else if (cell == CELL_PLAYER)
		*img = game->player;
	else if (cell == CELL_WALL)
		*img = game->wall;
}

static void	draw_map(t_game *game, t_var vars)
{
	int		x;
	int		y;
	void	*img;
	char	cell;
	
	img = NULL;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			cell = ft_get_cell(game, x, y);
			put_image(cell, game, &img);
			if (img)
				mlx_put_image_to_window(vars.mlx, vars.win, img, x * IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

static void	load_images(t_game **game, t_var vars)
{
	int	x;
	int	y;

	(*game)->floor = mlx_xpm_file_to_image(vars.mlx, "../assets/floor.xpm", 
					&x, &y);
	(*game)->exit = mlx_xpm_file_to_image(vars.mlx, "../assets/exit.xpm",
					&x, &y);
	(*game)->item = mlx_xpm_file_to_image(vars.mlx, "../assets/item.xpm",
					&x, &y);
	(*game)->player = mlx_xpm_file_to_image(vars.mlx, "../assets/player.xpm",
					&x, &y);
	(*game)->wall = mlx_xpm_file_to_image(vars.mlx, "../assets/wall.xpm",
					&x, &y);
}

void	game_building(t_game *game)
{
	t_var	vars;

	vars.mlx = mlx_init();
	if (NULL == vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, game->width * IMAGE_SIZE,
				game->height * IMAGE_SIZE, "so_long");
	if (NULL == vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		exit(1);
	}
	load_images(&game , vars);
	draw_map(game, vars);
	mlx_key_hook(vars.win, control_keys, &vars);
	mlx_loop(vars.mlx);
}
