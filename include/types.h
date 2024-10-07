/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:07:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 08:02:05 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define EXT ".ber"
# define IMAGE_SIZE 32
# define CELL_MOVABLE "0CE"

typedef enum e_cell
{
	CELL_FLOOR = '0',
	CELL_WALL = '1',
	CELL_ITEM = 'C',
	CELL_EXIT = 'E',
	CELL_PLAYER = 'P'
}	t_cell;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;

typedef struct s_player
{
	int	x;
	int	y;
	int	exit_count;
	int	item_count;
	int	move_count;
}	t_player;

typedef struct s_image
{
	void	*floor;
	void	*exit;
	void	*item;
	void	*player;
	void	*wall;
	void	*open;
}	t_image;

typedef struct s_game
{
	char		*map;
	int			width;
	int			height;

	t_var		vars;
	t_player	player;
	t_image		image;
}	t_game;

#endif