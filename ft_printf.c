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

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	check_format(const char *format, va_list args)
{
	int	len_format;

	len_format = 0;
	if (*format == 'c')
		len_format += ft_put_char(va_arg(args, int));
	else if (*format == 's')
		len_format += ft_put_string(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		len_format += ft_put_integer(va_arg(args, int));
	else if (*format == 'u')
		len_format += ft_put_unsigned(va_arg(args, unsigned));
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
			len_format += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (len_format);
}

void	test_u(void)
{
	int x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%u -----------\n\n");
	printf("Testing: (\"\\t%%u\\n\", 42)\n");
	x += printf("  Or\t:\t%u\n", 42);
	y += ft_printf("  Ft\t:\t%u\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe number %%u is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe number %u is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe number %u is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%u\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%u\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%u\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%u\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", -42)\n");
	x += printf("  Or\t:\t%u\n", -42);
	y += ft_printf("  Ft\t:\t%u\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%u\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%u\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int	main(void)
{
	test_u();
}
