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

int	ft_put_pointer(void *ptr)
{
	int		len_result;
	char	*result_hex;

	len_result = 0;
	if (ptr == NULL)
		len_result += write(1, "(nil)", 5);
	else
	{
		result_hex = ft_convert_hex(ptr, ' ');
		len_result += write(1, "0x", 2);
		len_result += ft_put_string(result_hex);
		free(result_hex);
	}
	return (len_result);
}
