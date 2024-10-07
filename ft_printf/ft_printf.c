/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:40 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/07 15:53:16 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_print_ptr((unsigned long)va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_digits((long)va_arg(ap, int), 10, 'd');
	else if (spec == 'x')
		count += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'x');
	else if (spec == 'u')
		count += ft_print_digits((long)va_arg(ap, unsigned int), 10, 'u');
	else if (spec == 'X')
		count += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'X');
	else if (spec == '%')
		count += ft_putchar('%');
	else
		count += write (1, &spec, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += ft_check_format(str[++i], ap);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
