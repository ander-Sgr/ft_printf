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

int	check_format(const char *format)
{
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("test");
}
