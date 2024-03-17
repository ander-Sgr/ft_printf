/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:30 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/17 14:12:30 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexadecimal(void *ptr, char flag)
{
	int		len_result;
	char	*result_hex;

	len_result = 0;
	if (ptr == NULL)
		return (0);
	else
	{
		result_hex = ft_convert_hex(ptr, flag);
		if (result_hex != NULL)
		{
			len_result += ft_put_string(result_hex);
			free(result_hex);
		}
	}
	return (len_result);
}
