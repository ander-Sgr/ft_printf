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

int	check_format(const char *format, void *args)
{
	int	len_format;

	len_format = 0;
	if (format[len_format] == 'c')
	{
		len_format += ft_putchar(*(char *)args);
		len_format += 1;
	}
	return (len_format);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_format;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_strchr("cspdiuxX", format[i]))
			{
				len_format += check_format(&format[i], va_arg(args, void *));
			}
			else
				len_format += ft_putchar(format[i]);
		}
		len_format += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len_format);
}

int	main(void)
{
	ft_printf("test %c", 'a');
}
