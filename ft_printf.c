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
	else if (*format == 's')
	{
		len_format += ft_putstring(va_arg(args, char*));
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
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
		{
			len_format += check_format(&format[i + 1], args);
			i++;
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

	int total_len_str;

	total_len_str = ft_printf("hola mundo %s print char %c", "que tal a todos", 'a');
	printf("\ntotal len str  %d\n", total_len_str);
}

