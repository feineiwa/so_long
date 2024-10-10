/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:05:49 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/10 07:29:21 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "types.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	valid_extension(char *str);
char	*get_map(char *dir);
void	map_not_readable(t_game *game);
void	free_map_error(t_game *game);
void	check_extremitties(t_game *game, int x, int y);
void	check_error_cells(int p, int e, int c, t_game *game);

void	ft_check_map_first(t_game *game);
void	ft_check_map_second(t_game *game);

void	game_building(t_game *game);
int		control_keys(int key, t_game *data);
int		close_windows(t_game *data);

char	ft_get_cell(char *map, int width, int in_x, int in_y);
void	cell_set(t_game *game, int in_x, int in_y, char cell);
void	get_axis(t_game *game, char cell, int *ax_x, int *ax_y);
void	exit_game(t_game *game);
int		ft_is_in(char cell, char *cell_mov);

void	move_player_up(t_game *game, t_player player);
void	move_player_down(t_game *game, t_player player);
void	move_player_right(t_game *game, t_player player);
void	move_player_left(t_game *game, t_player player);
void	cell_move_player(t_game *game, int x, int y, t_player *player);
void	ft_display_moves(t_game *game);

#endif