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

static int	check_format(const char *format, va_list args)
{
	int	len_format;

	len_format = 0;
	if (*format == 'c')
		len_format += ft_put_char(va_arg(args, int));
	else if (*format == 's')
		len_format += ft_put_string(va_arg(args, char *));
	else if (*format == 'p')
		len_format += ft_put_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		len_format += ft_put_integer(va_arg(args, int));
	else if (*format == 'u')
		len_format += ft_put_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		len_format += ft_put_hexadecimal(va_arg(args, void *), 'x');
	else if (*format == 'X')
		len_format += ft_put_hexadecimal(va_arg(args, void *), 'X');
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
		if (format[i] == '%' && format[i + 1] == '%')
		{
			len_format += ft_put_char('%');
			i++;
		}
		else if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
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

/*
void	test_x(void)
{
	int x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%x -----------\n\n");
	printf("Testing: (\"\\t%%x\\n\", 42)\n");
	x += printf("  Or\t:\t%x\n", 42);
	y += ft_printf("  Ft\t:\t%x\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe hex number %%x is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe hex number %x is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe hex number %x is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%x\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%x\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%x\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%x\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", -42)\n");
	x += printf("  Or\t:\t%x\n", -42);
	y += ft_printf("  Ft\t:\t%x\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%x\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%x\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_X(void)
{
	int x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%X -----------\n\n");
	printf("Testing: (\"\\t%%X\\n\", 42)\n");
	x += printf("  Or\t:\t%X\n", 42);
	y += ft_printf("  Ft\t:\t%X\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe hex number %%X is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe hex number %X is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe hex number %X is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%X\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%X\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%X\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%X\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", -42)\n");
	x += printf("  Or\t:\t%X\n", -42);
	y += ft_printf("  Ft\t:\t%X\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%X\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%X\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_p(void)
{
	int		n;
	char	c;
	void	*p;

	int x, y;
	printf("\n----------- TEST: %%p -----------\n\n");
	x = 0;
	y = 0;
	n = 50;
	c = 'a';
	p = NULL;
	printf("Testing: (\"\\t%%p\\n\", (void *)&n)\n");
	x += printf("  Or\t:\t%p\n", (void *)&n);
	y += ft_printf("  Ft\t:\t%p\n", (void *)&n);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", (void *)&c)\n");
	x += printf("  Or\t:\t%p\n", (void *)&c);
	y += ft_printf("  Ft\t:\t%p\n", (void *)&c);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", p)\n");
	x += printf("  Or\t:\t%p\n", p);
	y += ft_printf("  Ft\t:\t%p\n", p);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int	main(void)
{
	test_p();
	test_X();
	test_x();
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,    
'C', "0", 0, 0 ,0 ,0, 42, 0);
}
*/
