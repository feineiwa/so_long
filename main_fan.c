/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:39:14 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/27 13:05:10 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;


int	f(int key, void *dt)
{
	t_data *data;
	
	data = (t_data *)dt;
	if (key == 'w')
	{
		mlx_clear_window(data->mlx,data->win );
		mlx_destroy_window(data->mlx,data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;

	(void)av;
	(void)ac;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit(1);
	data.win = mlx_new_window(data.mlx, 200, 200, "mem");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (1);
	}
	mlx_key_hook(data.win, f, &data);
	mlx_loop(data.mlx);
}