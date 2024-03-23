/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2024/03/23 14:29:15 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

/*
	Output a float number with the given precision.
 */
size_t	vfpf_putfloat(int fd, double n, t_ft_printf_flags flags)
{
	size_t		len;
	double		dec;
	int			i;

	len = 0;
	if (n < 0 && (long)n == 0)
		len += vfpf_putchar(fd, '-', flags);
	len += vfpf_putnbr(fd, (long)n, flags);
	if (flags.precision > 0)
	{
		vfpf_putchar(fd, '.', flags);
		len++;
		dec = ft_absf(n - ft_abs((long)n));
		i = 0;
		while (i < flags.precision)
			i++;
		while (i-- > 0)
		{
			dec *= 10;
			len += vfpf_putnbr(fd, (long)dec, flags);
			dec -= (long)dec;
		}
	}
	return (len);
}
