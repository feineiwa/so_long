/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:04:49 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/08 08:40:57 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_image(char cell, int *item, t_image *image, void **img)
{
	if (cell == CELL_EXIT)
	{
		if (*item <= 0)
			*img = image->open;
		else
			*img = image->exit;
	}
	else if (cell == CELL_FLOOR)
		*img = image->floor;
	else if (cell == CELL_ITEM)
		*img = image->item;
	else if (cell == CELL_PLAYER)
		*img = image->player;
	else if (cell == CELL_WALL)
		*img = image->wall;
}

static void	ft_display_moves(t_game *game)
{
	char	*str;

	mlx_string_put(game->vars.mlx, game->vars.win, 25, 20,
		0xFFFFFF, "Moves : ");
	str = ft_itoa(game->player.move_count);
	mlx_string_put(game->vars.mlx, game->vars.win, 75, 20, 0xFFFFFF, str);
	free(str);
}

void	draw_map(t_game *game)
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
			cell = ft_get_cell(game->map, game->width, x, y);
			put_image(cell, &game->player.item_count, &game->image, &img);
			if (img)
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					img, x * IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
	ft_display_moves(game);
	ft_putstr_fd("\rMoves : ", 1);
	ft_putnbr_fd(game->player.move_count, 1);
}

static void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->image.floor = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/floor.xpm", &x, &y);
	game->image.exit = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/exit.xpm", &x, &y);
	game->image.item = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/item.xpm", &x, &y);
	game->image.player = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/player.xpm", &x, &y);
	game->image.wall = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/wall.xpm", &x, &y);
	game->image.open = mlx_xpm_file_to_image(game->vars.mlx,
			"./assets/open.xpm", &x, &y);
}

void	game_building(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
	{
		free(game->map);
		exit(1);
	}
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * IMAGE_SIZE,
			game->height * IMAGE_SIZE, "so_long");
	if (!game->vars.win)
	{
		mlx_destroy_display(game->vars.mlx);
		free(game->map);
		free(game->vars.mlx);
		exit(1);
	}
	load_images(game);
	draw_map(game);
	mlx_hook(game->vars.win, 2, 1L << 0, control_keys, game);
	mlx_hook(game->vars.win, 17, 0, close_windows, game);
	mlx_loop(game->vars.mlx);
}
