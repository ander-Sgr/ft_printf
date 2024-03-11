/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:42:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/10 17:42:06 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_convert_to_arr(unsigned int nbr, int size)
{
	int		i;
	char	*arr_int;

	arr_int = (char *)malloc((size + 1) * sizeof(char));
	if (arr_int == NULL)
		return (NULL);
	i = size - 1;
	while (nbr != 0)
	{
		arr_int[i] = '0' + (nbr % 10);
		nbr = nbr / 10;
		i--;
	}
	arr_int[size] = '\0';
	return (arr_int);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	total_digits;
	char			*arr_int;

	total_digits = ft_count_digits(n);
	arr_int = ft_convert_to_arr(n, total_digits);
	return (arr_int);
}

int	ft_put_unsigned(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_utoa(nbr);
	if (str == NULL)
		return (-1);
	len = write(1, str, ft_count_digits(nbr));
	free(str);
	return (len);
}
