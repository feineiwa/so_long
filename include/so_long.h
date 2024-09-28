/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:05:49 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/29 00:22:14 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "types.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"

//all error
void	valid_extension(char *str);
char	*get_map(char *dir);
void	map_not_readable(t_game *game);
void	free_map_error(t_game *game);
void	min_width_and_height(t_game *game);

//libft function
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//check_map
void	ft_check_map_first(t_game *game);
void	ft_check_map_second(t_game *game);

//building
void	game_building(t_game *game);
int		control_keys(int key, t_game *data);
int		close_windows(t_game *data);
void	draw_map(t_game *game);

//utitls
char	ft_get_cell(char *map, int width, int in_x, int in_y);
void	cell_set(t_game *game, int in_x, int in_y, char cell);
void	get_axis(t_game *game, char cell, int *ax_x, int *ax_y);
void	exit_game(t_game *game);
int		ft_is_in(char cell, char *cell_mov);

//move players
void	move_player_up(t_game *game, t_player player);
void	move_player_down(t_game *game, t_player player);
void	move_player_right(t_game *game, t_player player);
void	move_player_left(t_game *game, t_player player);


#endif