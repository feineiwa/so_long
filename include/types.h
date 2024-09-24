/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:07:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/24 20:14:57 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef	enum	e_cell
{
	cell_blank = '0',
	cell_wall = '1',
	cell_collectible = 'C',
	cell_player = 'P',
}	t_cell;

#endif