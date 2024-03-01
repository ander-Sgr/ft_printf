/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:07:29 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/23 00:07:29 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	check_format(const char *format, va_list args)
{
	int	len_format;

	len_format = 0;
	if (*format == 'c')
	{
		len_format += ft_putchar(va_arg(args, int));
	}
	return (len_format);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_format;
	va_list	args;

	i = 0;
	len_format = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_strchr("cspdiuxX", format[i + 1]))
			{
				len_format += check_format(&format[i + 1], args);
				i++;
			}
			else
				len_format += ft_putchar(format[i]);
		}
		else
			len_format += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len_format);
}

int	main(void)
{
	int	total_len;

	total_len = ft_printf("test %c %c %c", 'a', 'b', 'c');
	printf("\nprinted my func printf %d:\n", total_len);
}
