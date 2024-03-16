/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:05:15 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/16 17:05:15 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	invert_result_hex(char *result_hex)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = (int)ft_strlen(result_hex) - 1;
	while (i < j)
	{
		temp = result_hex[i];
		result_hex[i] = result_hex[j];
		result_hex[j] = temp;
		i++;
		j--;
	}
}

static char	*convert_hex(void *ptr)
{
	char				*hex;
	unsigned long long	number;
	char				*result_hex;
	int					i;

	number = (unsigned long long)ptr;
	;
	hex = "0123456789abcdef";
	result_hex = (char *)malloc(sizeof(char) * 17);
	if (result_hex == NULL)
		return (NULL);
	i = 0;
	if (number == 0)
		result_hex[i + 1] = hex[0];
	else
	{
		while (number != 0 && i < 16)
		{
			result_hex[i] = hex[number % 16];
			number = number / 16;
			i++;
		}
	}
	result_hex[i] = '\0';
	invert_result_hex(result_hex);
	return (result_hex);
}

int	ft_put_pointer(void *ptr)
{
	char	*result_hex;
	int		len_result;
	int		total_len;

    total_len = 0;
	if (ptr == NULL)
		total_len += ft_put_char('0');
	result_hex = convert_hex(ptr);
	len_result = (int)ft_strlen(result_hex);
	total_len = len_result + ft_put_string("0x");
	ft_putstr_fd(result_hex, 1);
	free(result_hex);
	return (total_len);
}
