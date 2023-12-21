/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 21:58:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

/*
	Output a float number with the given precision.
 */
size_t	ft_def_vfprintf_putfloat(int fd, double n, t_ft_printf_flags flags)
{
	size_t		len;
	double		dec;
	int			i;

	len = 0;
	if (n < 0 && (long)n == 0)
		len += ft_def_vfprintf_putchar(fd, '-', flags);
	len += ft_def_vfprintf_putnbr(fd, (long)n, flags);
	if (flags.precision > 0)
	{
		ft_def_vfprintf_putchar(fd, '.', flags);
		len++;
		dec = ft_absf(n - ft_abs((long)n));
		i = 0;
		while (i < flags.precision)
			i++;
		while (i-- > 0)
		{
			dec *= 10;
			len += ft_def_vfprintf_putnbr(fd, (long)dec, flags);
			dec -= (long)dec;
		}
	}
	return (len);
}
