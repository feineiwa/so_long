/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:44:49 by frahenin          #+#    #+#             */
/*   Updated: 2024/03/08 13:57:31 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dest_size)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dest_size <= 0)
		return (len_src);
	else
	{
		while (src[i] != 0 && --dest_size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
	return (len_src);
}
