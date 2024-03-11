/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:02:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/23 00:02:00 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_char(char c);
int	ft_put_string(char *str);
int	ft_put_integer(int nbr);
int	ft_put_unsigned(unsigned int nbr);
// int	ft_putpointer(void *);

#endif
