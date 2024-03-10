/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:17 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/04 21:01:17 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstring(char *str)
{
	int	len_str;
	
	len_str = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return ((int)len_str);
}
