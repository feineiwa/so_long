/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:37:30 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 15:52:22 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long nbr)
{
	if (nbr < 16)
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + 48), 1);
		else
			ft_putchar_fd(((nbr - 10) + 97), 1);
	}
	else
	{
		ft_put_ptr((nbr / 16));
		ft_put_ptr((nbr % 16));
	}
}

int	ft_len_ptr(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	ft_print_ptr(unsigned long nbr)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (nbr == 0)
		count += write (1, "0", 1);
	else
	{
		ft_put_ptr(nbr);
		count += ft_len_ptr(nbr);
	}
	return (count);
}
