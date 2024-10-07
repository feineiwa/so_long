/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:45:52 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 15:51:28 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(long nbr, int base, char c)
{
	int		count;
	char	*symb;

	count = 0;
	if (c == 'x' || c == 'u' || c == 'd' || c == 'i')
		symb = "0123456789abcdef";
	else if (c == 'X')
		symb = "0123456789ABCDEF";
	if (nbr < 0)
	{
		count = ft_putchar('-');
		count += ft_print_digits(-nbr, base, c);
	}
	else if (nbr < base)
	{
		count += ft_putchar(symb[nbr]);
	}
	else
	{
		count += ft_print_digits((nbr / base), base, c);
		count += ft_print_digits((nbr % base), base, c);
	}
	return (count);
}
