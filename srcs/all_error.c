/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:47 by frahenin          #+#    #+#             */
/*   Updated: 2024/09/25 12:21:19 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str + (len - 4), EXT, 4))
		return (1);
	return (0);
}